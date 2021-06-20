#include <iostream>
#include "ConfParser.h"

using namespace std;

int main()
{

    ConfParser *confParser = new ConfParser();
    std::string conf = CONF;
    std::string buf;

    confParser->readFile(conf);
    confParser->parse();

    confParser->echo();

    cout << CONF <<endl;
    confParser->importAll();
    confParser->buildTree();

    return EXIT_SUCCESS;
}
