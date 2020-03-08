#include "Type.hpp"

Type* Type::baseType()
{
    return base; 
}
SimpleType::SimpleType()
{
    size = 4;
}
int RecordType::offset(std::string value)
{
    return this->offsetTable.at(value);
}
Type * RecordType::lookup(std::string value)
{
    return this->typeTable.at(value);
}
RecordType::RecordType(std::vector<std::string> mem, Type* type)
{
    this->members = mem;
    this->size = 0;
    //this->type = type; 
}
ArrayType::ArrayType(Expression * lower, Expression* upper, Type* base)
{
    this->lower = lower->value;
    this->upper = upper->value;
    this->base = base;
    this->size = (this->upper - this->lower) * this->base->size;
}


