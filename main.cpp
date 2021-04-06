// for test

#include <cstdio>
#include <iostream>

int main() {
  unsigned int a = 2147483649;
  int b = 2147483647;
  int c = a + b;
  std::cout << c << std::endl;
  std::cout << sizeof(c) << std::endl;
  std::cout << sizeof(unsigned int) << std::endl;
  std::cout << sizeof(int) << std::endl;

  printf("%d \n", a);
  printf("%d\n", b);
  printf("%d\n", c);
}