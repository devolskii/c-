/*
Objects don’t spring to life all at once; they must be constructed along with
their parents and any objects that are contained within them. C++ defines the
creation order as follows:
1. If the class has a base class, the default constructor of the base class is
executed, unless there is a call to a base class constructor in the
ctor-initializer, in which case that constructor is called instead of the
default constructor.
2. Non-static data members of the class are constructed in the order in which
they are declared.
3. The body of the class’s constructor is executed.
*/
#include <iostream>
using namespace std;
class Something {
public:
  Something() { cout << "2"; }
};
class Base {
public:
  Base(int i) { cout << i << endl; }
};
class Derived : public Base {
public:
  Derived(int i) : Base(i) { cout << "3"; }

private:
  Something mDataMember;
};
int main() {
  Derived myDerived(12);
  return 0;
}