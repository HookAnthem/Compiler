#pragma once
#include "Global.hpp"

class Variable
{
public:
    Variable() : type(nullptr), offset(0), reg(){};
    Type * type;
    int offset;
    std::string reg;
};
class Value
{
public:
    Value() : type(nullptr), value(0){};
    Type * type;
    int value;
};

class Constant : public Value {};
