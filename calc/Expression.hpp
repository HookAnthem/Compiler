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
Expression * Apply(Expression * a, Expression * b, std::string op, std::string mode);

void CheckExpression(Expression * a, Expression * b);

void Binop(std::string op, std::string d, std::string a, std::string b);

void BinopLo(std::string op, std::string d, std::string a, std::string b);

void BinopHi(std::string op, std::string d, std::string a, std::string b);

void Unop(std::string op, std::string d, std::string a);

std::string LoadExpression(Expression * a);
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







