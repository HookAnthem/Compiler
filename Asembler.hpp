#pragma once 
#include "Global.hpp"

class Asembler{
public:
    Asembler();
    Asembler(std::string id);
    ~Asembler();
    void Write(std::string print);
    void WriteHead();
    void WriteFoot();
    void WriteGlobal();
    void WriteStrings();
    std::ofstream file;
    std::string file_name;
};
