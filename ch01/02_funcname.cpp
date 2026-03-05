#include <iostream>
int func1();
int main() {
  std::cout << func1();
  return 0;
}

int func1() {
  std::cout << "Inside Function: " << __func__ << std::endl;
  return 1;
}