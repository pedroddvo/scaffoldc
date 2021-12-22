#include <iostream>
#include "./lang/tokenizer.h"

int main() {
  std::string src = "1 ++ 23";
  Tokenizer t(src);
 
  std::cout << t.token().span.offset << std::endl;
  std::cout << t.token().span.offset << std::endl;
  std::cout << t.token().span.offset << std::endl;
  if (t.trace.errored()) {
    t.trace.report(src);
  }
  
  
  return 0;
}