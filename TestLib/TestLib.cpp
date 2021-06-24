#include "TestLib.h"

#include <iostream>
#include <thread>

#include <unistd.h>
#include <cstring>
#include <AOption.h>

using namespace std;

extern "C" void init(ImportLib** ret) {
    *ret = new TestLib();
}

TestLib::TestLib()
{}

void TestLib::configure(std::list<AOption *> options) {
    std::cout << "void TestLib::configure(std::list<AOption *> options)" << std::endl;
    for (std::list<AOption*>::iterator it = options.begin(); it != options.end(); it++)
        std::cout << "configure\t" << (*it)->name() << ": " << (*it)->value() << std::endl;
}

bool TestLib::run()
{
    std::cout << "bool TestLib::run()" << std::endl;
    return false;
}

void TestLib::print() {
    std::cout << "void TestLib::print()" << std::endl;
}

void TestLib::testModule()
{
    std::cout << "void TestLib::testModule()" << std::endl;
}
