#include <iostream>
int main() {

  /*
    If you ignore the return value of new, or if the pointer variable
    goes out of scope, the memory becomes orphaned because you no longer have a
    way to access it. This is also called a memory leak.
  */
  // new int; // MEMORY LEAK
  std::cout << "I have just leaked an int" << std::endl;

  /*
    It is recommended to set a pointer back to nullptr after having freed
    its memory. That way, you do not accidentally use a pointer to memory that
    has already been deallocated.
  */
  int *ptr = new int; // raw pointer
  delete ptr;
  ptr = nullptr;

  /*
    The main advantage of new over malloc() is that new doesn’t just allocate
    memory, it constructs objects!  With free(), the object’s destructor is not
    called. With delete, the destructor is called and the object is properly
    cleaned up.
  */

  /*
    If out of memory, but don't want to throw an error and instead set the
    pointer to nullptr:
  */
  int *a = new (std::nothrow) int;
  delete a;
  a = nullptr;

  // Array
  int *arr = new int[5];
  delete[] arr;
  arr = nullptr;

  return 0;
}