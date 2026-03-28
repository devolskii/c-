class A {
  int ma = 22;

public:
  A() = default;
  int get_ma();
};

class B {
  int mr = 5;
  int mc = 5;
  A **mobj = nullptr;
  void friend print(B);
  void friend swap(B &, B &) noexcept;

public:
  B(int r, int c);
  ~B();
  B &operator=(B &);
};
