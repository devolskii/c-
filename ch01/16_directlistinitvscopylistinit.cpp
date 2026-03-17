/*
  There are two types of initialization that use braced initializer lists :
    ➤➤ Copy list initialization.T obj = {arg1, arg2, ...};
    ➤➤ Direct list initialization.T obj{arg1, arg2, ...};
  In combination with auto type deduction, there is an important difference
  between copy - and direct list initialization introduced with C++ 17. Starting
  with C++ 17, you have the following results :
*/

int main() {
  // Copy list initialization
  auto a = {11};     // initializer_list<int>
  auto b = {11, 22}; // initializer_list<int>
  // Direct list initialization
  auto c{11};     // int
  auto d{11, 22}; // Error, too many elements.
  /*
    Note that for copy list initialization, all the elements in the braced
    initializer must be of the same type. For example, the following does not
    compile:
  */
  auto b = {11, 22.33}; // Compilation error
}