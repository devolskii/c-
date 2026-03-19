#include "00_header.h"
#include <iostream>

int A::getValue() const { return value; }

void func(const A &obj) {
  std::cout << obj.getValue(); // since obj is const, methods called on obj
                               // inside func must be const methods
}

A::A(int value) {
  this->value = value;
  func(*this);
}