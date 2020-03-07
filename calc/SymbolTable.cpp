#include "SymbolTable.hpp"
#include "Global.hpp"



void SymbolTable::init()
{
    offset = 0; 
    scoped();
    SYMBOL_TABLE.Store("INTEGER", &TYPE_INT);
    SYMBOL_TABLE.Store("integer", &TYPE_INT);
    
    SYMBOL_TABLE.Store("CHAR", &TYPE_CHAR);
    SYMBOL_TABLE.Store("char", &TYPE_CHAR);
    
    SYMBOL_TABLE.Store("STRING", &TYPE_STR);
    SYMBOL_TABLE.Store("string", &TYPE_STR);
    
    SYMBOL_TABLE.Store("BOOLEAN", &TYPE_BOOL);
    SYMBOL_TABLE.Store("boolean", &TYPE_BOOL);
    
    SYMBOL_TABLE.Store("true", &EXPR_TRUE);
    SYMBOL_TABLE.Store("false", &EXPR_FALSE);
    
    scoped();
}

Expression * SymbolTable::ExpressionLookup(std::string id)
{
    for(int i = expression_table.size() - 1; i>= 0; --i)
    {
	try
	{
            return expression_table[i].at(id);
	}
	catch(const std::out_of_range& e)
	{
	   std::cout << "We went out of range no worries we will keep going" << std::endl;
	}
    }
}
void SymbolTable::Store(std::string id, Expression *expr)
{
   if(expression_table.back().count(id) == 0)
   {
       expression_table.back()[id] = expr;
   }
   else
   {
	   std::cout << "This ID seems to exist elsewhere.... Hope this isnt Kenneth Sundbergs code." << std::endl;
   }
}
Type * SymbolTable::TypeLookup(std::string id)
{
    for(int i = type_table.size() - 1; i>= 0; --i)
    {
	try
	{
            return type_table[i].at(id);
	}
	catch(const std::out_of_range& e)
	{
	   std::cout << "We went out of range no worries we will keep going" << std::endl;
	}
    }
}
void SymbolTable::Store(std::string id, Type *type)
{
   if(type_table.back().count(id) == 0)
   {
       type_table.back()[id] = type;
   }
   else
   {
	   std::cout << "This ID seems to exist elsewhere.... Hope this isnt Kenneth Sundbergs code. Hang On resuming progress..." << std::endl;
   }
}
void SymbolTable::scoped()
{
    std::map<std::string, Expression*> expr;
    std::map<std::string, Type*> type;
    expression_table.push_back(expr);
    type_table.push_back(type);
}
void SymbolTable::remove()
{
    expression_table.pop_back();
    type_table.pop_back();
}
int SymbolTable::Counter(int size)
{
    int temp = offset; 
    offset += size;
    return temp;
}




