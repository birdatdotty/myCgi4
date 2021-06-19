#include "Option.h"

#include <iostream>

Option::Option(std::list<std::string> params) {
    _name = *params.begin();
    params.pop_front();
    this->params = params;
}

void Option::echo(std::string pre) {
    std::cout << pre << _name << ": ";
    for (std::list<std::string>::iterator it = params.begin(); it != params.end(); it++)
        std::cout << pre  << "\"" << *it << "\"";

    std::cout << std::endl;
}

std::string Option::name() const {return _name;}

std::string Option::value() const {return *params.begin();}
