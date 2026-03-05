#include <array>
#include <iostream>

int main() {
  std::array<int, 4> arr = {11, 23, 31, 45};
  for (int i : arr) {
    std::cout << i << std::endl;
  }
  return 0;
}