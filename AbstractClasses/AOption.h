#ifndef AOPTION_H
#define AOPTION_H

#include <string>

class AOption {
public:
    virtual std::string name() const = 0;
    virtual std::string value() const = 0;
};

#endif // AOPTION_H
