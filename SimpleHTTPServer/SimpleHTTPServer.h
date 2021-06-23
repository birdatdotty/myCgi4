#ifndef SIMPLEHTTPSERVER_H
#define SIMPLEHTTPSERVER_H

// https://code-live.ru/post/cpp-http-server-over-sockets/
// https://stackoverflow.com/questions/9102453/sockaddr-in-undeclared-identifier
// https://rsdn.org/article/unix/sockets.xml
#include "Server.h"
#include "Bus.h"
#include "ImportLib.h"

#include <netinet/in.h>



class SimpleHTTPServer
        :
          public ImportLib,
        public Server
{
public:
    SimpleHTTPServer();
    virtual void start(Bus* bus);
    virtual bool shutdownServer();
    virtual void stop();
    virtual bool run();


    virtual void testModule();
    virtual void configure(std::list<AOption*> options);
    virtual std::string typeName() {return "Server";}


private:
    void setPort();
    Bus* bus;
    int sock;
    int listener;
    int port;
    bool status;
    struct sockaddr_in addr;
};


#endif // SIMPLEHTTPSERVER_H
