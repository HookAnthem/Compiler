#include "Writing.hpp"

void writeFunc(std::string str)
{
   FOUT.Write("li $v0, 4");
   FOUT.Write("la $a0," + str);
   FOUT.Write("syscall");
}
void writeFunc(int num)
{
   FOUT.Write("li $v0 1");
   FOUT.Write("li $a0," + std::to_string(num));
   FOUT.Write("syscall");
}
void writeFunc(char character)
{
   FOUT.Write("li $v0, 11");
   FOUT.Write("li $a0,'" + std::to_string(character) + "'" );
   FOUT.Write("syscall");
}
void writeFuncLoc(Expression * e)
{
   if(e->type == &TYPE_INT || e->type == &TYPE_BOOL)
   {
	FOUT.Write("li $v0,1");
   }
   else if(e->type == &TYPE_CHAR)
   {
	FOUT.Write("li $v0, 11");
   }
   else
   {
   }
}
void writeFunc(Expression * e)
{
   if(e->memLoc.length())
   {
	writeFuncLoc(e);
   }
   else if(e->type == &TYPE_STR)
   {
	std::string temp = std::string("STR" + std::to_string(e->value));
	writeFunc(temp);
   }
   else
   {
	writeFunc(e->value);
   }
}
