#include "./tokenizer.h"

bool Tokenizer::eof() {
  return src_offset >= src.length();
}

char Tokenizer::next() {
  if (eof()) return 0;

  return src[src_offset++];
}

char Tokenizer::peek() {
  if (eof()) return 0;

  return src[src_offset];
}

void Tokenizer::skipws() {
  while (isspace(peek())) next();
}

Token Tokenizer::token() {
  skipws();
  char c = peek();
  
  Token tok = Token();
  tok.span.start = src_offset;

  if (isdigit(c)) {
    while (isdigit(peek())) next();
    if (peek() == '.') {
      next();
      if (!isdigit(peek())) {
        tok.span.offset = src_offset;
        trace.error("Expected a digit 0 - 9", tok.span);
        goto error;   
      }
      while (isdigit(peek())) next();
    }
    tok.span.offset = src_offset - tok.span.start;
    tok.kind = Token::Number;
  } else {
    bool op = false;
    while (!op) {
      switch (peek()) {
      case '+':
      case '-':
      case '*':
      case '/':
        next();
        tok.span.offset++;
        break;
      default:
        op = true;
        break;
      }
    }

    if (tok.span.offset) {
      tok.kind = Token::Operator;
      return tok;
    }


    while (!eof() && !isspace(peek())) {
      next();
    }
    tok.span.offset = src_offset - tok.span.start;
    trace.error("Bad character(s)!", tok.span);
    goto error;
  }
  

  return tok;

error:
  tok.kind = Token::Error;
  return tok;
}