#pragma once
#include "Global.hpp"
class Type;
class Expression;
class SymbolTable;
class oneValxpr;

class MiddleAsembler
{
public:

    MiddleAsembler() : expressions(), tempStrList(), tempExprIdxs(),
        endifNumber(0), endifNumberStack(), forStack(), forAscendStack(),
        stringIdTemp(), functionOffset(0)
    {
        tempStrList.emplace_back();
    };

    ~MiddleAsembler()
    {
    }

    void assertIntOrChar(int);
    int appendStrList(int,char*);
    int makeStrList(char*);
    void makeVars(int,int, std::string reg = "$gp");
    int getLval(std::string);
    int assignExprToLval(int,int);
    void clearExpressions();
    int charLiteral(char);
    int charCast(int);
    int intLiteral(int);
    int intCast(int);
    int stringLiteral(char*);
    int getLint(char*);
    int loadReg(oneValxpr*);
    int binOp(int, int, int (MiddleAsembler::*)(int, int), bool matchTypes = true);
    int binOpAdd(int, int);
    int binOpAnd(int, int);
    int binOpDiv(int, int);
    int binOpEq(int, int);
    int binOpGteq(int, int);
    int binOpGt(int, int);
    int binOpLteq(int, int);
    int binOpLt(int, int);
    int binOpMod(int, int);
    int binOpMult(int, int);
    int binOpNeq(int, int);
    int binOpOr(int, int);
    int binOpSub(int, int);

    int makeRecordVars(int,int);
    int mergeRecords(int, int);
    void addTempStrLayer();
    void removeTempStrLayer();

    int preWhile();
    void startWhile(int,int);
    void endWhile(int);

    int startIf(int,bool);
    void endIf();
    void doElse(int);

    int startRepeat();
    void endRepeat(int,int);

    int startFor(char*,int);
    int compareFor(int,int,bool);
    void endFor(int);

    int writeExpression(int);
    void readToLval(int);

    void storeConst(char*, int);
    
    int unOp(int,int (MiddleAsembler::*)(int));
    int unOpNeg(int);
    int unOpNot(int);
    int unOpDecr(int);
    int unOpIncr(int);


    int getLvalArr(int,int);
    int getLvalRec(int,char*);

    int buildArray(int,int,int);

    void doProcedurePrologue(std::string);
    void doProcedureEpilogue();
    void precallProcedure(std::string);

    void doFunctionPrologue(std::string);
    void doFunctionEpilogue();
    void precallFunction(std::string);
    void startFunction(std::string);

    void makeParameters(int, int);

    void addArgument(int i){functionArgumentIdxs.push_back(i);};
private:
    std::vector<Expression*> expressions;
    std::vector<std::vector<std::string>> tempStrList;
    std::vector<int> tempExprIdxs;
    int endifNumber;
    std::vector<int> endifNumberStack;
    std::vector<int> forStack;
    std::vector<bool> forAscendStack;
    std::string stringIdTemp;
    std::vector<bool> forNewVar;
    std::vector<int> functionArgumentIdxs;
    int functionOffset;

};
void ignoreFunction();
