#include "Parser.h"
#include <iostream>

void Parser::print() {
    for (std::list<std::string>::iterator it = strList.begin(); it != strList.end(); it++)
        std::cout << *it << std::endl;
}

bool Parser::setAction() {
    chAction = ch;
    return true;
}

void Parser::charSlash() {
    if (actionExist) {
        actionExist = false;
        if (chAction == ' ') actionSpace();
        else if (chAction == '+') actionSum();
    }
    actionChar();
}

void Parser::charSpace() {
    if (ch != ' ')
        chAction = ' ';

    actionExist = true;
}
