#include "Operations.hpp"

void saveVar(std::string id, Type * t)
{
    int offset = SYMBOL_TABLE.Counter(t->size);
    std::string address = std::string(std::to_string(offset) + "($gp)");
    Expression *expr = new Expression(address, t);
    expr->has_add = true;
    SYMBOL_TABLE.Store(id, expr);
}
void saveVar(std::vector<std::string> *varNames, Type * t)
{
    for(int i = 0; i < varNames->size(); ++i)
    {
	saveVar(varNames->at(i), t);
    }
}
std::string LoadVar(std::string memLoc)
{
    std::string temp = REG_POOL.GetReg();
    FOUT.Write(std::string("lw " + temp + ", " + memLoc)); 
    return temp;
}
void Assign(Expression * one, Expression * two)
{
	std::string temp = LoadExpression(two);
	FOUT.Write(std::string("sw " + temp + "," + one->memLoc));
	REG_POOL.ReleaseReg(temp); 
}
int Offset(std::string memLoc)
{
   int offset = memLoc.find("(");
   try 
   {
	return std::stoi(memLoc.substr(0, offset));
   }
   catch(std::invalid_argument e)
   {
	return 0;
   }
}
std::string address(std::string memLoc)
{
    int offset = memLoc.find("(");
    return memLoc.substr(offset, memLoc.length());
}
std::string incrementLoc(std::string memLoc, int x)
{
    int offset = Offset(memLoc);
    std::string mem = address(memLoc);
    offset += x;
    std::string newLoc = std::to_string(offset) + mem;
    return newLoc;
}
