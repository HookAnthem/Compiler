#include "RecordType.hpp"

int RecordType::offset(std::string value)
{
    return this->offsetTable.at(value);
}
Type * RecordType::lookup(std::string value)
{
    return this->typeTable.at(value);
}
RecordType::RecordType(std::vector<std::string> mem, Type* type)
{
    this->members = mem;
    this->size = 0;
    this->type = type; 
}

