#include "09_header.h"
#include <iostream>

// A ctor-initializer allows you to provide initial values for data members as
// they are created, which is more efficient than assigning values to them
// later.

A::A(int a) : ma(a) {}

// no need to ctor initialize str to "" because the string class does it for you

C::C() : i(0) {}

C::C(std::string s) : str(s) {}

// with this implementation, the code does not compile. The compiler does not
// know how to initialize the ma data member of A because it does not have a
// default constructor. B::B() {} //won't compile

// so...
B::B() : obj(0) {}

int main() {
  C o1;
  std::cout << "o1.i = " << o1.i << std::endl;
  std::cout << "o1.str = " << o1.str << "Empty string?" << std::endl;
}

/*
  Some programmers prefer to assign initial values in the body of the
  constructor, even though this might be less efficient. However, several data
  types must be initialized in a ctor-initializer or with an in-class
  initializer. The following table summarizes them:
    =======================================================================
    DATA TYPE                ||             EXPLANATION
    =======================================================================
    const data members       |  You cannot legally assign a value to a const
                             |  variable after it is created. Any value must
                             |  be supplied at the time of creation.
    -----------------------------------------------------------------------
    Reference data members   |  References cannot exist without referring to
                             |  something.
    -----------------------------------------------------------------------
    Object data members      | C++ attempts to initialize member objects
    for which there is       | using a default constructor. If no default
    no default constructor   | constructor exists, it cannot initialize the
                             | object.
    -----------------------------------------------------------------------
    Base classes without     |
    default constructors     |
    -----------------------------------------------------------------------
*/