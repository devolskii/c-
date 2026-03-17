#include <iostream>
int main() {
  char board[3][3] = {{'X', 'O', 'X'}, {'O', 'O', 'O'}, {'X', 'X', 'O'}};
  std::cout << board[1]; // prints from the row to end of the array itself
  return 0;
}