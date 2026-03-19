class A {
public:
  A() = default; // To avoid having to write empty default constructors
                 // manually, C++ supports the concept of explicitly defaulted
                 // constructors.This allows you to write the class definition
                 // without the need to implement the default constructor in the
                 // implementation file.
  A(int);

private:
  int ma;
};