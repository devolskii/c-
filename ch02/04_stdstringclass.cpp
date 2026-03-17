#include <iostream>
#include <ostream>
#include <string>
using namespace std::string_literals;
/*
  There are no memory leaks even though strings
  are allocated and resized on a few places. All of these string objects are
  created as stack variables.While the string class certainly has a bunch of
  allocating and resizing to do, the string destructors clean up this memory
  when string objects go out of scope.
*/

int main() {
  std::string A = "abc";
  std::string B = "acb";
  std::cout << (A > B) << std::endl;
  auto string1 = "Hello World";  // string1 is a const char*
  auto string2 = "Hello World"s; // string2 is an std::string
  /*
    The standard user - defined literal “s” requires a using namespace
    std::string_literals; or using namespace std;.
  */
  return 0;
}