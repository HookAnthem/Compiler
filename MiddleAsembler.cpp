#include "MiddleAsembler.hpp"
extern void yyerror(const char*);
int MiddleAsembler::charLiteral(char c)
{
    fold *foldedVal = new fold();
    foldedVal->setType(SYMBOL_TABLE.getSimpleType("character"));
    foldedVal->setValue(c);
    expressions.push_back(foldedVal);
    return expressions.size() - 1;
}

int MiddleAsembler::charCast(int i)
{
    auto e = expressions[i];
    e->setType(SYMBOL_TABLE.getSimpleType("character"));
    return i;
}

int MiddleAsembler::intLiteral(int i)
{
    fold *foldedVal = new fold();
    foldedVal->setType(SYMBOL_TABLE.getSimpleType("integer"));
    foldedVal->setValue(i);
    expressions.push_back(foldedVal);
    return expressions.size() - 1;
}

int MiddleAsembler::intCast(int i)
{
    auto e = expressions[i];
    e->setType(SYMBOL_TABLE.getSimpleType("integer"));
    return i; 
}

int MiddleAsembler::stringLiteral(char* cstr)
{
    fold *foldedVal = new fold();
    foldedVal->setType(SYMBOL_TABLE.getSimpleType("string"));
    foldedVal->setValue(SYMBOL_TABLE.storeStringLiteral(cstr));
    expressions.push_back(foldedVal);
    return expressions.size() - 1;
}

int MiddleAsembler::writeExpression(int i)
{
    auto e = expressions[i];
    if(auto fe = dynamic_cast<fold*>(e))
    {
        if (fe->getType() == SYMBOL_TABLE.getSimpleType("string"))
        {
            FOUT.Write("la $a0, STR" + std::to_string(fe->getValue()));
            FOUT.Write("li $v0, 4");
            FOUT.Write("syscall");
        }
        else if (fe->getType() == SYMBOL_TABLE.getSimpleType("character"))
        {
            FOUT.Write("la $a0, " + std::to_string(fe->getValue()));
            FOUT.Write("li $v0, 11");
            FOUT.Write("syscall");;
        }
        else if (fe->getType() == SYMBOL_TABLE.getSimpleType("integer")
              || fe->getType() == SYMBOL_TABLE.getSimpleType("boolean"))
        {
            FOUT.Write("la $a0, " + std::to_string(fe->getValue()));
            FOUT.Write("li $v0, 1");
            FOUT.Write("syscall");;
        }
    }
    else
    if (auto le = dynamic_cast<oneValxpr*>(e))
    {
        if (le->getType() == SYMBOL_TABLE.getSimpleType("string"))
        {
            FOUT.Write("la $a0, STR" + std::to_string(le->getOffset()));
            FOUT.Write("li $v0, 4");
            FOUT.Write("syscall");;
        }
    }
    else
    if (auto re = dynamic_cast<RegExpr*>(e))
    {

        if (re->getType() == SYMBOL_TABLE.getSimpleType("string"))
        {
            FOUT.Write("li $v0, 4");;
        }
        else if (re->getType() == SYMBOL_TABLE.getSimpleType("character"))
        {
            FOUT.Write("la $a0, (" + *re->getRegister() + ")");
            FOUT.Write("li $v0, 11");;
        }
        else if (re->getType() == SYMBOL_TABLE.getSimpleType("integer") || re->getType() == SYMBOL_TABLE.getSimpleType("boolean"))
        {
            FOUT.Write("la $a0, (" + *re->getRegister() + ")");;
            FOUT.Write("li $v0, 1");;
        }
        FOUT.Write("syscall");

    }
    return {};
}

void MiddleAsembler::clearExpressions()
{
    for (auto & e : expressions)
    {
        delete e;
        e = nullptr;
    }
    expressions.clear();
}

int MiddleAsembler::appendStrList(int i,char* c)
{
    tempStrList[i].push_back(c);
    return i;
}

int MiddleAsembler::makeStrList(char* c)
{
    tempStrList.emplace_back();
    tempStrList.rbegin()->push_back(c);
    return tempStrList.size() - 1;
}

void MiddleAsembler::makeVars(int l,int r, std::string reg)
{
    auto type = SYMBOL_TABLE.getConstType(r);

    for (const auto & name : tempStrList[l])
    {
        SYMBOL_TABLE.storeVar(name, type, reg);
    }
}

void MiddleAsembler::makeParameters(int i, int t)
{
    auto type = SYMBOL_TABLE.getConstType(t);
    for (const auto & name : tempStrList[i])
    {
        SYMBOL_TABLE.storeParam(name, type);
    }
}

int MiddleAsembler::makeRecordVars(int l,int r)
{
    auto type = SYMBOL_TABLE.getConstType(r);

    auto size = tempStrList.size();
    auto record = new RecordType(size);
    for (const auto & name : tempStrList[l])
    {
        record->addMember(name, type);
    }
    return SYMBOL_TABLE.addConstType(record);
}

int MiddleAsembler::mergeRecords(int l, int r)
{
    auto lr = dynamic_cast<RecordType*>(SYMBOL_TABLE.getConstType(l));
    auto rr = dynamic_cast<RecordType*>(SYMBOL_TABLE.getConstType(r));

    lr->addMembers(rr->getMembers());
    return l;

}

