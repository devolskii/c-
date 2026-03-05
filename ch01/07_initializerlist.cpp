#include <initializer_list>
#include <iostream>
#include <vector>

int makeSum(std::initializer_list<int>
                list) { // allows variable length  list, std::array requires
                        // length to be mentioned
  int total = 0;
  for (int i : list) {
    total += i;
  }
  return total;
}

int makeSum1(std::vector<int> v) { // what's the point of initializer_list when
                                   // you can use vector instead anyway? because
                                   // v becomes non-fixed size but list doesn't?
  int total = 0;
  for (int i : v) {
    total += i;
  }
  return total;
}

int main() {
  std::cout << makeSum({12, 13, 14, 15}) << std::endl;
  std::cout << makeSum1({12, 13, 14, 15});
  return 0;
}