#include "Global.hpp"

SymbolTable SYMBOL_TABLE;
SimpleType TYPE_INT;
SimpleType TYPE_CHAR;
SimpleType TYPE_BOOL;
SimpleType TYPE_STR;
Expression EXPR_TRUE(1, &TYPE_BOOL);
Expression EXPR_FALSE(0, &TYPE_BOOL);