int MiddleAsembler::getLval(std::string lval)
{
    auto c = SYMBOL_TABLE.lookupConst(lval);
    auto v = SYMBOL_TABLE.lookupVar(lval);
    
    if (c.type != nullptr)
    {
        fold *fe = new fold();
        fe->setValue(c.value);
        fe->setType(c.type);
        expressions.push_back(fe);
        return expressions.size() - 1;
    }
    else if (v.reg != "")
    {
        oneValxpr *le = new oneValxpr();
        le->setRegister(std::make_shared<std::string>(v.reg));
        le->setOffset(v.offset);
        le->setType(v.type);
        stringIdTemp = lval;
        expressions.push_back(le);
        return expressions.size() - 1;
    }

}


int MiddleAsembler::getLvalArr(int lv, int rexp)
{
    auto oneValxp = dynamic_cast<oneValxpr*>(expressions[lv]);
    auto arrType = dynamic_cast<ArrayType*>(expressions[lv]->getType());
    if (auto rle = dynamic_cast<oneValxpr*>(expressions[rexp]))
    {
        rexp = loadReg(rle);
    }
    auto lowerBound = arrType->getLowerBound();
    if (auto rfexp = dynamic_cast<fold*>(expressions[rexp]))
    {
        auto val = rfexp->getValue() - lowerBound;
        auto offset = val * arrType->getPBaseSize();
        oneValxp->setOffset(oneValxp->getOffset() + offset);
        oneValxp->setType(arrType->getBaseType());
        return lv;
    }
    if (auto rrexp = dynamic_cast<RegExpr*>(expressions[rexp]))
    {
        auto reg = rrexp->getRegister();
        auto reg2 = SYMBOL_TABLE.requestRegister();
        FOUT.Write("sub " + *reg + ", " + *reg + ", " + std::to_string(lowerBound));
        FOUT.Write("mul " + *reg + ", " + *reg + ", " + std::to_string(arrType->getPBaseSize()));
        FOUT.Write("addi " + *reg2 + ", " + *oneValxp->getRegister() + ", " + std::to_string(oneValxp->getOffset()));
        FOUT.Write("add " + *reg2 + ", " + *reg2 + ", " + *reg);
        oneValxp->setOffset(0);
        oneValxp->setRegister(reg2);
        oneValxp->setType(arrType->getBaseType());

        rrexp->releaseRegister();
        return lv;
    }
}

int MiddleAsembler::getLvalRec(int lv,char* rid)
{
    auto oneValxp = dynamic_cast<oneValxpr*>(expressions[lv]);
    auto recType = dynamic_cast<RecordType*>(expressions[lv]->getType());
    auto members = recType->getMembers();
    auto found = members.find(rid);
    auto offset = 0;
    for (auto i = members.begin(); ;i++)
    {
        if (i == members.end()) yyerror("what?");
        if (i->first != std::string(rid))
        {
            offset += i->second->getPSize();
        }
        else
        {
            oneValxp->setType(i->second);
            break;
        }
    }


    auto reg = SYMBOL_TABLE.requestRegister();
    FOUT.Write("addi " + *reg + ", " + *oneValxp->getRegister() + ", " + std::to_string(oneValxp->getOffset()));
    FOUT.Write("addi " + *reg + ", " + *reg + ", " + std::to_string(offset));

    oneValxp->setOffset(0);
    oneValxp->setRegister(reg);
    
    return lv;
}

//FOUT.Write breaking multiArray
int MiddleAsembler::assignExprToLval(int li, int ei)
{
    auto oneVal = dynamic_cast<oneValxpr*>(expressions[li]);
    auto expr = expressions[ei];
    if (auto at = dynamic_cast<ArrayType*>(oneVal->getType()))
    {
        auto twoVal = dynamic_cast<oneValxpr*>(expressions[ei]);
        auto undersize = at->getPSize();
        auto reg = SYMBOL_TABLE.requestRegister();
        for (auto i = 0; i < undersize; i+=4)
        {
            std::cout << "lw " << *reg << ", " << twoVal->getOffset() + i << "(" << *twoVal->getRegister() << ")" << std::endl;
	    std::cout << "sw " << *reg << ", " << oneVal->getOffset() + i << "(" << *oneVal->getRegister() << ")" << std::endl;
        }
    }
    else
    if (auto rt = dynamic_cast<RecordType*>(oneVal->getType()))
    {
        auto twoVal = dynamic_cast<oneValxpr*>(expressions[ei]);
        auto undersize = rt->getPSize();
        auto reg = SYMBOL_TABLE.requestRegister();
        for (auto i = 0; i < undersize; i+=4)
        {
            std::cout << "lw " << *reg << ", " << twoVal->getOffset() + i << "(" << *twoVal->getRegister() << ")" << std::endl;
	    std::cout << "sw " << *reg << ", " << oneVal->getOffset() + i << "(" << *oneVal->getRegister() << ")" << std::endl;
        }
    }
    else
    if (auto fe = dynamic_cast<fold*>(expr))
    {
        auto reg = SYMBOL_TABLE.requestRegister();
        if (fe->getType() == SYMBOL_TABLE.getSimpleType("string"))
        {
            SYMBOL_TABLE.changeVarOffset(stringIdTemp, fe->getValue());
            oneVal->setOffset(fe->getValue());
        }
        else
        {
            std::cout << "addi " << *reg << ", $0, " << fe->getValue() << std::endl;
            std::cout << "sw " << *reg << ", " << oneVal->getOffset() << "(" << *oneVal->getRegister() << ")" << std::endl;
        }

    }
    else if (auto le = dynamic_cast<oneValxpr*>(expr))
    {
        auto reg = SYMBOL_TABLE.requestRegister();
        std::cout << "lw " << *reg << ", " << le->getOffset() << "(" << *le->getRegister() << ")" << std::endl;
	std::cout << "sw " << *reg << ", " << oneVal->getOffset() << "(" << *oneVal->getRegister() << ")" << std::endl;
    }
    else if (auto re = dynamic_cast<RegExpr*>(expr))
    {
        std::cout << "sw " << *re->getRegister() << ", " << oneVal->getOffset() << "(" << *oneVal->getRegister() << ")" << std::endl;
    }
    return li;

}

