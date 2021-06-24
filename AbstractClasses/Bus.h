#ifndef BUS_H
#define BUS_H

#include <string>

class Request;
class Page;

class Bus
{
public:
    virtual Page* data(Request* req) = 0;
};

#endif // BUS_H
