#include <iostream>
#include "ConfParser.h"

using namespace std;

int main()
{
//    const char* root4Qml = "/home/bird/devel/myCgi2/root4.qml";
//    cout << "Hello World!" << endl;
//    return 0;
    ConfParser *confParser = new ConfParser();
    std::string conf = CONF;//"/home/bird/devel/myCgi2/root4.qml";
    std::string buf;

    confParser->readFile(conf);
    confParser->parse();

    confParser->echo();

    cout << CONF <<endl;
    confParser->importAll();
    confParser->buildTree();

    return EXIT_SUCCESS;
}
