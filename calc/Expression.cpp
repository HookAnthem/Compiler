#include "Expression.hpp"
Expression::Expression(std::string memLoc, Type * t)
{
    this->memLoc = memLoc; 
    this->type = type;
    this->has_add = true;
}
Expression::Expression(int x, Type * t)
{
    this->value = x;
    this->type = t; 
    this->is_const = true;
}
Expression::~Expression()
{
	if(!this->has_add && !this->is_const && this->memLoc.length() > 0)
	{
	    REG_POOL.ReleaseReg(this->memLoc);
	}
}
void CheckExpression(Expression * one, Expression * two){
	if(!one || !two){ 
		std::cout << "Error: nullptr during expression apply." << std::endl;
        }
        if(one->type != two->type) { // Type error
		std::cout << "Error: Type error during expression apply." <<std::endl;
        }
	
}
std::string LoadExpression(Expression * one)
{
    if(one->is_const)
    {
	std::string reg = REG_POOL.GetReg();
	FOUT.Write(std::string("li " + reg + ", " + std::to_string(one->value)));
	return reg;
    }
    else if(one->has_add)
    {
	return LoadVar(one->memLoc);
    }
    else
    {
	return one->memLoc;
    }
}
void Binary(std::string operation, std::string destReg, std::string reg1, std::string reg2) {
	FOUT.Write(std::string(operation + " " + destReg + "," + reg1 + "," + reg2));
}

void BinaryLo(std::string operation, std::string destReg, std::string reg1, std::string reg2){
	FOUT.Write(std::string(operation + " " + reg1 + "," + reg2));
	FOUT.Write(std::string("mflo " + destReg));
}

void BinaryHi(std::string operation, std::string destReg, std::string reg1, std::string reg2){
        FOUT.Write(std::string(operation + " " + reg1 + "," + reg2));
        FOUT.Write(std::string("mfhi " + destReg));
}

void Unary(std::string operation, std::string destReg, std::string reg1){
	FOUT.Write(std::string(operation + " " + destReg + "," + reg1));
	if(operation == "not"){
		FOUT.Write(std::string("sltu " + destReg + ", $zero, " + reg1));
		FOUT.Write(std::string("xori " + destReg + "," + reg1 + ",1"));
	}
}

Expression * Apply(Expression * one, Expression * two, std::string operation, std::string type){
	std::string reg1 = LoadExpression(one);
	std::string reg2 = LoadExpression(two);
	if(type == "binar")
	{
	    Binary(operation, reg1, reg1, reg2);
	}
	if(type == "hi")
	{
	    BinaryHi(operation, reg1, reg1, reg2);
	}
	if(type == "lo")
	{
	    BinaryLo(operation, reg1, reg1, reg2);
	}
	if(type == "un")
	{
	    Unary(operation, reg1, reg2);
	}
	REG_POOL.ReleaseReg(reg2);
	return new Expression(reg1, one->type);
}
Expression * Lvalue(std::string id)
{
     return SYMBOL_TABLE.ExpressionLookup(id); 
}
Expression * add(Expression * one, Expression * two)
{
    if(one->is_const && two->is_const)
    {
	    return new Expression(one->value + two->value, one->type);
    }
    else
    {
	    Apply(one, two, "add", "binar");
    }
}
Expression * sub(Expression * one, Expression * two)
{
    if(one->is_const && two->is_const)
    {
	    return new Expression(one->value - two->value, one->type);
    }
    else
    {
	    Apply(one, two, "sub", "binar");
    }
}
Expression * mult(Expression * one, Expression * two)
{
    if(one->is_const && two->is_const)
    {
	    return new Expression(one->value * two->value, one->type);
    }
    else
    {
	    Apply(one, two, "mult", "lo");
    }
}
Expression * div(Expression * one, Expression * two)
{
    if(one->is_const && two->is_const)
    {
	    return new Expression(one->value / two->value, one->type);
    }
    else
    {
	    Apply(one, two, "div", "lo");
    }
}
Expression * mod(Expression * one, Expression * two)
{
    if(one->is_const && two->is_const)
    {
	    return new Expression(one->value % two->value, one->type);
    }
    else
    {
	    Apply(one, two, "mod", "hi");
    }
}
Expression * And(Expression * one, Expression * two)
{
    if(one->is_const && two->is_const)
    {
	    return new Expression(one->value && two->value, one->type);
    }
    else
    {
	    Apply(one, two, "and", "binar");
    }
}
Expression * equal(Expression * one, Expression * two)
{
    if(one->is_const && two->is_const)
    {
	    return new Expression(one->value == two->value, one->type);
    }
    else
    {
	    Apply(one, two, "seq", "binar");
    }
}
Expression * Or(Expression * one, Expression * two)
{
    if(one->is_const && two->is_const)
    {
	    return new Expression(one->value || two->value, one->type);
    }
    else
    {
	    Apply(one, two, "or", "binar");
    }
}
Expression * neg(Expression * one, Expression * two)
{
    if(one->is_const && two->is_const)
    {
	    return new Expression(one->value != two->value, one->type);
    }
    else
    {
	    Apply(one, two, "sne", "binar");
    }
}
Expression * leg(Expression * one, Expression * two)
{
    if(one->is_const && two->is_const)
    {
	    return new Expression(one->value <= two->value, one->type);
    }
    else
    {
	    Apply(one, two, "sle", "binar");
    }
}
Expression * grteq(Expression * one, Expression * two)
{
    if(one->is_const && two->is_const)
    {
	    return new Expression(one->value >= two->value, one->type);
    }
    else
    {
	    Apply(one, two, "sge", "binar");
    }
}
Expression * les(Expression * one, Expression * two)
{
    if(one->is_const && two->is_const)
    {
	    return new Expression(one->value < two->value, one->type);
    }
    else
    {
	    Apply(one, two, "slt", "binar");
    }
}
Expression * grt(Expression * one, Expression * two)
{
    if(one->is_const && two->is_const)
    {
	    return new Expression(one->value > two->value, one->type);
    }
    else
    {
	    Apply(one, two, "sgt", "binar");
    }
}
