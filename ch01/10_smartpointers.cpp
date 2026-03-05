#include <cstddef>
#include <iostream>
#include <memory>

struct Employee {
  int employeeNumber;
  Employee()
      : firstInitial('A'), lastInitial('S'), employeeNumber(counter++),
        salary(20.5) {}
  Employee(char fi, char ls, float sal)
      : firstInitial(fi), lastInitial(ls), employeeNumber(counter++),
        salary(sal) {}

private:
  inline static size_t counter = 1;
  char firstInitial, lastInitial;
  float salary;
};
// size_t Employee::counter = 1;
int main() {
  auto anEmployee = std::make_unique<Employee>();
  auto employees = std::make_unique<Employee>('B', 'C', 20);
  auto employee = std::make_shared<Employee>();
  std::cout << anEmployee->employeeNumber << std::endl
            << employee->employeeNumber << std::endl
            << employees->employeeNumber;
  // std::cout << Employee::counter;
  //  don't
  //  need to deallocate, done automatically
}