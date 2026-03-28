#include "02_header.h"
#include <iostream>
#include <utility>

int A::get_ma() { return ma; }

B::B(int r, int c) : mr(r), mc(c) {
  mobj = new A *[r]; // while row, new A*
  for (int i = 0; i < c; i++) {
    mobj[i] = new A[c]; // while columns, new A
  }
}

B::~B() {
  for (int i = 0; i < mc; i++)
    delete[] mobj[i];
  delete[] mobj;
  mobj = nullptr;
} // noexcept by default

void print(B temp) {
  std::cout << temp.mobj[0][0].get_ma();
} // temp.mobj deallocated when function exits

int main() {
  B obb(6, 7);
  print(obb); // obb.mobj becomes dangling pointer
  B obb1(3, 5);
  obb = obb1; // causes orphan memory for older obb.mobj, hence memory leak
  // hence perform deep copy
  // 1. Define assignment operator within class
  // 1.1 Free up old memory of obb.mobj
  // 1.2 Allocate new memory for obb.mobj (might cause error if unavailability
  // of memory)
  // 1.3 Perform deep copy of obb1.mobj values to obb.mobj
  // Solution?
  // copy and swap idiom
  return 0;
}

B &B::operator=(B &rhs) {
  if (this == &rhs) { // checking for self assignment
    return *this;
  }
  B temp(rhs);       // copy
  swap(*this, temp); // swap
  return *this;
}

void swap(B &lhs, B &rhs) noexcept {
  using std::swap;
  swap(lhs.mr, rhs.mr);
  swap(lhs.mc, rhs.mc);
  swap(lhs.mobj, rhs.mobj);
}