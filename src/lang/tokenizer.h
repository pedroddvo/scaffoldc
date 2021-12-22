#pragma once
#include "./common.h"
#include "./token.h"
#include "./error.h"
#include <string>
#include <vector>

typedef std::vector<Token> TokenStream;

class Tokenizer {
  Stacktrace trace;
  std::string src;
  uint32_t src_offset;
  
public:
  Tokenizer(std::string src) : src(src) {}
  
  bool eof();
  char next();
  char peek();
  
  void skipws();
  
  Token token();
};