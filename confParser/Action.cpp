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
