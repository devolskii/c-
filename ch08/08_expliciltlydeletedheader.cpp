class A {
public:
  A() = delete;

private:
  int ma;
};

int main() {
  A a; // error
  return 0;
}