void MiddleAsembler::readToLval(int i)
{
    auto le = dynamic_cast<oneValxpr*>(expressions[i]);
  
    if (le->getType() == SYMBOL_TABLE.getSimpleType("integer") || le->getType() == SYMBOL_TABLE.getSimpleType("boolean"))
    {
        FOUT.Write("li $v0, 5");
        FOUT.Write("syscall");
        FOUT.Write("sw $v0, " + std::to_string(le->getOffset()) + "(" + *le->getRegister() + ")");

    }
    else if (le->getType() == SYMBOL_TABLE.getSimpleType("character"))
    {
        FOUT.Write("li $v0, 12");
        FOUT.Write("syscall");
        FOUT.Write("sw $v0, " + std::to_string(le->getOffset()) + "(" + *le->getRegister() + ")"); 
    }
}

void MiddleAsembler::storeConst(char* id, int i)
{
    auto fe = dynamic_cast<fold*>(expressions[i]);
    auto t = fe->getType();
    auto val = fe->getValue();
    SYMBOL_TABLE.storeConst(id, t, val);
}
int MiddleAsembler::loadReg(oneValxpr* le)
{
    auto regExpr = new RegExpr();
    auto reg = SYMBOL_TABLE.requestRegister();
    FOUT.Write("lw " + *reg + ", " + std::to_string(le->getOffset()) + "(" + *le->getRegister() + ")");
    regExpr->setRegister(reg);
    regExpr->setType(le->getType());
    expressions.push_back(regExpr);
    return expressions.size() - 1;
}
int MiddleAsembler::binOp(int l, int r, int (MiddleAsembler::*cb)(int, int), bool matchTypes)
{
    if(auto loneValxpr = dynamic_cast<oneValxpr*>(expressions[l]))
    {
        l = loadReg(loneValxpr);
    }

    if(auto twoValxpr = dynamic_cast<oneValxpr*>(expressions[r]))
    {
        r = loadReg(twoValxpr);
    }

    return (this->*cb)(l,r);
}
int MiddleAsembler::binOpAdd(int l, int r)
{
    auto oneExpr = dynamic_cast<fold*>(expressions[l]);
    auto twoExpr = dynamic_cast<fold*>(expressions[r]);
    auto oneRegExpr = dynamic_cast<RegExpr*>(expressions[l]);
    auto twoRegExpr = dynamic_cast<RegExpr*>(expressions[r]);

    if(oneRegExpr)
    {
        if (twoRegExpr)
        {
            FOUT.Write("add " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + *twoRegExpr->getRegister());
            twoRegExpr->releaseRegister();
            return l;
        }
        else
        if(twoExpr)
        {
            FOUT.Write("addi " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + std::to_string(twoExpr->getValue()));
            return l;
        }
    }
    else
    if(oneExpr)
    {
        if(twoRegExpr)
        {
            FOUT.Write("addi " + *twoRegExpr->getRegister() + ", " + *twoRegExpr->getRegister() + ", " + std::to_string(oneExpr->getValue()));
            return r;
        }
        else
        if(twoExpr)
        {
            oneExpr->setValue(oneExpr->getValue() + twoExpr->getValue());
            return l;
        }
    }
}

int MiddleAsembler::binOpAnd(int l, int r)
{   
    auto oneExpr = dynamic_cast<fold*>(expressions[l]);
    auto twoExpr = dynamic_cast<fold*>(expressions[r]);
    auto oneRegExpr = dynamic_cast<RegExpr*>(expressions[l]);
    auto twoRegExpr = dynamic_cast<RegExpr*>(expressions[r]);

    if(oneRegExpr)
    {
        if (twoRegExpr)
        {
            FOUT.Write("and " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + *twoRegExpr->getRegister());
            twoRegExpr->releaseRegister();
            return l;
        }
        else
        if(twoExpr)
        {
            FOUT.Write("andi " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + std::to_string(twoExpr->getValue()));
            return l;
        }
    }
    else
    if(oneExpr)
    {
        if(twoRegExpr)
        {
            FOUT.Write("andi " + *twoRegExpr->getRegister() + ", " + *twoRegExpr->getRegister() + ", " + std::to_string(oneExpr->getValue()));
            return r;
        }
        else
        if(twoExpr)
        {
            oneExpr->setValue(oneExpr->getValue() & twoExpr->getValue());
            return l;
        }
    }
}

