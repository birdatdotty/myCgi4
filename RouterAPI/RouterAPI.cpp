#include "RouterAPI.h"

#include <iostream>

extern "C" void init(ImportLib** ret) {
//    std::cout << "extern \"C\" void init(ImportLib** ret)" << std::endl;
    *ret = new RouterAPI();
}

RouterAPI::RouterAPI()
{
}

void RouterAPI::testModule()
{
    std::cout << "void RouterAPI::testModule()" << std::endl;
}

void RouterAPI::configure(std::list<AOption *> options)
{

}
