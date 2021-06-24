#ifndef REQUEST_H
#define REQUEST_H

#include "Page.h"

#include <string>

class Request
{
public:
    explicit Request() {}
    virtual std::string url(/*const Router *router*/) const = 0;
    virtual std::string method() const = 0;
//    virtual std::string uri() const = 0;
//    virtual std::string getData() const = 0;
    virtual std::string contentType() const = 0;
    virtual std::string content() const = 0;
    virtual int contentLength() const = 0;

    virtual Page* page() = 0;
};


#endif // REQUEST_H
