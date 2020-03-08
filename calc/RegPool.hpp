#pragma once

#include "Global.hpp"

class RegPool{
public:
  RegPool();
  void init();
  std::string GetReg(); 
  void ReleaseReg(std::string reg);
  std::vector<std::string> registers{"$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8"};
};

