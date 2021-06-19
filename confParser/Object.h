#ifndef OBJECT_H
#define OBJECT_H

#include "Option.h"
class ConfParser;
class ImportLib;

class Object {
public:
    Object(Object* parent, std::string name = "");
    void addOption(Option* option);
    void addChildren(Object* object);
    std::string value(std::string key);

    Object* parent() const;
    std::string id() const;
    std::string name() const;
    bool buildTree( ImportLib* parent);

    void setConfParser(ConfParser* newConfParser);

private:
    Object* _parent;
    std::string _name;
    std::string _id;
    std::list<Object*> childrens;
    std::list<AOption*> options;
    std::list<Object*> objects;
    ConfParser* confParser;

    // for debug:
public:
    void echo(std::string pre);
};

#endif // OBJECT_H
