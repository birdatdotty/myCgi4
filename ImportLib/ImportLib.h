#ifndef IMPORTLIB_H
#define IMPORTLIB_H

#include <string>
#include <dlfcn.h>
#include <map>
#include <list>

//#include "AOption.h"
class AOption;


class ImportLib;
typedef void(*fnInit)(ImportLib**);

/// add like it in your lib:
/*
extern "C" void init(ImportLib** ret) {
    *ret = new Module1();
}
*/


class ImportLib
{
public:
    virtual void testModule() = 0;
    virtual void configure(std::list<AOption*> options) = 0;
    virtual void addChildren(ImportLib* children);
    virtual std::string typeName() {return "";}
    virtual bool run();

private:
    std::list<ImportLib*> childrens;
};

class Import {
public:
    ImportLib* build(std::string name);
protected:
    bool load(std::string name);


    std::map <std::string,fnInit> constructors;
private:
    fnInit import(std::string lib);
};


#endif // IMPORTLIB_H
