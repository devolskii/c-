#include <cstddef> //for size_t
char **allocate(size_t rows, size_t cols) {
  char **board = new char *[rows]; //   In C we would: char **board = (char
                                   //   **)malloc(r * sizeof(char *));
                                   // If error, you can return nullptr instead:
                                   // int *ptr = new(nothrow) int
  for (size_t i = 0; i < rows; i++) {
    board[i] = new char[cols];
  }
  // std::cout << "Done Creating";
  return board;
}

void deallocate(char **board, size_t rows) {
  for (size_t i = 0; i < rows; i++) {
    delete[] board[i];
  }
  delete[] board;
  // std::cout << "Done Deleting";
}

int main() {
  char **abc = allocate(2, 3);
  deallocate(abc, 2);
  return 0;
}