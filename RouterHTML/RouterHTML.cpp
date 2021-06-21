#include "RouterHTML.h"

#include <iostream>

extern "C" void init(ImportLib** ret) {
//    std::cout << "extern \"C\" void init(ImportLib** ret)" << std::endl;
    *ret = new RouterHTML();
}

RouterHTML::RouterHTML()
{
}

void RouterHTML::testModule()
{
    std::cout << "void RouterHTML::testModule()" << std::endl;
}

void RouterHTML::configure(std::list<AOption *> options)
{

}
