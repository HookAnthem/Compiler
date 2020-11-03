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
    WriteStrings();
    //Write("GA: .align 2");
}
void Asembler::WriteGlobal()
{
    Write("GA:");
}
void Asembler::WriteStrings()
{
   Write(".asciiz");
   auto sl = SYMBOL_TABLE.getStringList();
   for (auto i = 0U; i < sl.size(); ++i)
   {
	std::string temp = "STR" + std::to_string(i) + ": " + sl[i];
	Write(temp);
   }
   
}
