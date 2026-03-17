#include <cstring>
char *copystring(const char *str) {
  char *result = new char[strlen(str) + 1];
  strcpy(result, str);
  return result;
}
/*
  You should never use sizeof() to try to get the size of a string. It returns
  different sizes depending on how the C - style string is stored.If it is
  stored as a char[], then sizeof() returns the actual memory used by the
  string, including the ‘\0’ character, as in this example :
  */
char text1[] = "abcdef";
size_t s1 = sizeof(text1); // is 7
size_t s2 = strlen(text1); // is 6
/*
  However, if the C - style string is stored as a char *, then sizeof() returns
  the size of a pointer !
*/
const char *text2 = "abcdef";
size_t s3 = sizeof(text2); // is platform-dependent
size_t s4 = strlen(text2); // is 6
//  Here, s3 will be 4 when compiled in 32 - bit mode, and 8 when compiled in 64
//  - bit mode because it is returning the size of a const char *, which is a
//  pointer.
