#include <iostream>
#include <string>
#include <string_view>

using namespace std::string_view_literals;

/*
  A string_view is basically a drop-in replacement for const string&,
  but without the overhead. It never copies strings! A string_view supports an
  interface similar to std::string. One exception is the absence of c_str(), but
  data() is available. On the other hand, string_view does add the methods
  remove_prefix(size_t) and remove_suffix(size_t), which shrink the string by
  advancing the starting pointer by a given offset, or by moving the end pointer
  backward by a given offset.
*/

std::string_view extractExtension(std::string_view fileName) {
  return fileName.substr(fileName.rfind('.'));
}

int main() {
  std::string str = "Hello";
  std::string_view sv = " world";
  auto result = str + sv.data();

  std::string fileName = R"(c:\temp\my file.ext)";
  std::cout << "C++ string: " << extractExtension(fileName) << std::endl;
  const char *cString = R"(c:\temp\my file.ext)";
  std::cout << "C string: " << extractExtension(cString) << std::endl;
  std::cout << "Literal: " << extractExtension(R"(c:\temp\my file.ext)")
            << std::endl;

  auto a = "A string view"sv;

  return 0;
}