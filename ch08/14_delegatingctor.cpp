/*
  Delegating constructors allow constructors to call another constructor from
  the same class. However, this call cannot be placed in the constructor body;
  it must be in the ctor-initializer and it must be the only member-initializer
  in the list.
*/

#include <cstdlib>
#include <string_view>

class A {
public:
  A() = default;
  A(double);
  A(std::string_view);

private:
  double stringtoDouble(std::string_view) const;
  double mvalue;
};

A::A(double value) : mvalue(value) {}

double A::stringtoDouble(std::string_view sv) const {
  return std::strtod(sv.data(), nullptr);
}

// constructor delegation
A::A(std::string_view str) : A(stringtoDouble(str)) {}