int MiddleAsembler::binOpOr(int l, int r)
{
    auto oneExpr = dynamic_cast<fold*>(expressions[l]);
    auto twoExpr = dynamic_cast<fold*>(expressions[r]);
    auto oneRegExpr = dynamic_cast<RegExpr*>(expressions[l]);
    auto twoRegExpr = dynamic_cast<RegExpr*>(expressions[r]);

    if(oneRegExpr)
    {
        if (twoRegExpr)
        {
            FOUT.Write("or " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + *twoRegExpr->getRegister());
            twoRegExpr->releaseRegister();
            return l;
        }
        else
        if(twoExpr)
        {
            FOUT.Write("ori " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + std::to_string(twoExpr->getValue()));
            return l;
        }
    }
    else
    if(oneExpr)
    {
        if(twoRegExpr)
        {
            FOUT.Write("ori " + *twoRegExpr->getRegister() + ", " + *twoRegExpr->getRegister() + ", " + std::to_string(oneExpr->getValue()));
            return l;
        }
        else
        if(twoExpr)
        {
            oneExpr->setValue(oneExpr->getValue() | twoExpr->getValue());
            return l;
        }
    }
}

int MiddleAsembler::binOpEq(int l, int r)
{
    auto oneExpr = dynamic_cast<fold*>(expressions[l]);
    auto twoExpr = dynamic_cast<fold*>(expressions[r]);
    auto oneRegExpr = dynamic_cast<RegExpr*>(expressions[l]);
    auto twoRegExpr = dynamic_cast<RegExpr*>(expressions[r]);

    if(oneRegExpr)
    {
        if (twoRegExpr)
        {
            FOUT.Write("seq " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + *twoRegExpr->getRegister());
            twoRegExpr->releaseRegister();
            return l;
        }
        else
        if(twoExpr)
        {
            auto reg = SYMBOL_TABLE.requestRegister();
            FOUT.Write("li " + *reg + ", " + std::to_string(twoExpr->getValue()));
            FOUT.Write("seq " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + *reg);
            return l;
        }
    }
    else
    if(oneExpr)
    {
        if(twoRegExpr)
        {   
            auto reg = SYMBOL_TABLE.requestRegister();
            FOUT.Write("li " + *reg + ", " + std::to_string(oneExpr->getValue()));
            FOUT.Write("seq " + *twoRegExpr->getRegister() + ", " + *twoRegExpr->getRegister() + ", " + *reg);
            return r;
        }
        else
        if(twoExpr)
        {
            oneExpr->setValue(oneExpr->getValue() == twoExpr->getValue());
            return l;
        }
    }
}

int MiddleAsembler::binOpNeq(int l, int r)
{
    auto oneExpr = dynamic_cast<fold*>(expressions[l]);
    auto twoExpr = dynamic_cast<fold*>(expressions[r]);
    auto oneRegExpr = dynamic_cast<RegExpr*>(expressions[l]);
    auto twoRegExpr = dynamic_cast<RegExpr*>(expressions[r]);

    if(oneRegExpr)
    {
        if (twoRegExpr)
        {
            FOUT.Write("sne " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + *twoRegExpr->getRegister());
            twoRegExpr->releaseRegister();
            return l;
        }
        else
        if(twoExpr)
        {
            FOUT.Write("sne " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + std::to_string(twoExpr->getValue()));
            return l;
        }
    }
    else
    if(oneExpr)
    {
        if(twoRegExpr)
        {   
            auto reg = SYMBOL_TABLE.requestRegister();
            FOUT.Write("sne " + *twoRegExpr->getRegister() + ", " + *twoRegExpr->getRegister() + ", " + std::to_string(oneExpr->getValue()));
            return r;
        }
        else
        if(twoExpr)
        {
            oneExpr->setValue(oneExpr->getValue() != twoExpr->getValue());
            return l;
        }
    }
}

int MiddleAsembler::binOpGteq(int l, int r)
{
    auto oneExpr = dynamic_cast<fold*>(expressions[l]);
    auto twoExpr = dynamic_cast<fold*>(expressions[r]);
    auto oneRegExpr = dynamic_cast<RegExpr*>(expressions[l]);
    auto twoRegExpr = dynamic_cast<RegExpr*>(expressions[r]);

    if(oneRegExpr)
    {
        if (twoRegExpr)
        {
            FOUT.Write("sge " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + *twoRegExpr->getRegister());
            twoRegExpr->releaseRegister();
            return l;
        }
        else
        if(twoExpr)
        {
            FOUT.Write("sge " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + std::to_string(twoExpr->getValue()));
            return l;
        }
    }
    else
    if(oneExpr)
    {
        if(twoRegExpr)
        {   
            auto reg = SYMBOL_TABLE.requestRegister();
            FOUT.Write("li " + *reg + ", " + std::to_string(oneExpr->getValue()));
            FOUT.Write("sge " + *twoRegExpr->getRegister() + ", " + *reg + ", " + *twoRegExpr->getRegister());
            return r;
        }
        else
        if(twoExpr)
        {
            oneExpr->setValue(oneExpr->getValue() >= twoExpr->getValue());
            return l;
        }
    }
}

