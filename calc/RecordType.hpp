#pragma once 
#include "Global.hpp"

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
