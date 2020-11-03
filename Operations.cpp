#include "Operations.hpp"

void stop()
{
    FOUT.Write("\tli $a0, 0");
    FOUT.Write("\tli $v0, 17");
    FOUT.Write("\tsyscall");
}