int MiddleAsembler::binOpGt(int l, int r)
{
    auto oneExpr = dynamic_cast<fold*>(expressions[l]);
    auto twoExpr = dynamic_cast<fold*>(expressions[r]);
    auto oneRegExpr = dynamic_cast<RegExpr*>(expressions[l]);
    auto twoRegExpr = dynamic_cast<RegExpr*>(expressions[r]);

    if(oneRegExpr)
    {
        if (twoRegExpr)
        {
            FOUT.Write("sgt " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + *twoRegExpr->getRegister());
            twoRegExpr->releaseRegister();
            return l;
        }
        else
        if(twoExpr)
        {
            FOUT.Write("sgt " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + std::to_string(twoExpr->getValue()));
            return l;
        }
    }
    else
    if(oneExpr)
    {
        if(twoRegExpr)
        {   
            auto reg = SYMBOL_TABLE.requestRegister();
            FOUT.Write("li " + *reg + ", " + std::to_string(oneExpr->getValue()));
            FOUT.Write("sgt " + *twoRegExpr->getRegister() + ", " + *reg + ", " + *twoRegExpr->getRegister());
            return r;
        }
        else
        if(twoExpr)
        {
            oneExpr->setValue(oneExpr->getValue() > twoExpr->getValue());
            return l;
        }
    }
}

int MiddleAsembler::binOpLteq(int l, int r)
{
    auto oneExpr = dynamic_cast<fold*>(expressions[l]);
    auto twoExpr = dynamic_cast<fold*>(expressions[r]);
    auto oneRegExpr = dynamic_cast<RegExpr*>(expressions[l]);
    auto twoRegExpr = dynamic_cast<RegExpr*>(expressions[r]);

    if(oneRegExpr)
    {
        if (twoRegExpr)
        {
            FOUT.Write("sle " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + *twoRegExpr->getRegister());
            twoRegExpr->releaseRegister();
            return l;
        }
        else
        if(twoExpr)
        {
            FOUT.Write("sle " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + std::to_string(twoExpr->getValue()));
            return l;
        }
    }
    else
    if(oneExpr)
    {
        if(twoRegExpr)
        {   
            auto reg = SYMBOL_TABLE.requestRegister();
            FOUT.Write("li " + *reg + ", " + std::to_string(oneExpr->getValue()));
            FOUT.Write("sle " + *twoRegExpr->getRegister() + ", " + *reg + ", " + *twoRegExpr->getRegister());
            return r;
        }
        else
        if(twoExpr)
        {
            oneExpr->setValue(oneExpr->getValue() <= twoExpr->getValue());
            return l;
        }
    }
}

int MiddleAsembler::binOpLt(int l , int r )
{
    auto oneExpr = dynamic_cast<fold*>(expressions[l]);
    auto twoExpr = dynamic_cast<fold*>(expressions[r]);
    auto oneRegExpr = dynamic_cast<RegExpr*>(expressions[l]);
    auto twoRegExpr = dynamic_cast<RegExpr*>(expressions[r]);

    if(oneRegExpr)
    {
        if (twoRegExpr)
        {
            FOUT.Write("slt " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + *twoRegExpr->getRegister());
            twoRegExpr->releaseRegister();
            return l;
        }
        else
        if(twoExpr)
        {
            FOUT.Write("slti " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + std::to_string(twoExpr->getValue()));
            return l;
        }
    }
    else
    if(oneExpr)
    {
        if(twoRegExpr)
        {   
            auto reg = SYMBOL_TABLE.requestRegister();
            FOUT.Write("li " + *reg + ", " + std::to_string(oneExpr->getValue()));
            FOUT.Write("slt " + *twoRegExpr->getRegister() + ", " + *reg + ", " + *twoRegExpr->getRegister());
            return r;
        }
        else
        if(twoExpr)
        {
            oneExpr->setValue(oneExpr->getValue() < twoExpr->getValue());
            return l;
        }
    }
}

int MiddleAsembler::binOpSub(int l, int r)
{
    auto oneExpr = dynamic_cast<fold*>(expressions[l]);
    auto twoExpr = dynamic_cast<fold*>(expressions[r]);
    auto oneRegExpr = dynamic_cast<RegExpr*>(expressions[l]);
    auto twoRegExpr = dynamic_cast<RegExpr*>(expressions[r]);

    if(oneRegExpr)
    {
        if (twoRegExpr)
        {
            FOUT.Write("sub " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + *twoRegExpr->getRegister());
            twoRegExpr->releaseRegister();
            return l;
        }
        else
        if(twoExpr)
        {
            FOUT.Write("sub " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + std::to_string(twoExpr->getValue()));
            return l;
        }
    }
    else
    if(oneExpr)
    {
        if(twoRegExpr)
        {   
            auto reg = SYMBOL_TABLE.requestRegister();
            FOUT.Write("li " + *reg + ", " + std::to_string(oneExpr->getValue()));
            FOUT.Write("sub " + *twoRegExpr->getRegister() + ", " + *reg + ", " + *twoRegExpr->getRegister());
            return r;
        }
        else
        if(twoExpr)
        {
            oneExpr->setValue(oneExpr->getValue() - twoExpr->getValue());
            return l;
        }
    }
}

