/*
Because destructors cannot take arguments, the language can always automatically
call the destructor for parent classes. The order of destruction is conveniently
the reverse of the order of construction:
1. The body of the class’s destructor is called.
2. Any data members of the class are destroyed in the reverse order of their
construction.
3. The parent class, if any, is destructed.
*/
#include <iostream>
using namespace std;
class Something {
public:
  Something() { cout << "2"; }
  virtual ~Something() { cout << "2"; }
};
class Base {
public:
  Base() { cout << "1"; }
  virtual ~Base() { cout << "1"; }
};
class Derived : public Base {
public:
  Derived() { cout << "3"; }
  virtual ~Derived() { cout << "3"; }

private:
  Something mDataMember;
};

int main() {
  Derived obj;
  return 0;
}