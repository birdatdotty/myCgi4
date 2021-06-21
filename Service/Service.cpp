#include "Service.h"

#include <iostream>
#include <AOption.h>

extern "C" void init(ImportLib** ret) {
//    std::cout << "extern \"C\" void init(ImportLib** ret)" << std::endl;
    *ret = new Service();
}

Service::Service()
{
}

void Service::testModule()
{
    std::cout << "void Service::testModule()" << std::endl;
}

void Service::configure(std::list<AOption *> options)
{
    std::cout << "void Service::configure(std::list<AOption *> options)" << std::endl;
    for (std::list<AOption *>::iterator it = options.begin(); it != options.end(); it++)
    {
        std::cout << " configure: " << (*it)->name() << " -> " << (*it)->value()<< std::endl;
    }
}

void Service::addChildren(ImportLib *children) {
    ImportLib::addChildren(children);
    Server* item;

    std::cout << __LINE__ << ": " << children->typeName() << ": " << children << std::endl;
    if (children->typeName() == "Server")
    {
        item = dynamic_cast<Server*>(children);
        std::cout << __LINE__ << ": " << typeName() << " [" << this << "] line:" << std::endl;
        servers.push_back(item);
    }

    std::cout << __LINE__ << " <" << typeName() << "> " << ": " << this << " ->" << servers.size() << std::endl;
}

bool Service::run() {
    std::cout << __LINE__ << ">>" << typeName() << "[" << this << "] servers.size():" << servers.size() << std::endl;

    return true;
}
