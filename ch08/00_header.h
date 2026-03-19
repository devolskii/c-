class A {
public:
  A(int);
  int getValue() const; // member function doesn't change object, hence const

private:
  int value;
};