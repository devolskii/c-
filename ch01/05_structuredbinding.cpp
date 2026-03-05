#include <array>
#include <iostream>

int main() {
  std::array<int, 3> arr = {11, 22, 33};
  auto [a, b, c] = arr;
  std::cout << a << b << c << std::endl;
  struct S {
    float fa, fb, fc;
  };
  S var = {1.0, 2.5, 3.7};
  auto [ma, mb, mc] = var;
  std::cout << ma << mb << mc << std::endl;
  return 0;
}