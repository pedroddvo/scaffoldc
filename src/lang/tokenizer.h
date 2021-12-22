#pragma once
#include "../common.h"
#include "./token.h"
#include "./error.h"
#include <string>
#include <vector>

typedef std::vector<Token> TokenStream;

class Tokenizer {
  std::string src;
  uint32_t src_offset;
  
public:
  Stacktrace trace;
  Tokenizer(const std::string& src) : src(src), src_offset(0), trace() {}
  
  bool eof();
  char next();
  char peek();
  
  void skipws();
  
  Token token();
};