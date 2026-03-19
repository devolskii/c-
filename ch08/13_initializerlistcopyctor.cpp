#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <vector>

class EvenSequence {
public:
  EvenSequence(std::initializer_list<double> args) {
    if (args.size() % 2 != 0) {
      throw std::invalid_argument("initializer_list should "
                                  "contain even number of elements.");
    }
    mSequence.reserve(args.size());
    for (const auto &value : args) {
      mSequence.push_back(value);
    }
  }

  void dump() const {
    for (const auto &value : mSequence) {
      std::cout << value << ", ";
    }
    std::cout << std::endl;
  }

private:
  std::vector<double> mSequence;
};

int main() {
  EvenSequence p1 = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  p1.dump();

  try {
    EvenSequence p2 = {1.0, 2.0, 3.0};
  } catch (const std::invalid_argument &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}