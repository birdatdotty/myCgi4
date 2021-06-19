#include "SimpleHTTPServer.h"

#include <iostream>
#include <thread>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <unistd.h>
#include <cstring>

using namespace std;

extern "C" void init(ImportLib** ret) {
    std::cout << "extern \"C\" void init(ImportLib** ret)" << "--" << std::endl;
    ImportLib* ss = new SimpleHTTPServer();
    ss->testModule();
    std::cout << "extern \"C\" void init(ImportLib** ret)" << "--" << std::endl;
    *ret = new SimpleHTTPServer();
}

SimpleHTTPServer::SimpleHTTPServer(/*int port*/)
//    : port(port)
{}

void SimpleHTTPServer::start(Bus *bus) {
    status = true;
    cout << "SimpleServer started: " << port << endl;

    int listener;
    struct sockaddr_in addr;
    char buf[1024];
    int bytes_read;

    listener = socket(AF_INET, SOCK_STREAM, 0);
    if(listener < 0)
    {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(2);
    }

    listen(listener, 1);

    while(status)
    {
        sock = accept(listener, NULL, NULL);
        if(sock < 0)
        {
            perror("accept");
            exit(3);
        }

        while(status)
        {
            bytes_read = recv(sock, buf, 1024, 0);
            if(bytes_read <= 0) break;

            std::string data = bus->data();
            send(sock, data.c_str(), strlen(data.c_str()), 0);
//            send(sock, buf, bytes_read, 0);
        }

        close(sock);
    }

}

bool SimpleHTTPServer::shutdown()
{
    status = false;
//    close(sock);

    return true;
}

void SimpleHTTPServer::configure(std::list<AOption *> options) {}

void SimpleHTTPServer::testModule()
{
    std::cout << "void SimpleHTTPServer::testModule()" << std::endl;
}
