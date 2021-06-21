#include <iostream>
#include "ConfParser.h"

#include "Server.h"
#include "Service.h"

using namespace std;

int main()
{
    ConfParser *confParser = new ConfParser();
    std::string conf = CONF;
    std::string buf;

    confParser->readFile(conf);
    confParser->parse();

    confParser->importAll();
    confParser->buildTree();

    ImportLib *root = confParser->getRootLib();
    std::cout << __FILE__ << ": " << root->typeName() << std::endl;
    root->run();

//    Service* service = dynamic_cast<Service*>(root);
//    std::cout << "service:" << service->typeName() << std::endl;

    return EXIT_SUCCESS;
}
