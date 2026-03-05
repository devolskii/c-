#include <iostream>
#include <string>
// const reference prevents unnecessary copying
void func(const std::string &str) {
  std::cout << str << '\t' << &str << std::endl;
}
int main() {
  int x = 5;
  int &refX = x;
  std::cout << &x << '\t' << &refX << std::endl;
  std::string s = "Hello, idiot";
  std::cout << &s << '\t';
  func(s);
  return 0;
}