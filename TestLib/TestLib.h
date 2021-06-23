#ifndef TESTLIB_H
#define TESTLIB_H

#include "ImportLib.h"

class TestLib
        : public ImportLib
{
public:
    TestLib();
    virtual void testModule();
    virtual void configure(std::list<AOption*> options);

    virtual std::string typeName() {return "TestLib";}
    virtual bool run();

    void print();
};

#endif // TESTLIB_H
