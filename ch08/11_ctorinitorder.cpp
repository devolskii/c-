#include <iostream>

using namespace std;

class Foo {
public:
  Foo(double value);

private:
  double mValue;
};

Foo::Foo(double value) : mValue(value) {
  cout << "Foo::mValue = " << mValue << endl;
}

class MyClass {
public:
  MyClass(double value);

private:
  Foo mFoo;
  double mValue;
};

MyClass::MyClass(double value) : mValue(value), mFoo(mValue) {
  cout << "MyClass::mValue = " << mValue << endl;
}

// The data members are initialized in the order they appear in the
// definition of the class, not the order in the ctor - initializer!

int main() {
  MyClass instance(1.2);
  return 0;
}