int MiddleAsembler::binOpMult(int l, int r)
{
    auto oneExpr = dynamic_cast<fold*>(expressions[l]);
    auto twoExpr = dynamic_cast<fold*>(expressions[r]);
    auto oneRegExpr = dynamic_cast<RegExpr*>(expressions[l]);
    auto twoRegExpr = dynamic_cast<RegExpr*>(expressions[r]);

    if(oneRegExpr)
    {
        if (twoRegExpr)
        {
            FOUT.Write("mul " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + *twoRegExpr->getRegister());

            twoRegExpr->releaseRegister();
            return l;
        }
        else
        if(twoExpr)
        {
            auto reg = SYMBOL_TABLE.requestRegister();
            FOUT.Write("mul " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + std::to_string(twoExpr->getValue()));
            return l;
        }
    }
    else
    if(oneExpr)
    {
        if(twoRegExpr)
        {   
            FOUT.Write("mul " + *twoRegExpr->getRegister() + ", " + *twoRegExpr->getRegister() + ", " + std::to_string(oneExpr->getValue()));
            return r;
        }
        else
        if(twoExpr)
        {
            oneExpr->setValue(oneExpr->getValue() * twoExpr->getValue());
            return l;
        }
    }
}

int MiddleAsembler::binOpDiv(int l, int r)
{
    auto oneExpr = dynamic_cast<fold*>(expressions[l]);
    auto twoExpr = dynamic_cast<fold*>(expressions[r]);
    auto oneRegExpr = dynamic_cast<RegExpr*>(expressions[l]);
    auto twoRegExpr = dynamic_cast<RegExpr*>(expressions[r]);

    if(oneRegExpr)
    {
        if (twoRegExpr)
        {
            FOUT.Write("div " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + *twoRegExpr->getRegister());
            twoRegExpr->releaseRegister();
            return l;
        }
        else
        if(twoExpr)
        {
            FOUT.Write("div " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + std::to_string(twoExpr->getValue()));
            return l;
        }
    }
    else
    if(oneExpr)
    {
        if(twoRegExpr)
        {   
            auto reg = SYMBOL_TABLE.requestRegister();
    	    std::cout << "li " << *reg << ", " << oneExpr << std::endl;
            FOUT.Write("div " + *twoRegExpr->getRegister() + ", " + *reg + ", " + *twoRegExpr->getRegister());
            return r;
        }
        else
        if(twoExpr)
        {
            oneExpr->setValue(oneExpr->getValue() / twoExpr->getValue());
            return l;
        }
    }
}

int MiddleAsembler::binOpMod(int l, int r)
{
    auto oneExpr = dynamic_cast<fold*>(expressions[l]);
    auto twoExpr = dynamic_cast<fold*>(expressions[r]);
    auto oneRegExpr = dynamic_cast<RegExpr*>(expressions[l]);
    auto twoRegExpr = dynamic_cast<RegExpr*>(expressions[r]);

    if(oneRegExpr)
    {
        if (twoRegExpr)
        {
            FOUT.Write("rem " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + *twoRegExpr->getRegister());
            twoRegExpr->releaseRegister();
            return l;
        }
        else
        if(twoExpr)
        {
            FOUT.Write("rem " + *oneRegExpr->getRegister() + ", " + *oneRegExpr->getRegister() + ", " + std::to_string(twoExpr->getValue()));
            return l;
        }
    }
    else
    if(oneExpr)
    {
        if(twoRegExpr)
        {   
            auto reg = SYMBOL_TABLE.requestRegister();
    	std::cout << "li " << *reg << ", " << oneExpr << std::endl;
            FOUT.Write("rem " + *twoRegExpr->getRegister() + ", " + *reg + ", " + *twoRegExpr->getRegister());
            return r;
        }
        else
        if(twoExpr)
        {
            oneExpr->setValue(oneExpr->getValue() % twoExpr->getValue());
            return l;
        }
    }
}

int MiddleAsembler::unOp(int i, int (MiddleAsembler::*cb)(int))
{
    if (expressions[i]->getType() == SYMBOL_TABLE.getSimpleType("string"))
    {
        return (this->*cb)(i);
    }
    if (auto e = dynamic_cast<oneValxpr*>(expressions[i]))
    {
        i = loadReg(e);
    }
    return (this->*cb)(i);
}

