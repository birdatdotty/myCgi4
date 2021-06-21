#ifndef ACTION_H
#define ACTION_H

#include <list>
#include <string>



class Action {
public:
    enum class Oper {NONE, SUM, DOT};
    Action();
    void set(unsigned char ch);
    Oper action();

private:
    Oper _oper;


    /// rebuild it class:
protected:
    void actionChar();
    void actionSum();
    void actionSpace();
    std::string word;
    std::string tmpWord;

    char ch;
    char chAction = ' ';
    std::list<std::string> strList;

    std::string strAction;


};



#endif // ACTION_H
