#include <array>
#include <iostream>
#include <iterator>

int main() {
  int stackArray[] = {1, 2, 3, 4, 5};
  int arrSize = std::size(stackArray);
  int *ptr = stackArray;
  std::cout << arrSize << std::endl;
  for (int i = 0; i < arrSize; i++) {
    std::cout << ptr[i];
  }
  return 0;
}