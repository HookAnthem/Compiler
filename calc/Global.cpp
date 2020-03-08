#include "Global.hpp"
extern SymbolTable SYMBOL_TABLE;
extern RegPool REG_POOL; 
extern Asembler FOUT;
extern list STRING_LIST;

SimpleType TYPE_INT;
SimpleType TYPE_CHAR;
SimpleType TYPE_BOOL;
SimpleType TYPE_STR;
Expression EXPR_TRUE(1, &TYPE_BOOL);
Expression EXPR_FALSE(0, &TYPE_BOOL);
