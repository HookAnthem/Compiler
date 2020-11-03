#pragma once
#include "Global.hpp"
class Constant;
class Variable;



struct SymbolTableLayer
{
    SymbolTableLayer(): constants(), variables(), types(){};
    std::map<std::string, Constant> constants;
    std::map<std::string, Variable> variables;
    std::map<std::string, Type *> types;
};

class SymbolTable
{ 
public:
    SymbolTable(): declTypes(), stack(), SimpleTypes(), ConstTypes(), stringList(), regPool(), frameOffsets(), offset(0){};
    void initialize();
    Constant lookupConst(std::string);
    Variable lookupVar(std::string);
    int lookupType(std::string);
    Type * getType(std::string);
    void storeType(std::string, Type*);
    void storeConst(std::string, Type*, int);
    void storeVar(std::string, Type*, std::string, bool onStack = false);
    void storeParam(std::string,Type*);
    void storeVarStack(std::string, Type*);
    int storeStringLiteral(std::string);
    void checkForIdDefined(std::string);
    void enterScope();
    void leaveScope();
    std::shared_ptr<std::string> requestRegister();
    Type* getSimpleType(std::string);
    Type* getSimpleType(int);
    int addConstType(Type*);
    Type* getConstType(int);
    std::vector<std::string> getStringList();
    void changeVarOffset(std::string, int);
    void pushFrameOffset();
    void popFrameOffset();
    void changeFrameOffsetBy(int);
    int storeType(char* id, int t);
private:
    std::vector<Type *> declTypes;
    std::vector<SymbolTableLayer> stack;
    std::vector<Type*> SimpleTypes;
    std::vector<Type*> ConstTypes;
    std::vector<std::string> stringList;
    std::vector<std::shared_ptr<std::string>> regPool;
    std::vector<int> frameOffsets;
    unsigned offset;
};
