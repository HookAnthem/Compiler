#include "Global.hpp"
extern int yyparse();
int main()
{
  //symbol_table.enter_scope();
   FOUT.WriteHead();
   SYMBOL_TABLE.init();
   yyparse();
   FOUT.WriteFoot();
};
