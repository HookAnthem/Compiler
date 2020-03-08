#include "RegPool.hpp"

RegPool::RegPool()
{
    init();
}

void RegPool::init()
{
    std::vector<std::string> all_registers{"$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8"};
    registers = all_registers; 
}
std::string RegPool::GetReg()
{
    if(registers.size() <= 0)
    {
	init();
    }
    std::string reg = registers.back();
    registers.pop_back();
    return reg;
}
void RegPool::ReleaseReg(std::string reg)
{
    registers.push_back(reg);
}
