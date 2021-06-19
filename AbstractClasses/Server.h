#ifndef SERVER_H
#define SERVER_H

#include "Bus.h"

class Server {
public:
    virtual void start(Bus* bus) = 0;
    virtual bool shutdown() = 0;
};

#endif // SERVER_H
