#pragma Once 
#include "Global.hpp"

void saveVar(std::string id, Type * t);
void saveVar(std::vector<std::string> *varNames, Type * t);
std::string LoadVar(std::string);
void Assign(Expression * a, Expression * b);
int offset(std::string);
std::string address(std::string memLoc);
std::string incrementLoc(std::string memLoc, int x);