int MiddleAsembler::unOpNeg(int i)
{
    if (auto e = dynamic_cast<fold*>(expressions[i]))
    {
        e->setValue(e->getValue() * -1);
        return i;
    }
    else
    if (auto e = dynamic_cast<RegExpr*>(expressions[i]))
    {
        auto reg = SYMBOL_TABLE.requestRegister();
        FOUT.Write("neg " + *e->getRegister() + ", " + *e->getRegister());
        return i;
    }
}
int MiddleAsembler::unOpNot(int i)
{
    if (auto e = dynamic_cast<fold*>(expressions[i]))
    {
        switch(e->getValue())
        {
        case 0:
            e->setValue(1);
            break;
        default:
            e->setValue(0);
        }
        e->setType(SYMBOL_TABLE.getSimpleType("boolean"));
        return i;
    }
    else

    if (auto e = dynamic_cast<RegExpr*>(expressions[i]))
    {
        auto reg = SYMBOL_TABLE.requestRegister();
        auto reg2 = SYMBOL_TABLE.requestRegister();
        FOUT.Write("slti " + *reg + ", " + *e->getRegister() + ", 1");
        FOUT.Write("slti " + *reg2 + ", " + *e->getRegister() + ", 0");
        FOUT.Write("xor " + *e->getRegister() + ", " + *reg + ", " + *reg2);

        e->setType(SYMBOL_TABLE.getSimpleType("boolean"));

        return i;
    }
}


int MiddleAsembler::unOpDecr(int i)
{
    if (dynamic_cast<BooleanType*>(expressions[i]->getType()))
    {
        return unOpNot(i);
    }

    if (auto e = dynamic_cast<fold*>(expressions[i]))
    {
        e->setValue(e->getValue() - 1);
        return i;
    }
    else
    if (auto e = dynamic_cast<RegExpr*>(expressions[i]))
    {
        FOUT.Write("addi " + *e->getRegister() + ", " + *e->getRegister() + ", -1");

        return i;
    }
}

int MiddleAsembler::unOpIncr(int i)
{
    if (dynamic_cast<BooleanType*>(expressions[i]->getType()))
    {
        return unOpNot(i);
    }

    if (auto e = dynamic_cast<fold*>(expressions[i]))
    {
        e->setValue(e->getValue() + 1);
        return i;
    }
    else
    if (auto e = dynamic_cast<RegExpr*>(expressions[i]))
    {
        FOUT.Write("addi " + *e->getRegister() + ", " + *e->getRegister() + ", 1");
        return i;
    }
}

int MiddleAsembler::buildArray(int le, int re, int t)
{
    auto lfe = dynamic_cast<fold*>(expressions[le]);
    auto rfe = dynamic_cast<fold*>(expressions[re]);
    auto lowerBound = lfe->getValue();
    auto size = rfe->getValue() - lfe->getValue() +1;

    auto tt = SYMBOL_TABLE.getConstType(t);  
    auto newType = new ArrayType(size,tt,lowerBound);

    return SYMBOL_TABLE.addConstType(newType);
}

int MiddleAsembler::preWhile()
{
    static int num = 0;
    FOUT.Write("WB" + std::to_string(num) + ":");
    return num++;
}

void MiddleAsembler::startWhile(int num, int i)
{
    if (auto fe = dynamic_cast<fold*>(expressions[i]))
    {
        auto reg = SYMBOL_TABLE.requestRegister();
        FOUT.Write("li " + *reg + ", " + std::to_string(fe->getValue()));
        FOUT.Write("beq " + *reg + ", $zero, WE" + std::to_string(num));
    }
    else
    if (auto le = dynamic_cast<oneValxpr*>(expressions[i]))
    {
        auto reg = SYMBOL_TABLE.requestRegister();
        FOUT.Write("lw " + *reg + ", " + std::to_string(le->getOffset()) + "(" + *le->getRegister() + ")");
        FOUT.Write("beq " + *reg + ", $zero, WE" + std::to_string(num));
    }
    else
    if (auto re = dynamic_cast<RegExpr*>(expressions[i]))
    {
        FOUT.Write("beq " + *re->getRegister() + ", $zero, WE" + std::to_string(num));
        re->releaseRegister();
    }
}

void MiddleAsembler::endWhile(int i)
{
    FOUT.Write("j WB" + std::to_string(i));
    FOUT.Write("WE" + std::to_string(i) + ":");
}

int MiddleAsembler::startIf(int i,bool isElseif)
{
    static int num = 0;
    std::shared_ptr<std::string> reg;
    if (auto fe = dynamic_cast<fold*>(expressions[i]))
    {
        reg = SYMBOL_TABLE.requestRegister();
        FOUT.Write("li " + *reg + ", " + std::to_string(fe->getValue()));
    }
    else
    if (auto le = dynamic_cast<oneValxpr*>(expressions[i]))
    {
        reg = SYMBOL_TABLE.requestRegister();
        FOUT.Write("lw " + *reg + ", " + std::to_string(le->getOffset()) + "(" + *le->getRegister() + ")");
    }
    else
    if (auto re = dynamic_cast<RegExpr*>(expressions[i]))
    {
        reg = re->getRegister();
        re->releaseRegister();
    }
    FOUT.Write("beq " + *reg + ", $zero, ELSE" + std::to_string(num));
    if (!isElseif)
    {
        endifNumberStack.push_back(endifNumber);
        endifNumber++;
    }
    return num++;
}

