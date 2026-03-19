#include "04_header.h"

A::A() { ma = 10; }

A::A(int a) { ma = a; }

void A::setA(int a) { ma = a; }

int main() {
  A obj();      // Empty parentheses interpreted as a function declaration
  obj.setA(19); // Base of member reference is a function; perhaps you meant to
                // call it with no arguments?
  return 0;
}