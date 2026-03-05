#include <iostream>
#include <memory>
#include <string>

class A {
  std::string ma{"just a"};
  bool mb{};
  int mc{};

public:
  A();
  A(std::string a, bool b, int c);
  ~A();
  std::string geta() const;
  bool getb() const;
  int getc() const;
  void seta(std::string a);
};
A::A(std::string a, bool b, int c) : ma(a), mb(b), mc(c) {
  std::cout << "Parametrized constructor called" << std ::endl;
}
A::A() { std::cout << "Object Created" << std::endl; }
A::~A() { std::cout << "Object being destroyed" << std::endl; }
std::string A::geta() const { return ma; }
bool A::getb() const { return mb; }
int A::getc() const { return mc; }
void A::seta(std::string a) { ma = a; }

int main() {
  A obj1{"BB", true, 5}, obj2;
  std::cout << obj1.geta() << obj1.getb() << obj1.getc() << std::endl;
  std::cout << obj2.geta() << obj2.getb() << obj2.getc() << std::endl;
  auto obj3 = std::make_unique<A>();
  std::cout << obj3->geta() << obj3->getb() << obj3->getc() << std::endl;
  return 0;
}
