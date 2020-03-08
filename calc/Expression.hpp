#pragma once 
#include "Global.hpp"
class Type; 


class Expression {
	public:
		std::string memLoc; 
		int value;
		Type* type;
		bool is_const = false;
		bool has_add = false;
		Expression(std::string, Type * t);
		Expression(int x, Type * t);
		~Expression();
};
Expression * Apply(Expression * one, Expression * two, std::string operation, std::string type);
void CheckExpression(Expression * one, Expression * two);
void Binary(std::string operation, std::string destReg, std::string reg1, std::string reg2);
void BinaryLo(std::string operation, std::string destReg, std::string reg1, std::string reg2);
void BinaryHi(std::string operation, std::string destReg, std::string reg1, std::string reg2);
void Unary(std::string operation, std::string destReg, std::string reg1);
std::string LoadExpression(Expression * one);
Expression * add(Expression * one, Expression * two);
Expression * sub(Expression * one, Expression * two);
Expression * mult(Expression * one, Expression * two);
Expression * div(Expression * one, Expression * two);
Expression * mod(Expression * one, Expression * two);
Expression * And(Expression * one, Expression * two);
Expression * equal(Expression * one, Expression * two);
Expression * Or(Expression * one, Expression * two);
Expression * neg(Expression * one, Expression * two);
Expression * leg(Expression * one, Expression * two);
Expression * grteq(Expression * one, Expression * two);
Expression * les(Expression * one, Expression * two);
Expression * grt(Expression * one, Expression * two);
Expression * ArrayAccess(Expression *, Expression*);
Expression * Lvalue(std::string id);

