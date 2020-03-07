#pragma once 

/* Libs */
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstdlib>

/* Locals */
#include "SymbolTable.hpp"
#include "Expression.hpp"
#include "Operations.hpp"


/* Types*/
#include "Type.hpp"
#include "ArrayType.hpp"
#include "RecordType.hpp"
#include "SimpleType.hpp"

class Type;
class Expressions;
class SymbolTable;

extern SymbolTable SYMBOL_TABLE;


extern SimpleType TYPE_INT;
extern SimpleType TYPE_CHAR;
extern SimpleType TYPE_BOOL;
extern SimpleType TYPE_STR;
extern Expression EXPR_TRUE;
extern Expression EXPR_FALSE;
