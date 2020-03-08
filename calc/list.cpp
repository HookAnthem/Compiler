#include "list.hpp"

int list::storage(std::string string)
{
    strings.push_back(string);
    return Size() - 1;
}
std::string list::Lookup(int Loc)
{
    return strings[Loc];
}
int list::Size()
{
    return strings.size();
}
