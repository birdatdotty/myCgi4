#ifndef OPTION_H
#define OPTION_H

#include <list>
#include <string>

#include "AOption.h"

class Option: public AOption {
public:
    Option(std::list<std::string> params);
    std::string name() const;
    std::string value() const;

private:
    std::string _name;
    std::list<std::string> params;

    // for debug:
public:
    void echo(std::string pre);
};

#endif // OPTION_H
