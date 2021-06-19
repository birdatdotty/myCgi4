#ifndef SERVICE_H
#define SERVICE_H

#include "ImportLib.h"

class RouterAPI: public ImportLib
{
public:
    RouterAPI();

    virtual void testModule();
    virtual void configure(std::list<AOption*> options);
};

#endif // SERVICE_H
