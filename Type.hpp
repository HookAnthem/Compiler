#pragma once
#include "Global.hpp"
class Type
{
public:
    Type(): siz(0U){};
    Type(unsigned size): siz(size){};
    virtual ~Type(){};
    unsigned size();
    virtual int getPSize() = 0;
private:
    unsigned siz;
};
class ArrayType : public Type
{
public:
    ArrayType():Type(),baseType(nullptr),lowerBound(0){};
    ArrayType(unsigned size, Type* bt,int lb)
        :Type(size),baseType(bt),lowerBound(lb){};
    int getLowerBound();
    int getBaseTypeSize();
    Type* getBaseType();
    int getPBaseSize();
    int getPSize();
    virtual ~ArrayType(){};

private:
    Type* baseType;
    int lowerBound;
};
class Simple : public Type
{
public:
    Simple():Type(4U){};
    Simple(unsigned size):Type(size){};
    virtual ~Simple(){};
    int getPSize();
};
class BooleanType : public Simple
{
public:
    BooleanType():Simple(4U){};
    virtual ~BooleanType(){};
};
class CharacterType : public Simple
{
public:
    CharacterType():Simple(4U){};
    virtual ~CharacterType(){};
};
class IntegerType : public Simple
{
public:
    IntegerType():Simple(4U){};
    virtual ~IntegerType(){};
};
class RecordType : public Type
{
public:
    RecordType():Type(),members(){};
    RecordType(unsigned s):Type(s), members(){};
    std::map<std::string,Type*> getMembers();
    void addMembers(std::map<std::string,Type*> ms); 
    void addMember(std::string s,Type* t);
    int getPSize();
    int size();

private:
    std::map<std::string,Type*> members;
};
class StringType : public Simple
{
public:
    StringType():Simple(4U){};
    virtual ~StringType(){};
};
