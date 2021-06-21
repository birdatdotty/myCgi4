#ifndef SERVICE_H
#define SERVICE_H

#include "ImportLib.h"

class RouterAPI: public ImportLib
{
public:
    RouterAPI();

    virtual void testModule();
    virtual void configure(std::list<AOption*> options);
    virtual std::string typeName() {return "Router";}
};

#endif // SERVICE_H
