#include <iostream>

class A {
public:
  A() = default;
  A(const A &obj) = delete;
  // A(const A &obj);
  int getMData() const;
  void setMData(int);
  A &operator=(const A &rhs); // compiler could've generated an assignment
                              // operator though

private:
  int mdata;
};
// A::A(const A &obj) { mdata = obj.mdata; }
int A::getMData() const { return mdata; }
void A::setMData(int data) { mdata = data; }
A &A::operator=(const A &rhs) {
  if (this == &rhs)
    return *this; // when your class has dynamically allocated memory or other
                  // resources, it’s paramount to take self - assignment into
                  // account
  mdata =
      rhs.mdata; // Even though mdata is private, this works because operator=
                 // is a member function of the same class — members have access
                 // to private fields of any instance of their own class.
  return *this;
  /*
    ^^ When you return *this from a function declared to return A&,
    C++ automatically binds the returned object as a reference.
    It's essentially the same as this pattern:
      A obj;
      A &ref = obj;
  */
}

int main() {
  A obj1, obj2;
  obj1.setMData(12);
  obj2.setMData(33);
  std::cout << "obj1: " << obj1.getMData() << ", obj2: " << obj2.getMData()
            << std::endl;
  obj1 = obj2;
  /*
    ^^ This is just a statement. Once it's done executing, the result of the
    expression (the returned A&) has nowhere to go — no variable is waiting to
    receive it. So it simply vanishes, just like this:
      5 + 3; // result is 8, but nobody stores it, so it's gone
      getMData(); // returns an int, but if you don't
                  // store it, it's discarded The same principle applies here —
                  // the returned reference is the result of an expression,
                  // and if you don't capture it, it's lost.
  */
  std::cout << "obj1: " << obj1.getMData() << ", obj2: " << obj2.getMData()
            << std::endl;
  obj2.setMData(40);
  std::cout << "obj1: " << obj1.getMData() << ", obj2: " << obj2.getMData()
            << std::endl;
  A &obj3 = (obj1 = obj2);
  std::cout << "obj1: " << obj1.getMData() << ", obj2: " << obj2.getMData()
            << ", obj3: " << obj3.getMData() << std::endl;
  obj3.setMData(57);
  std::cout << "obj1: " << obj1.getMData() << ", obj2: " << obj2.getMData()
            << ", obj3: " << obj3.getMData() << std::endl;
  A &obj4 = obj1 = obj2;
  std::cout << "obj1: " << obj1.getMData() << ", obj2: " << obj2.getMData()
            << ", obj3: " << obj3.getMData() << ", obj4: " << obj4.getMData()
            << std::endl;
  obj4.setMData(82);
  std::cout << "obj1: " << obj1.getMData() << ", obj2: " << obj2.getMData()
            << ", obj3: " << obj3.getMData() << ", obj4: " << obj4.getMData()
            << std::endl;
  return 0;
}