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
  std::cout << a.getA() << std::endl; // will print garbage value
  // AClass b = a;          // call to deleted copy ctor of AClass, error!
  AClass c;
  c.setA(12);
  std::cout << c.getA() << std::endl;
  c = a; // copy ctor not used, bcz this is assignment not copy. copy is for
         // uninitialized
  std::cout << c.getA() << std::endl;
  return 0;
}