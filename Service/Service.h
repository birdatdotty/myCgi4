#ifndef SERVICE_H
#define SERVICE_H

#include "ImportLib.h"
#include "Server.h"

#include <list>

class Service: public ImportLib
{
public:
    Service();

    virtual void testModule();
    virtual void configure(std::list<AOption*> options);
    virtual std::string typeName() {return "Service";}

    virtual void addChildren(ImportLib* children);
    virtual bool run();


private:
    std::list<Server*> servers;
};

#endif // SERVICE_H
