class A {
public:
  static void fun(int i); // methods don’t access information about specific
  // objects, so they could be static
  enum class color { red = 1, green, yellow, blue };
  void fun2() const;

private:
  int ma;
  static int sa;
  mutable int counter = 0;
  // make your counter variable mutable, which tells the compiler that it’s okay
  // to change it in a method.const
};

// You don’t repeat the static keyword in front of the method definitions
void A::fun(int i) { sa++; }
int A::sa = 5;
void A::fun2() const { counter++; }

int main() { A obj; }