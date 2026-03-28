
class A {
public:
  void foo();
};

class C {};

int D();

class B {
  friend class C;
  friend void A::foo();
  friend int D();
};