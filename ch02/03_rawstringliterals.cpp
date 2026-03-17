#include <iostream>
int main() {
  const char *str = "Hello \"World\""; // using escape sequences
  // With a raw string literal, you can avoid the need to escape the quotes.
  const char *str1 = R"(Hello "World")";
  // similarly, if \n is not used
  const char *str2 = R"(Hello
World)";
  // Escape sequences are ignored in raw string literals
  const char *str3 = R"(Tab can't be \t seen)";

  /*
    Because a raw string literal ends with )" you cannot embed a )" in your
    string using this syntax. For example, the following string is not valid
    because it contains the )" sequence in the middle of the string:
  */
  // const char* str4 = R"(Embedded )" characters)"; // Error!
  /*
    If you need embedded )" characters, you need to use the extended raw string
    literal syntax, which is as follows:
    R"d-char-sequence(r-char-sequence)d-char-sequence"
    The r-char-sequence is the actual raw string. The d-char-sequence is an
    optional delimiter sequence, which should be the same at the beginning and
    at the end of the raw string literal. This delimiter sequence can have at
    most 16 characters. You should choose this delimiter sequence as a sequence
    that will not appear in the middle of your raw string literal.

    The previous example can be rewritten using a unique delimiter sequence as
    follows:
  */
  const char *str4 = R"-(Embedded )" characters)-";
  std::cout << str4;
}