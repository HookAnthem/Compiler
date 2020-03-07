#include "ArrayType.hpp"

ArrayType::ArrayType(Expression * lower, Expression* upper, Type* base)
{
    this->lower = lower->value;
    this->upper = upper->value;
    this->base = base;
    this->size = (this->upper - this->lower) * this->base->size;
}


