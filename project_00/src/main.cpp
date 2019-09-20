#include <iostream>
#include "array.cpp"

int main()
{
  Array<int, 5> a;

  a[0] = 10;

  std::cout << *a.begin() << std::endl;

  return 0;
}
