#include "ConfParser.h"

#include <fstream>
#include <iostream>
#include <string>

ConfParser::ConfParser() {}

bool ConfParser::readFile(std::string filePath) {
    std::ifstream file (filePath, std::ios::in|std::ios::binary|std::ios::ate);
    if (file.is_open())
    {
        file.seekg(0, std::ios::end);
        ctx.reserve(file.tellg());
        file.seekg(0, std::ios::beg);

        ctx.assign((std::istreambuf_iterator<char>(file)),
                   std::istreambuf_iterator<char>());

//        std::cout << ctx << std::endl;
        return true;
    }

    return false;
}

bool ConfParser::parse()
{
    colon = false;

    for (size_t i = 0; i < ctx.size(); i++) {
        ch = ctx[i];

        if (ch == '"') {
            colon = !colon;
        }
        // utf-8
        else if (ch > 128) {
            // https://ru.wikipedia.org/wiki/UTF-8
            // 128 - 10000000
            // 192 - 11000000
            // 224 - 11100000
            // 240 - 11110000
            if (ch < 224) {
                word += ch;
                word += ctx[i+1];
                i++;
            }
            else if (ch < 240 ) {
                word += ch;
                word += ctx[i+1];
                word += ctx[i+2];
                i += 2;
            }
            else {
                word += ch;
                word += ctx[i+1];
                word += ctx[i+2];
                word += ctx[i+3];
                i += 3;
            }
        }
        else if (colon)
            word += ch;
        else if (ch >= '0' && ch <= '9')
            word += ch;
        else if (ch >= 'A' && ch <= 'Z')
            word += ch;
        else if (ch >= 'a' && ch <= 'z')
            word += ch;
        else if (ch == '_') {
            word += ch;
        }
//        else if (ch == '.') {
//            word += ch;
//        }

        else
            if (finishWord()) {
                return true;
            }
    }

    return false;
}

bool ConfParser::importAll()
{
    std::string importModuleName;
    for (std::list<Command*>::iterator it = commands.begin(); it != commands.end(); it++) {
        importModuleName = (*it)->data("import");
        if (importModuleName != "") {
            load(importModuleName);
            ImportLib* testLib = build(importModuleName);

            testLib->testModule();
        }
    }

    return false;
}

bool ConfParser::buildTree()
{
    std::cout << __LINE__ << ": " << root->name() << std::endl;
//    importRoot = build(root->name());
//    root->buildTree(importRoot);
    root->buildTree(nullptr);
    importRoot = root->self;

    std::cout << "importRoot(root->name()): " << __LINE__ << root->name() << std::endl;

    return true;
}

ImportLib *ConfParser::getRootLib() {return importRoot;}

bool ConfParser::finishWord()
{
    if (word.size() > 0) {
        Action::Oper _action = action();
        if (_action == Action::Oper::SUM) {
            std::string last = strList.back();
            strList.pop_back();

            strList.push_back(last + word);
        }
        else if (_action == Action::Oper::DOT) {
            std::string last = strList.back();
            strList.pop_back();

            if (ids[last]) {
                std::string value = ids[last]->value(word);
                strList.push_back(value);
            }
        }
        else
            strList.push_back(word);

        word.clear();
        if (!colon && ch == '+') { set(ch); }
        else if (!colon && ch == '.') { set(ch); }
    }
    if (ch == ':')
        type = Type::OPTION;
    else if (ch == '{') {
        type = Type::OBJECT;
        if (curObject)
        if (curObject->id().size() > 0)
            ids[curObject->id()] = curObject;
    }
    else if (ch == '}') {
        if (curObject) {
            curObject = curObject->parent();
            if (!curObject) {
               return true;
            }
        }
    }
    else if (ch == '\n' || ch == ';') {
        if (type == Type::OPTION) {
            Option* option = new Option(strList);
            curObject->addOption(option);
        }
        else if (type == Type::OBJECT) {
            std::cout << "111111111111111111111111" << std::endl;
            std::string name = *strList.rbegin();
            Object* object = new Object(curObject, name);
            object->setConfParser(this);
            if (curObject)
                curObject->addChildren(object);
            else {
                root = curObject = object;
            }

            curObject = object;
        }
        else {
            if (strList.size() > 1) {
                Command* command = new Command(strList);
                if (!curObject)
                    commands.push_back(command);
            }
        }
        strList.clear();
        type = Type::COMMAND;
    }
    if (!colon && ch == '+') { set(ch); }
    else if (!colon && ch == '.') { set(ch); }

    return false;
}

// for debug:
void ConfParser::echo()
{
    for (std::list<Command*>::iterator it = commands.begin(); it != commands.end(); it++)
        (*it)->echo("");
    root->echo("");
}
