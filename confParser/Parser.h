#ifndef PARSER_H
#define PARSER_H

#include "Action.h"

#include <map>

class Object;
class Command;

class Parser: public Action
{
public:
//    bool parse(QString str);
    void print();

//protected:
//    std::map<std::string,Object*> ids;
//    std::list<Command*> commands;

private:
    bool actionExist = false;

    bool setAction();
    void charSlash ();
    void charSpace();
};

#endif // PARSER_H
