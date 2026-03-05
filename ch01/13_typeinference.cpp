#include <iostream>
#include <string>

std::string message = "test";

const std::string &foo() { return message; }

int main() {
  auto f1 = foo(); // Because auto strips away reference and const qualifiers,
                   // f1 is of type string, and thus a copy is made.
  f1[1] = 'o';
  const auto &f2 = foo(); // If you want a const reference, you can explicitly
  // make it a reference and mark it const
  std::cout << message << "\t" << f1 << "\t" << f2 << "\t" << &f1 << "\t" << &f2
            << std::endl;
  message[1] = 'a';
  std::cout << message << '\t' << f2 << std::endl;
  return 0;
}
