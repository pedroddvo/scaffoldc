#include "../common.h"
#include "./token.h"
#include <array>
#include <string>

#define TRACE_SIZE 8

struct Error {
  std::string msg;

  Span span;
  
  Error() : msg(""), span() {}
  Error(const std::string& msg, Span span) : msg(msg), span(span) {}
};

class Stacktrace {
  std::array<Error, TRACE_SIZE> trace;
  uint8_t error_current;
  uint8_t error_count;
  
public:
  Stacktrace() : trace(), error_current(0), error_count(0) {}
  
  bool errored();
  void error(const std::string& msg, Span span);
  void report(std::string src);
};