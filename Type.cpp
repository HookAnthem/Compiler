#include "Type.hpp"
//Default size return
unsigned Type::size()
{
    return siz;
};
//Array Itemes
int ArrayType::getLowerBound()
{
    return lowerBound;
}
int ArrayType::getBaseTypeSize()
{
   return baseType->size();
}
Type* ArrayType::getBaseType()
{
   return baseType;
}
int ArrayType::getPBaseSize()
{
   return baseType->getPSize();
}
int ArrayType::getPSize()
{
    return size() * baseType->getPSize();
}
//Simply Type 
int Simple::getPSize()
{
    return size();
}
//Record Type
void RecordType::addMembers(std::map<std::string,Type*> ms)
{
    for(const auto & item : ms)
    {
        addMember(item.first,item.second);
    }
}
void RecordType::addMember(std::string s,Type* t)
{
    auto f = members.find(s);
    if (f != members.end())
    {
       throw std::runtime_error(
           "id " + s + " already defined in record");
    }
    members[s] = t;
}
int RecordType::getPSize()
{
    unsigned int totSize = 0U;
    for (auto i = members.begin(); i != members.end(); i++)
    {
        totSize += i->second->getPSize();
    }
    return totSize;
}
int RecordType::size()
{
    return members.size();
}
std::map<std::string,Type*> RecordType::getMembers()
{
    return members;
}

