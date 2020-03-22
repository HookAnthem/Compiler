#include "Global.hpp"
extern int yyparse();
extern FILE *yyin;
int main(int argc, char *argv[])
{
  //symbol_table.enter_scope();
   SYMBOL_TABLE.init();
   if(argc > 1)
   {
     auto file = std::fopen(argv[1], "r");
     yyin = file;
   }
   FOUT.WriteHead();
      yyparse();
   
   FOUT.WriteFoot();
};
