#include "./error.h"

bool Stacktrace::errored() {
  return error_count > 0;
}

void Stacktrace::error(std::string msg, Span span) {
  if (error_current >= TRACE_SIZE)
    error_current = 0;

  trace[error_current++] = Error(msg, span);
}