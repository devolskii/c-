#include <iostream>

void func(char *s) { std::cout << "char* version" << std::endl; }
void func(int a) { std::cout << "int version" << std::endl; }

int main() {
  int *s = nullptr; // As a rule of thumb, every time you declare a pointer
                    // variable, you should immediately initialize it with
                    // either a proper pointer or nullptr. Don’t leave it
                    // uninitialized!
  s = new int;
  *s = 5;
  int *arr = new int[*s];
  arr[0] = 12;
  std::cout << arr[0];
  delete s;
  s = nullptr; // It is recommended to set a pointer back to nullptr after
               // having freed its memory.That way, you do not accidentally use
               // a pointer to memory that has already been deallocated.
  delete[] arr;
  arr = nullptr;
  func(NULL);
  func(nullptr);
  return 0;
}