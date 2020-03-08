#pragma once
#include "Global.hpp"

class Expression;

class Type {
  public:
    int size;
    Type * base = this;
    virtual Type * baseType();
};

class SimpleType : public Type 
{
   public:
       SimpleType();
};

class RecordType: public Type
{
    public:
	RecordType(std::vector<std::string> mem, Type* type); 
	std::vector<std::string> members;
	void addTo(std::string memValue, Type* type);
	int offset(std::string value);
 	Type * lookup(std::string value);
	std::map<std::string, int> offsetTable;
	std::map<std::string, Type*> typeTable;
};

class ArrayType : public Type 
{
    public: 
	int upper; 
	int lower; 
	ArrayType(Expression * lower, Expression* upper, Type * base);
};




