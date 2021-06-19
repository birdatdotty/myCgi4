#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <list>

class Command
{
public:
    Command(std::list<std::string> params);
    void echo(std::string pre);
    std::string data(std::string cmdName);
private:
    std::string cmd;
    std::string option;
};

#endif // COMMAND_H
