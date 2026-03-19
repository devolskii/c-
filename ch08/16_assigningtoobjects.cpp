#include <iostream>

class AClass {
public:
  AClass() = default; // if you don't provide a default ctor but only copy ctor,
                      // you won't be able to create an object
  AClass(const AClass &obj) = delete; // if you delete, can't use copy ctor
  int getA() const;
  void setA(int a);

private:
  int ma;
};

// AClass::AClass(const AClass &obj) : ma(obj.ma) {}
int AClass::getA() const { return ma; };
void AClass::setA(int a) { ma = a; };

int main() {
  AClass a;
  a.setA(5);
  std::cout << a.getA() << std::endl;
  // AClass b = a;          // call to deleted copy ctor of AClass, error!
  AClass c;
  c = a; // copy ctor not used, bcz this is assignment not copy. copy is for
         // uninitialized
  /*
    You might be tempted to say that a is “copied” to c. However,
    in the world of C++, “copying” only occurs when an object is being
    initialized. If an object already has a value that is being overwritten, the
    more accurate term is “assigned to.” Note that the facility that C++
    provides for copying is the copy constructor. Because it is a constructor,
    it can only be used for object creation, not for later assignments to the
    object.
  */
  std::cout << c.getA() << std::endl;
  return 0;
}

/*
  The assignment operator as explained in this section is sometimes called
  the copy assignment operator because both the left-hand side and the
  right-hand side object stay alive after the assignment. This distinction is
  made because there is also a move assignment operator in which the right-hand
  side object is destroyed after the assignment for performance reasons. This
  move assignment operator
*/