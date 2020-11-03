#include "SymbolTable.hpp"

extern void yyerror(const char*);


unsigned const INT_TYPE = 0, CHAR_TYPE = 1, BOOL_TYPE = 2, STR_TYPE = 3;

void SymbolTable::initialize()
{
    SimpleTypes.push_back(new IntegerType);
    SimpleTypes.push_back(new CharacterType);
    SimpleTypes.push_back(new BooleanType);
    SimpleTypes.push_back(new StringType);

    enterScope();
    storeType("integer", SimpleTypes[INT_TYPE]);
    storeType("INTEGER", SimpleTypes[INT_TYPE]);
    storeType("char", SimpleTypes[CHAR_TYPE]);
    storeType("CHAR", SimpleTypes[CHAR_TYPE]);
    storeType("boolean", SimpleTypes[BOOL_TYPE]);
    storeType("BOOLEAN", SimpleTypes[BOOL_TYPE]);
    storeType("string", SimpleTypes[STR_TYPE]);
    storeType("STRING", SimpleTypes[STR_TYPE]);

    storeConst("true", SimpleTypes[BOOL_TYPE], 1);
    storeConst("TRUE", SimpleTypes[BOOL_TYPE], 1);
    storeConst("false", SimpleTypes[BOOL_TYPE], 0);
    storeConst("FALSE", SimpleTypes[BOOL_TYPE], 0);

    enterScope();
    pushFrameOffset();

    const int NUM_T_REGS = 10; // 0-9
    for(auto i = 0; i < NUM_T_REGS; i++)
    {
        regPool.push_back(std::make_shared<std::string>("$t" + std::to_string(i)));
    }

    const int NUM_S_REGS = 8; // 0-7
    for(auto i = 0; i < NUM_S_REGS; i++)
    {
        regPool.push_back(std::make_shared<std::string>("$s" + std::to_string(i)));
    }
}

Constant SymbolTable::lookupConst(std::string id)
{
    for (auto curLayer = stack.rbegin(); curLayer != stack.rend(); curLayer++)
    {
        auto found = curLayer->constants.find(id);
        if(found != curLayer->constants.end())
        {
            return found->second;
        }
    }
    return {};
}

Variable SymbolTable::lookupVar(std::string id)
{
    for (auto curLayer = stack.rbegin(); curLayer != stack.rend(); curLayer++)
    {
        auto found = curLayer->variables.find(id);
        if(found != curLayer->variables.end())
        {
            return found->second;
        }
    }
    return {};
}

int SymbolTable::lookupType(std::string id)
{
    for (auto curLayer = stack.rbegin(); curLayer != stack.rend(); curLayer++)
    {
        auto found = curLayer->types.find(id);
        if(found != curLayer->types.end())
        {
            auto foundInIneff = std::find(
                ConstTypes.begin(),
                ConstTypes.end(),
                found->second);
            if (foundInIneff != ConstTypes.end())
            {
                return foundInIneff - ConstTypes.begin();
            }
            
            for (auto idx = 0U; idx < SimpleTypes.size(); idx++)
            {
                if (SimpleTypes[idx] == found->second)
                {
                    ConstTypes.push_back(SimpleTypes[idx]);
                    return ConstTypes.size() - 1;
                }
            }
            

        }
    }
    throw std::runtime_error("Type " + id + " not defined");
}

Type * SymbolTable::getType(std::string id)
{
    for (auto curLayer = stack.rbegin(); curLayer != stack.rend(); curLayer++)
    {
        auto found = curLayer->types.find(id);
        if(found != curLayer->types.end())
        {
            return found->second;
        }
    }
    throw std::runtime_error("Type " + id + " not defined");
}

void SymbolTable::storeType(std::string id, Type* t)
{
    auto topLayer = stack.rbegin();
    topLayer->types[id] = t;
}

void SymbolTable::storeConst(std::string id, Type* t, int val)
{
    checkForIdDefined(id);
    auto topLayer = stack.rbegin();
    Constant c;
    c.type = t;
    c.value = val;
    topLayer->constants[id] = c;
}

void SymbolTable::storeVar(std::string id, Type* t, std::string reg, bool onStack)
{
    checkForIdDefined(id);
    auto topLayer = stack.rbegin();
    Variable v;
    if (t == getSimpleType("string"))
    {
        stringList.emplace_back();
        v.offset = stringList.size() - 1;
    }
    else
    {
        if (onStack)
        {
            frameOffsets.back() -= t->getPSize();
            v.offset = frameOffsets.back();
        }
        else
        {
            v.offset = offset;
            offset += t->getPSize();
        }
    }
    v.reg = reg;
    v.type = t;
    topLayer->variables[id] = v;
}

void SymbolTable::storeParam(std::string id,Type* t)
{
    auto v = Variable();
    v.reg = "$fp";
    v.type = t;
    v.offset = offset;
    offset += t->getPSize();
}

void SymbolTable::changeFrameOffsetBy(int i)
{
    frameOffsets.back() += i;
}

int SymbolTable::storeStringLiteral(std::string s)
{
    stringList.push_back(s);
    return(stringList.size() - 1);
}


void SymbolTable::checkForIdDefined(std::string id)
{
    auto topLayer = stack.rbegin();
    if(topLayer->constants.find(id) != topLayer->constants.end())
    {
        throw std::runtime_error("Constant " + id + " is already defined in this scope");
    }
    if(topLayer->variables.find(id) != topLayer->variables.end())
    {
        throw std::runtime_error("Variable " + id + " is already defined in this scope");
    }
}

void SymbolTable::enterScope()
{
    stack.emplace_back();
}

void SymbolTable::leaveScope()
{
    stack.pop_back();
}

Type* SymbolTable::getSimpleType(std::string s)
{
    if (s == "boolean")     return SimpleTypes[BOOL_TYPE];
    if (s == "integer")     return SimpleTypes[INT_TYPE];
    if (s == "character")   return SimpleTypes[CHAR_TYPE];
    if (s == "string")      return SimpleTypes[STR_TYPE];
    throw std::domain_error("Simple type " + s + " not found");
}

Type* SymbolTable::getSimpleType(int i)
{
    return SimpleTypes[i];
}

int SymbolTable::addConstType(Type *t)
{
    ConstTypes.push_back(t);
    return ConstTypes.size() - 1;
}

Type * SymbolTable::getConstType(int i)
{
    return ConstTypes[i];
}

std::vector<std::string> SymbolTable::getStringList()
{
    return stringList;
}

std::shared_ptr<std::string> SymbolTable::requestRegister()
{
    for (auto & reg : regPool)
    {
        if(reg.unique())
        {
            return reg;
        }
    }
    yyerror("Depleted register pool");
}

void SymbolTable::changeVarOffset(std::string id, int offset)
{
    for (auto curLayer = stack.rbegin(); curLayer != stack.rend(); curLayer++)
    {
        auto found = curLayer->variables.find(id);
        if(found != curLayer->variables.end())
        {
            found->second.offset = offset;
            return;
        }
    }
}

void SymbolTable::pushFrameOffset()
{
    frameOffsets.push_back(0);
}

void SymbolTable::popFrameOffset()
{
    frameOffsets.pop_back();
}
int SymbolTable::storeType(char* id, int t)
{
   auto type = SYMBOL_TABLE.getConstType(t);
   SYMBOL_TABLE.storeType(id, type);
}
