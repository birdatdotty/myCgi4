#include "Action.h"


Action::Action():_oper(Oper::NONE) {}

void Action::set(unsigned char ch) {
    if (ch == '+') _oper = Oper::SUM;
    else if (ch == '.') _oper = Oper::DOT;
    else _oper = Oper::NONE;
}

Action::Oper Action::action() {
    Oper ret;
    ret = _oper;
    _oper = Oper::NONE;
    return ret;
}


/// rebuild it class:
inline void Action::actionChar()
{
    word += ch;
}

inline void Action::actionSum()
{
    tmpWord += word;
    word.clear();
    chAction = ' ';
}

inline void Action::actionSpace()
{
    tmpWord += word;
    word.clear();
    strList.push_back(tmpWord);
    tmpWord.clear();
}