void MiddleAsembler::endIf()
{
    FOUT.Write("ENDIF" + std::to_string(endifNumberStack.back()) + ":");
    endifNumberStack.pop_back();
}

void MiddleAsembler::doElse(int i)
{
    FOUT.Write("j ENDIF" + std::to_string(endifNumberStack.back()));
    FOUT.Write("ELSE" + std::to_string(i) + ":");
}

int MiddleAsembler::startRepeat()
{
    static unsigned num = 0U;
    FOUT.Write("REPEAT" + std::to_string(num) + ":");
    return num++;
}

void MiddleAsembler::endRepeat(int labelNum, int exNum)
{

    if (auto fe = dynamic_cast<fold*>(expressions[exNum]))
    {
        auto reg = SYMBOL_TABLE.requestRegister();
        FOUT.Write("li " + *reg + ", " + std::to_string(fe->getValue()));
        FOUT.Write("beq " + *reg + ", $zero, REPEAT" + std::to_string(labelNum));
    }
    else
    if (auto le = dynamic_cast<oneValxpr*>(expressions[exNum]))
    {
        auto reg = SYMBOL_TABLE.requestRegister();
        FOUT.Write("lw " + *reg + ", " + std::to_string(le->getOffset()) + "(" + *le->getRegister() + ")");
        FOUT.Write("beq " + *reg + ", $zero, REPEAT" + std::to_string(labelNum));
    }
    else
    if (auto re = dynamic_cast<RegExpr*>(expressions[exNum]))
    {
        FOUT.Write("beq " + *re->getRegister() + ", $zero, REPEAT" + std::to_string(labelNum));
        re->releaseRegister();
    }
}

int MiddleAsembler::startFor(char* id, int exNum)
{
    SYMBOL_TABLE.enterScope();
    
    auto v = SYMBOL_TABLE.lookupVar(id);
    if (v.type == nullptr)
    {
        const auto t = expressions[exNum]->getType();
        SYMBOL_TABLE.storeVar(id, t, "$fp", true);
        forNewVar.push_back(true);
        FOUT.Write("addi $sp, $sp, -4");
    }
    else{
        forNewVar.push_back(false);
    }
    static unsigned num = 0U;

    auto e = assignExprToLval(getLval(id), exNum);
    FOUT.Write("FOR_BEGIN" + std::to_string(num) + ":");
    forStack.push_back(num);
    num++;

    return e;
}

int MiddleAsembler::compareFor(int l, int r, bool ascending)
{
    auto oldl = l;
    if (auto e = dynamic_cast<oneValxpr*>(expressions[l]))
    {
        l = loadReg(e);
    }
    auto lexpr = dynamic_cast<RegExpr*>(expressions[l]);

    std::string compOp = (ascending ? "sle " : "sge ");

    if(auto frexpr = dynamic_cast<fold*>(expressions[r]))
    {
        FOUT.Write(compOp + *lexpr->getRegister() + ", " + *lexpr->getRegister() + ", " + std::to_string(frexpr->getValue()));
    }
    if(auto rrexpr = dynamic_cast<oneValxpr*>(expressions[r]))
    {
        auto reg = SYMBOL_TABLE.requestRegister();
        FOUT.Write("lw " + *reg + ", " + std::to_string(rrexpr->getOffset()) + "(" + *rrexpr->getRegister() + ")");
        FOUT.Write(compOp + *lexpr->getRegister() + ", " + *lexpr->getRegister() + ", " + *reg);
    }
    FOUT.Write("beq " + *lexpr->getRegister() + ", $zero, FOR_END" + std::to_string(forStack.back()));
    lexpr->releaseRegister();
    forAscendStack.push_back(ascending);
    return oldl;

}

void MiddleAsembler::endFor(int i)
{
    auto expr = dynamic_cast<oneValxpr*>(expressions[i]);

    auto reg = SYMBOL_TABLE.requestRegister();
    auto toAdd = (forAscendStack.back() ? 1 : -1);
    FOUT.Write("lw " + *reg + ", " + std::to_string(expr->getOffset()) + "(" + *expr->getRegister() + ")");
    FOUT.Write("addi " + *reg + ", " + *reg + ", " + std::to_string(toAdd));
    FOUT.Write("sw " + *reg + ", " + std::to_string(expr->getOffset()) + "(" + *expr->getRegister() + ")");
    FOUT.Write("j FOR_BEGIN" + std::to_string(forStack.back()));
    FOUT.Write("FOR_END" + std::to_string(forStack.back()) + ":");
    if(forNewVar.back())
    {
        FOUT.Write("addi $sp, $sp, 4");
        SYMBOL_TABLE.changeFrameOffsetBy(4);
    }
    forNewVar.pop_back();

    forAscendStack.pop_back();
    forStack.pop_back();
    SYMBOL_TABLE.leaveScope();
}

void MiddleAsembler::doProcedurePrologue(std::string name)
{
    FOUT.Write(name + "_p:");
}

void MiddleAsembler::doProcedureEpilogue()
{
    FOUT.Write("jr $ra");
}

void MiddleAsembler::precallProcedure(std::string name)
{
    FOUT.Write("jal " + name + "_p");
}
void ignoreFunction(){
    FOUT.WriteFoot();
    exit(0);
} 
