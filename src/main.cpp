#include <iostream>
#include "./lang/tokenizer.h"

int main() {
  std::string src = "12345$$$";
  Tokenizer t(src);
 
  t.token();
  t.token();
  if (t.trace.errored()) {
    t.trace.report(src);
  }
  
  
  return 0;
}