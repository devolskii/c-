#include <iostream>

int main() {
  std::cout << "hello" // here “hello” is a string literal because it is
                       // written as a value, not a variable.
            << std::endl;
  /*
    String literals are actually stored in a read-only part of memory. This
    allows the compiler to optimize memory usage by reusing references to
    equivalent string literals. That is, even if your program uses the string
    literal “hello” 500 times, the compiler is allowed to create just one
    instance of hello in memory. This is called LITERAL POOLING.
  */
  /*
    Generally, the behavior of modifying string literals is undefined. It could,
    for example, cause a crash, or it could keep working with seemingly
    inexplicable side effects, or the modification could silently be ignored, or
    it could just work; it all depends on your compiler.For example, the
    following code exhibits undefined behavior:
  */
  // Next line gives warning:
  // ISO C++11 does not allow conversion from string literal to 'char *'
  char *ptr = "hello"; // Assign the string literal to a variable.
  ptr[1] = 'a';        // Undefined behavior!
  /*
    A much safer way to code is to use a pointer to const characters when
    referring to string literals.The following code contains the same bug,
    but because it assigned the literal to a const char *,
    the compiler catches the attempt to write to read - only memory
    :
  */
  const char *ptr2 = "hello"; // Assign the string literal to a variable.
  ptr2[1] = 'a';              // Error! Attempts to write to read-only memory
  /*
    You can also use a string literal as an initial value for a character array
    (char[]). In this case, the compiler creates an array that is big enough to
    hold the string and copies the string to this array. The compiler does not
    put the literal in read-only memory and does not do any literal pooling.
  */
  char arr[] = "hello"; // Compiler takes care of creating appropriate sized
                        // character array arr.
  arr[1] = 'a';         // The contents can be modified.
  return 0;
}