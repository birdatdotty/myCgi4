#ifndef REQUESTSIMPLEHTTPSERVER_H
#define REQUESTSIMPLEHTTPSERVER_H

#include <string>
#include <list>

#include "Page.h"
#include "Request.h"

class RequestSimpleHTTPServer;


class RequestOptions {
public:
    RequestOptions(std::string name) {
        _name = name.substr(0, name.size() - 1);
    }
    void add(std::string option) {options.push_back(option);}
    bool is(std::string name) {return !name.compare(_name);}
    std::string value() { return *options.begin();}

    void print() const;

private:
    std::string _name;
    std::list<std::string> options;
};

class RequestSimpleHTTPServer: public Request
{
public:
    RequestSimpleHTTPServer(std::string ctx);

    virtual std::string url() const {return _url;}
    virtual std::string method() const {return _method;}
    virtual std::string contentType() const { return _contentType;}
    virtual std::string content() const { return _content; }
    virtual std::string protocol() const { return _protocol; }
    virtual int contentLength() const { return _contentLength;}
    virtual std::string host() const { return _host;}
    virtual std::string accept() const { return _accept;}
    virtual std::string userAgent() const { return _userAgent;}

    virtual Page* page();;
    void options();

private:
    RequestSimpleHTTPServer* req;
    std::string _url;
    std::string _method;
    std::string _contentType;
    std::string _content;
    std::string _protocol;
    std::string ctx;
    int _contentLength;

    Page* _page;

    int parserHeaderFirstLine(int i = 0);
    int parserHeader(int i = 0);

    unsigned char ch;
    std::string word;
    std::list<std::string> lexems;
    void endFirstLine();
    void endLine();
    std::list<RequestOptions*> _options;
    std::string _userAgent;
    std::string _accept;
    std::string _host;
};

class RequestSimpleHTTPServerPage
        : public Page
{
public:
    RequestSimpleHTTPServerPage(RequestSimpleHTTPServer* req): req(req) {}
    virtual ~RequestSimpleHTTPServerPage() {}
    virtual std::string out() {
//        return "virtual std::string out()";
        std::string data = "{\"url\":\"";
        data += req->url();
        data += "\"}";
        std::string header = "HTTP/1.1 200 OK\nContent-Type: application/json; charset=UTF-8\nContent-Length: ";

        header += std::to_string(data.size()) + "\n\n" + data;

        return header;
    }
private:
    RequestSimpleHTTPServer *req;
};


#endif // REQUESTSIMPLEHTTPSERVER_H
