#pragma once
#include "Global.hpp"

class Expression;
class Type {
  public:
    std::string memLoc;
    int size;
    Type * base = this;
    virtual Type * baseType();
};

