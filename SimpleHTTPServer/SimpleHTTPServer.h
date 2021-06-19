#ifndef SIMPLEHTTPSERVER_H
#define SIMPLEHTTPSERVER_H

// https://code-live.ru/post/cpp-http-server-over-sockets/
// https://stackoverflow.com/questions/9102453/sockaddr-in-undeclared-identifier
// https://rsdn.org/article/unix/sockets.xml
#include "Server.h"
#include "Bus.h"

#include "ImportLib.h"

class SimpleHTTPServer
        : public Server,
          public ImportLib
{
public:
    SimpleHTTPServer(/*int port*/);
    virtual void testModule();
    virtual void start(Bus* bus);
    virtual bool shutdown();
    virtual void configure(std::list<AOption*> options);

private:
    int sock;
    int port;
    bool status;
};

#endif // SIMPLEHTTPSERVER_H
