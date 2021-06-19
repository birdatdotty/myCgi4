#include "Command.h"

#include <iostream>
using namespace std;

Command::Command(std::list<std::string> params)
{
    cmd = *params.begin();
    params.pop_front();
    option = *params.begin();
}

void Command::echo(std::string pre) {
//    cout << "Option:" << cmd << endl;
//    cout << "params:" << option << endl;
    cout << pre << cmd << " [" << option << "]" << endl;
}

string Command::data(std::string cmdName)
{
    if (cmdName == cmd)
        return option;
    else
        return "";
}
