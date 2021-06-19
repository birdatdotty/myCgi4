#ifndef SERVICE_H
#define SERVICE_H

#include "ImportLib.h"

class Service: public ImportLib
{
public:
    Service();

    virtual void testModule();
    virtual void configure(std::list<AOption*> options);
};

#endif // SERVICE_H
