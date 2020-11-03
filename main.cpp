#include "Global.hpp"

extern int yyparse();
extern FILE *yyin;
int main(int argc, char *argv[])
{
   if(argc > 1)
   {
     auto file = std::fopen(argv[1], "r");
     yyin = file;
   }
   FOUT.WriteHead();
   SYMBOL_TABLE.initialize();
   yyparse();
   FOUT.WriteFoot();
};
