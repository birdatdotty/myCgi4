#ifndef ROUTERHTML_H
#define ROUTERHTML_H

#include "ImportLib.h"

class RouterHTML: public ImportLib
{
public:
    RouterHTML();

    virtual void testModule();
    virtual void configure(std::list<AOption*> options);
};

#endif // ROUTERHTML_H
