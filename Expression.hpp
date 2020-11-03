#pragma once
#include "Global.hpp"
class Type;

class Expression
{
public:
    Expression():type(nullptr){};
    virtual ~Expression(){};
    Type * getType(){return type;};
    void setType(Type *t){type = t;};
private:
    Type * type;
};
class RegExpr : public Expression
{
public:
    RegExpr() : Expression(), reg(){};
    void setRegister(const std::shared_ptr<std::string>& r){reg = r;};
    void releaseRegister(){reg.reset();};
    std::shared_ptr<std::string> getRegister(){return reg;};
private:
    std::shared_ptr<std::string> reg;
};

class oneValxpr : public RegExpr 
{
public:
    oneValxpr() : RegExpr(), offset(0){};
    void setOffset(int o){offset = o;};
    int getOffset(){return offset;};
private:
    int offset;
};
