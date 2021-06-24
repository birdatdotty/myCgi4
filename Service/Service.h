#ifndef SERVICE_H
#define SERVICE_H

#include "ImportLib.h"
#include "Server.h"

#include <list>
#include <thread>

class Service:
        public ImportLib,
        public Bus
{
public:
    Service();

    virtual void testModule();
    virtual void configure(std::list<AOption*> options);
    virtual std::string typeName() {return "Service";}

    virtual void addChildren(ImportLib* children);
    virtual bool run();
    virtual Page* data(Request* req);


private:
    std::list<Server*> servers;
    std::list<std::thread> threads;
    void startServer(Server* server);

    ImportLib* tl;
};

#endif // SERVICE_H
