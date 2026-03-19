#include "06_header.h"

/*
  Class A defines only one parameterized custom constructors. However, the
  compiler still generates a standard compiler-generated default constructor due
  to the use of the default keyword.
*/

A::A(int a) { ma = a; }

int main() {
  A obj; // works
  return 0;
}