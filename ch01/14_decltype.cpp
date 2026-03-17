#include <iostream>
float foo() { return 5; }
int main() {
  decltype(foo()) x; // the decltype keyword takes an expression as argument,
                     // and computes the type of that expression.
  std::cout << typeid(x).name();
};