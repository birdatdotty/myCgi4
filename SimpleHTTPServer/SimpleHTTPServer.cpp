#include "SimpleHTTPServer.h"

#include <thread>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <unistd.h>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

#include <AOption.h>
#include <iostream>


extern "C" void init(ImportLib** ret) {
    ImportLib* ss = new SimpleHTTPServer();
    *ret = new SimpleHTTPServer();
}

using namespace std;

SimpleHTTPServer::SimpleHTTPServer()
    : bus(bus), port(9999)
{
}

void SimpleHTTPServer::start(Bus *bus) {
    this->bus = bus;
    std::string answ;
    status = true;

    char buf[1024];
    int bytes_read;

    listener = socket(AF_INET, SOCK_STREAM, 0);
    const int trueFlag = 1;
    if (setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &trueFlag, sizeof(int)) < 0)
    perror("Failure");

    if(listener < 0)
    {
        perror("socket");
        exit(1);
    }

    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(2);
    }

    listen(listener, 1);

    while(status)
    {
        sock = accept(listener, NULL, NULL);
        if(sock < 0 && status == true)
        {
            perror("accept");
            exit(3);
        }

        while(status)
        {
            bytes_read = recv(sock, buf, 1024, 0);
            if(bytes_read <= 0) break;

            answ = bus->data();
            const char* data = answ.c_str();
            send(sock, data, strlen(data), 0);
        }

        close(sock);
    }

}

bool SimpleHTTPServer::shutdownServer()
{
    status = false;
    shutdown(listener, SHUT_RD);
    usleep(100);

    return true;
}

void SimpleHTTPServer::stop()
{
    shutdownServer();
}

bool SimpleHTTPServer::run()
{
    std::cout << "bool SimpleHTTPServer::run()" << std::endl;
    return false;
}

void SimpleHTTPServer::testModule() {
    std::cout << "void SimpleHTTPServer::testModule()" << std::endl;
}

void SimpleHTTPServer::configure(std::list<AOption *> options) {
    std::cout << "port: " << port << std::endl;
    for (std::list<AOption *>::iterator it = options.begin(); it != options.end(); it++) {
        if ((*it)->name() == "port") {
            port = std::stoi((*it)->value());
            setPort();
        }
    }
    std::cout << "port: " << port << std::endl;
}

void SimpleHTTPServer::setPort()
{
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
}
