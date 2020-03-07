#pragma once 
#include "Global.hpp"

class ArrayType : public Type 
{
    public: 
	int upper; 
	int lower; 
	ArrayType(Expression * lower, Expression* upper, Type * base);
};
