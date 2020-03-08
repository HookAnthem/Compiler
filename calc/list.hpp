#pragma once 
#include "Global.hpp"

class list
{
    public: 
	int storage(std::string); 
	std::string Lookup(int);
	int Size();
	std::vector<std::string> strings;
};
