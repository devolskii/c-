#include <string>
class A {
public:
  A(int);

private:
  int ma;
};

class B {
public:
  B();

private:
  A obj;
};

class C {
public:
  C();
  C(std::string);
  std::string str;
  int i;
};