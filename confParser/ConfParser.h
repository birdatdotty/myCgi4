#ifndef CONFPARSER_H
#define CONFPARSER_H

#include <list>
#include <string>
#include <map>

#include "Option.h"
#include "Object.h"
#include "Action.h"
#include "Command.h"

#include "ImportLib.h"

class ConfParser
        : protected Action,
          public Import

{
public:
    ConfParser();
    bool readFile(std::string filePath);
    bool parse();
bool importAll();
bool buildTree();
    enum class Type {STRING, DIGIT, NAME, DEFAULT, COMMAND, OPTION, OBJECT};

private:
    std::string ctx;


    // for parse:
    std::map<std::string,Object*> ids;
    std::list<std::string> lexemes;
    std::list<Command*> commands;
//    Action oper;
    bool finishWord();
    bool colon;
    unsigned char ch;
    Type type;
    std::string word;
    Object* curObject;
    Object* root;

// for debug:
public:
    void echo();
};

#endif // CONFPARSER_H
