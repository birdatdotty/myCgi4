#ifndef PARSERDATA_H
#define PARSERDATA_H

#include <list>
#include <map>
#include <string>

class Object;
class Command;

class ParserData {
protected:
    std::map<std::string,Object*> ids;
    std::list<Command*> commands;
};

#endif // PARSERDATA_H
