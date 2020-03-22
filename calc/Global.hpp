#pragma once 

/* Libs */
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <sstream>
#include <array>
#include <fstream>

/* Locals */
#include "SymbolTable.hpp"
#include "Expression.hpp"
#include "Operations.hpp"
#include "RegPool.hpp"
#include "Asembler.hpp"
#include "list.hpp"
#include "Type.hpp"
#include "Writing.hpp"
class Type;
class Expression;
class SymbolTable;
class RegPool;
class Asembler;
class SimpleType;
class list;
class ArrayType; 
class RecordType; 

extern SymbolTable SYMBOL_TABLE;
extern RegPool REG_POOL; 
extern Asembler FOUT;
extern list STRING_LIST;

extern SimpleType TYPE_INT;
extern SimpleType TYPE_CHAR;
extern SimpleType TYPE_BOOL;
extern SimpleType TYPE_STR;
extern Expression EXPR_TRUE;
extern Expression EXPR_FALSE;
extern const bool printDebug;
