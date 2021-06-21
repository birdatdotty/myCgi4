#ifndef ROUTERHTML_H
#define ROUTERHTML_H

#include "ImportLib.h"

class RouterHTML: public ImportLib
{
public:
    RouterHTML();

    virtual void testModule();
    virtual void configure(std::list<AOption*> options);
    virtual std::string typeName() {return "Router";}
};

#endif // ROUTERHTML_H
