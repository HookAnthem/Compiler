#pragma once
#include "Global.hpp"

class fold : public Expression
{
public:
    fold() : Expression(), value(0){};
    int getValue(){return value;};
    void setValue(int v){value = v;};
private:
    int value;
};
