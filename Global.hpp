#pragma once 

/* Libs */
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <sstream>
#include <array>
#include <fstream>
#include <memory>
#include <string>
#include <algorithm>

/* Local Things */
#include "MiddleAsembler.hpp"
#include "Expression.hpp"
#include "fold.hpp"
#include "Objects.hpp"
#include "SymbolTable.hpp"
#include "Type.hpp"
#include "Asembler.hpp"
#include "Operations.hpp"

class Type;
class Expression;
class SymbolTable;
class Constant;
class Variable;
class Asembler;

extern Asembler FOUT;
extern SymbolTable SYMBOL_TABLE;

extern const bool printDebug;
