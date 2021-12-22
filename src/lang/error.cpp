#include "./error.h"
#include <iostream>

bool Stacktrace::errored() {
  return error_count > 0;
}

void Stacktrace::error(const std::string& msg, Span span) {
  if (error_current >= TRACE_SIZE)
    error_current = 0;

  trace[error_current++] = Error(msg, span);
  error_count++;
}

void Stacktrace::report(std::string src) {
  for (int erri = 0; erri < (error_count >= TRACE_SIZE ? TRACE_SIZE : error_count); erri++) {
    Error err = trace[erri];
    uint32_t line = 0, column = 0;
    uint32_t line_start = 0, line_end = 0;

    for (uint32_t i = 0; i < err.span.start; i++) {
      if (src[i] == '\n') column = 0, line_start = i, line++;
      column++;
    }
    
    for (;;) {
      if (line_end >= src.length() || src[line_end] == '\n') break;
      line_end++;
    } 

    printf("%d:%d: ", line, column);
    printf("error: %s\n", err.msg.c_str());
    printf("\t%s\n", src.substr(line_start, line_end).c_str());
    printf("\t%s%s\n", std::string(err.span.start - line_start, ' ').c_str()
                     , std::string(err.span.offset, '~').c_str());
  }  
}