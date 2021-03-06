#include "Object.h"

#include <ImportLib.h>
#include <iostream>
#include "ConfParser.h"


Object::Object(Object *parent, std::string name)
    : _parent(parent), _name(name)
{}

void Object::addOption(Option *option) {
    options.push_back(option);
    if (option->name() == "id")
        _id = option->value();
}

 void Object::addChildren(Object *object) {
    childrens.push_back(object);
}

std::string Object::value(std::string key) {
    for (std::list<AOption*>::iterator it = options.begin(); it != options.end(); it++) {
        if ((*it)->name() == key)
            return (*it)->value();
    }

    return "";
}

Object *Object::parent() const {
    return _parent;
}

std::string Object::id() const {
    return _id;
}

std::string Object::name() const {
    return _name;
}

bool Object::buildTree(ImportLib *parentLib)
{
//    if (_name == "SimpeHTTPServer")
//        return false;

    self = confParser->build(_name);
    self->configure(options);
    if (parentLib)
        parentLib->addChildren(self);

    for (std::list<Object*>::iterator it = childrens.begin(); it != childrens.end(); it++)
    {
        (*it)->buildTree(self);
    }

    return true;
}

//bool Object::build() {
//    ImportLib* rootLib = confParser->buildTree()
//}

void Object::setConfParser(ConfParser *newConfParser) {
    confParser = newConfParser;
}

// for debug:
void Object::echo(std::string pre)
{
    if (_parent != nullptr)
        std::cout << pre << _name << ": " << parent()->_name << std::endl;
    else
        std::cout << "\n" << pre << _name << ": " << "nullptr" << std::endl;

//    if (options.size() > 0)
//        for (std::list<AOption*>::iterator it = options.begin(); it != options.end(); it++)
//            (*it)->echo("  " + pre);

    if (childrens.size() > 0) {
        for (std::list<Object*>::iterator it = childrens.begin(); it != childrens.end(); it++)
            (*it)->echo("  " + pre);
    }
}
