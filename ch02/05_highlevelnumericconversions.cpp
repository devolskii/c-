#include <cstddef>
#include <iostream>
#include <string>

int main() {
  long double a = 3.14L;
  std::string s = std::to_string(a);
  const std::string toParse = " 123USD";

  size_t index = 0;
  int value = stoi(toParse, &index);
  std::cout << "Parsed value: " << value << std::endl;
  std::cout << "Second non-parsed character: '" << toParse[index + 1] << "'"
            << std::endl;
  return 0;
}