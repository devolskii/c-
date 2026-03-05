#include <iostream>
float foo() { return 5; }
int main() {
  decltype(foo()) x;
  std::cout << typeid(x).name();
};