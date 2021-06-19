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
    std::cout << "_name: " << _name << std::endl;
//    ImportLib* self = confParser->
    if (_name == "SimpeHTTPServer")
        return false;
    ImportLib* self = confParser->build(_name);
    self->configure(options);
    parentLib->addChildren(self);

    for (std::list<Object*>::iterator it = childrens.begin(); it != childrens.end(); it++)
    {
        (*it)->buildTree(self);
//        if (!(*it)->buildTree(self))
//            return false;
    }
    std::cout << "_name: " << _name << std::endl;
    std::cout << "self: " << self <<std::endl;
    std::cout << "_name: " << _name << std::endl;
    self->testModule();

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
