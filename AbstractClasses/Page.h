#ifndef PAGE_H
#define PAGE_H

#include <string>

class Page {
public:
    virtual ~Page() {};
    virtual std::string out() = 0;
};

#endif // PAGE_H
