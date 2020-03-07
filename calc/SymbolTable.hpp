#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include "Global.hpp"
class Expression;
class Type; 

class SymbolTable
{
  public:
    SymbolTable() = default;
    void init(); 
    Expression * ExpressionLookup(std::string id);
    void Store(std::string , Expression *expr);
    void Store(std::string id, Type *type);
    Type* TypeLookup(std::string id);
    void scoped();
    void remove();
    int Counter(int size); 
    
    int offset; 
    std::vector<std::map<std::string, Expression *>> expression_table;
    std::vector<std::map<std::string, Type *>> type_table;
};

#endif
