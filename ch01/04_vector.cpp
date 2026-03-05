#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<int> v = {0, 1, 2};
  std::cout << v.size() << std::endl;
  v.push_back(3);
  std::cout << v.size() << v[3] << std::endl;
  std::vector<std::string> s{"hello ", "nigga ", "my g "};
  for (std::string i : s) {
    std::cout << i;
  }
  return 0;
}