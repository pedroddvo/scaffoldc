#pragma once
#include "../common.h"

struct Span {
  uint32_t start;
  uint32_t offset;

  Span() : start(0), offset(0) {}
  Span(uint32_t start, uint32_t offset) : start(start), offset(offset) {}
};

struct Token {
  enum {
    Error, Eof, Sof,

    Number,
    Operator,
  } kind;
  
  Span span;

  Token() : kind(Error), span() {}
};