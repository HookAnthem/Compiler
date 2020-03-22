#include "Asembler.hpp"
Asembler::Asembler()
{
    file_name = "code.asm";
    file.open(file_name);
}
Asembler::Asembler(std::string id)
{
    this->file_name = id;
    file.open(file_name);
}
Asembler::~Asembler()
{
    file.close();
}
void Asembler::Write(std::string print)
{
    std::cout << print << std::endl;
}
void Asembler::WriteHead()
{
    Write(".text");
    Write(".globl main");
    Write("main:");
    Write("j GA");
    WriteGlobal();
}
void Asembler::WriteFoot()
{
    Write("li $v0, 10");
    Write("syscall");
    Write(".data");
    WriteString();
    
}
void Asembler::WriteString()
{
    for(int i = 0; i < STRING_LIST.Size(); ++i)
    {
	Write(std::string("STR" + std::to_string(i) + ": .asciiz" + STRING_LIST.Lookup(i)));
    }
}

void Asembler::WriteGlobal()
{
	Write("GA:");
}
