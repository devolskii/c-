#include "00_header.h"
// clang++ .\01_thispointer.cpp .\03_nodefaultctor.cpp
int main() {
  // the three lines below fail because no default ctor
  A o[3];
  A *o1 = new A[3];
  A o2;
  return 0;
}