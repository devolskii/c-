#include <array>
#include <iostream>

int main() {
  std::array<int, 3> arr = {0, 1, 2};
  std::cout << arr.size() << arr[0] << std::size(arr);
  return 0;
}