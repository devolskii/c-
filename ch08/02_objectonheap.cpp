#include "00_header.h"
#include <memory>
int main() {
  auto o = std::make_unique<A>(
      10); // clang++ .\01_thispointer.cpp .\02_objectonheap.cpp
  return 0;
}