#include <iostream>
#include <stdexcept>
float divideNumbers(float num, float denom) {
  if (denom == 0) {
    throw std::invalid_argument("denominator cannot be 0");
  }
  return num / denom;
}
int main() {
  try {
    std::cout << divideNumbers(2.5, 0.5) << std::endl;
    std::cout << divideNumbers(2.3, 0) << std::endl;
    std::cout << divideNumbers(4.5, 2.5) << std::endl;
  } catch (const std::invalid_argument &exception) {
    std::cout << "Exception Caught: " << exception.what() << std::endl;
  }
  return 0;
  return 0;
}