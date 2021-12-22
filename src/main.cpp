#include <iostream>
#include "./tokenizer.h"

int main() {
  Tokenizer t("123.");

  std::cout << t.token().span.offset;
  
  return 0;
}