#include <iostream>
class Base {
public:
  /*
    virtual void fun1();
    void fun2(float);
    virtual void fun3(float);
    virtual void fun4(int);*/
  virtual void fun5(double);
  // virtual void fun6(float); //watch
};

class Derived : public Base {
public:
  /*
    void fun1();
    void fun2(int);
    virtual void fun3(int);
    virtual void fun4(int) override;*/
  virtual void fun5(int);
  // virtual void fun6(int) override; //watch error
};
void Derived::fun5(int a) {
  std::cout << a << ": Derived's fun5()" << std::endl;
}
void Base::fun5(double a) { std::cout << a << ": Base's fun5()" << std::endl; }
// void Base::fun6(float a) { std::cout << a << ": Base's fun6()" << std::endl;
// }
/*
void Base::fun1() { std::cout << "Base's fun1()" << std::endl; }
void Base::fun2(float a) { std::cout << a << ": Base's fun2()" << std::endl; }
void Base::fun3(float a) { std::cout << a << ": Base's fun3()" << std::endl; }
void Base::fun4(int a) { std::cout << a << ": Base's fun4()" << std::endl; }*/

// void Derived::fun6(int a) {
//   std::cout << a << ": Derived's fun6()" << std::endl;
// }
/*
void Derived::fun1() { std::cout << "Derived's fun1()" << std::endl; }
void Derived::fun2(int a) {
  std::cout << a << ": Derived's fun2()" << std::endl;
}
void Derived::fun3(int a) {
  std::cout << a << ": Derived's fun3()" << std::endl;
}
void Derived::fun4(int a) {
  std::cout << a << ": Derived's fun4()" << std::endl;
}*/

int main() {
  Derived myDerived;
  Base &ref = myDerived;

  /*myDerived.fun1();
  ref.fun1(); // calls Derived's fun1()

  // no mention of virtual in base class's method
  ref.fun2(1);
  ref.fun2(1.1); // call's base's fun2()
  myDerived.fun2(1);
  myDerived.fun2(1.1); // implicit conversion warning

  ref.fun3(1); // 1: base's fun3()
  ref.fun3(1.1);

  myDerived.fun3(1);
  myDerived.fun3(1.1); // implicit conv. warning

  ref.fun4(1); //
               // ref.fun4(1.1);

  myDerived.fun4(1);
  // myDerived.fun4(1.1);*/

  ref.fun5(1);   // base
  ref.fun5(1.1); // base

  return 0;
}