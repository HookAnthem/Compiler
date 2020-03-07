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
std::string LoadExpression(Expression * one)
{
    if(one->is_const)
    {
    }
    else if(one->has_add)
    {
    }
    else
    {
    }
}
void Binop(std::string op, std::string d, std::string a, std::string b) {
	// op = operator, d = destination register, a = reg1, b = reg2
	FOUT.Write(std::string(op + " " + d + "," + a + "," + b + " # Binop"));
}

void BinopLo(std::string op, std::string d, std::string a, std::string b){
	FOUT.Write(std::string(op + " " + a + "," + b));
	FOUT.Write(std::string("mflo " + d));
}

void BinopHi(std::string op, std::string d, std::string a, std::string b){
        FOUT.Write(std::string(op + " " + a + "," + b));
        FOUT.Write(std::string("mfhi " + d));
}

void Unop(std::string op, std::string d, std::string a){
	FOUT.Write(std::string(op + " " + d + "," + a + "# Unop"));
	if(op == "not"){
		FOUT.Write(std::string("sltu " + d + ", $zero, " + a));
		FOUT.Write(std::string("xori " + d + "," + d + ",1"));
	}
}

Expression * Apply(Expression * a, Expression * b, std::string op, std::string mode){
	std::string reg1 = LoadExpression(a);
	std::string reg2 = LoadExpression(b);

	if(mode == "binop") Binop(op, reg1, reg1, reg2);
	else if(mode == "hi") BinopHi(op, reg1, reg1, reg2);
	else if(mode == "lo") BinopLo(op, reg1, reg1, reg2);
	else if(mode == "unop") Unop(op, reg1, reg2);

	REGISTER_POOL.ReleaseRegister(reg2);
	return new Expression(reg1, a->type);
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
	    Apply(one, two, "add", "binop");
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
	    Apply(one, two, "sub", "binop");
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
	    Apply(one, two, "and", "binop");
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
	    Apply(one, two, "seq", "binop");
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
	    Apply(one, two, "or", "binop");
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
	    Apply(one, two, "sne", "binop");
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
	    Apply(one, two, "sle", "binop");
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
	    Apply(one, two, "sge", "binop");
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
	    Apply(one, two, "slt", "binop");
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
	    Apply(one, two, "sgt", "binop");
    }
}




