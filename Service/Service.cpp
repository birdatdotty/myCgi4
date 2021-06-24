#include "Service.h"

#include <iostream>
#include <AOption.h>
#include "Request.h"

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
    if (children->typeName() == "TestLib")
    {
        tl = dynamic_cast<ImportLib*>(children);
    }
    std::cout << __LINE__ << " <" << typeName() << "> " << ": " << this << " ->" << servers.size() << std::endl;
}

bool Service::run() {
    std::cout << __LINE__ << ">>" << typeName() << "[" << this << "] servers.size():" << servers.size() << std::endl;

    for (std::list<Server*>::iterator it = servers.begin(); it != servers.end(); it++) {
        std::cout << "(*it)->typeName(): " << (*it)->typeName() << std::endl;
        startServer(*it);
    }

    for (std::list<std::thread>::iterator it = threads.begin(); it != threads.end(); it++) {
        (*it).join();
    }

    return true;
}

Page* Service::data(Request *req) {
    std::string url = req->url();
//    if (url.size() > 0)
//    req->page();
//    return "HTTP/1.1 200 OK\nContent-Type: application/json; charset=UTF-8\nContent-Length: 9\n\nsasaddsB\n";
    return req->page();
}

void Service::startServer(Server *server) {
    threads.push_back(std::thread(&Server::start,server, this));
}
