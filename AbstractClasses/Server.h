#ifndef SERVER_H
#define SERVER_H

#include "Bus.h"

class Server {
public:
    virtual void start(Bus* bus) = 0;
    virtual bool shutdownServer() = 0;
    virtual std::string typeName() {return "Server";}
};

#endif // SERVER_H
