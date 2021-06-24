#include "RequestSimpleHTTPServer.h"

#include <iostream>

#include <fstream>
using std::ofstream;

void wf(std::string ctx) {
    ofstream outdata; // outdata is like cin
    outdata.open("/tmp/1111.buf");
    outdata << ctx;
    outdata.close();
}
void wf2(std::string ctx) {
    ofstream outdata; // outdata is like cin
    outdata.open("/tmp/1111_2.buf");
    outdata << ctx;
    outdata.close();
}

RequestSimpleHTTPServer::RequestSimpleHTTPServer(std::string ctx)
    : ctx(ctx),
      _contentLength(0)
{
    wf(ctx);
    wf2("rn\r\n");
    int i = 0;
    i = parserHeaderFirstLine(i);
    i = parserHeader(i);
    i++;

    _content = ctx.substr(i);
    _contentLength = _content.size();
}

Page *RequestSimpleHTTPServer::page() {
    if (_page)
        delete _page;

    _page = new RequestSimpleHTTPServerPage(this);
    return _page;
}

void RequestSimpleHTTPServer::options()
{
    for (auto it = _options.begin(); it != _options.end(); it++)
        (*it)->print();
}

int RequestSimpleHTTPServer::parserHeaderFirstLine(int i) {
    for (; ctx.at(i) != '\n'; i++) {
        char ch = ctx.at(i);
        if (ch == '\n') {
            if (word.size() > 0)
                lexems.push_back(word);
        }
        if (ch > ' ')
            word += ch;
        else {
            if (word.size() > 0)
                lexems.push_back(word);

            word.clear();
        }
    }

    if (word.size() > 0)
        lexems.push_back(word);

    endFirstLine();
    word.clear();

    return i + 1;
}

int RequestSimpleHTTPServer::parserHeader(int i) {
    std::cout << "-------------" << std::endl;
    std::cout << "ctx: " << ctx << std::endl;
    std::cout << "-------------" << std::endl;
    std::cout << "ctx.size()" << ctx.size() << std::endl;
    for (; ctx.at(i) != '\0'; i++) {
        char ch = ctx.at(i);
        std::cout << "ch: " << ch << std::endl;
        if (ch == '\n' || ch == '\r') {
            if (word.size() > 0)
                lexems.push_back(word);
            if (lexems.size() == 0)
                break;

            endLine();
            word.clear();


        }
        if (ch > ' ')
            word += ch;
        else {
            if (word.size() > 0)
                lexems.push_back(word);

            word.clear();
        }
    }
    return i;
}

void RequestSimpleHTTPServer::endFirstLine() {
    if (lexems.size() > 2) {
        _method = *lexems.begin(); lexems.pop_front();
        _url = *lexems.begin(); lexems.pop_front();
        _protocol = *lexems.begin(); lexems.pop_front();
    }

    lexems.clear();
}

void RequestSimpleHTTPServer::endLine() {
    std::list<std::string>::iterator it = lexems.begin();
    RequestOptions *tmpOption = new RequestOptions(*it);
    it++;
    for (; it != lexems.end(); it++) {
        tmpOption->add(*it);
    }
    _options.push_back(tmpOption);
    bool s;
    s = tmpOption->is("Accept");
    s = tmpOption->is("User-Agent");
    s = tmpOption->is("Host");
    if (tmpOption->is("Accept"))
        _accept = tmpOption->value();
    else if (tmpOption->is("User-Agent"))
        _userAgent = tmpOption->value();
    else if (tmpOption->is("Host")) {
        std::cout << tmpOption << tmpOption->value() << std::endl;
        _host = tmpOption->value();
    }

    lexems.clear();
}

void RequestOptions::print() const
{
    std::cout << "  " << _name << " >> ";

    //        for (auto it = options.begin(); it != options.end(); it++)
    //        for(std::list<std::string>::iterator it = options.begin(); it != options.end(); it++)
    for(auto it = options.begin(); it != options.end(); it++)
        std::cout << " [" << *it << "] ";

    std::cout << std::endl;

}
