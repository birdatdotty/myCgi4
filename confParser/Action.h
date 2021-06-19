#ifndef ACTION_H
#define ACTION_H


class Action {
protected:
    enum class Oper {NONE, SUM, DOT};
    Action();
    void set(unsigned char ch);
    Oper action();

private:
    Oper _oper;
};

#endif // ACTION_H
