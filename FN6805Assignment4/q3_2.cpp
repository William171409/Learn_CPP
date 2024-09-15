#include <iostream>
long long int_multiply(int a, int b) { return static_cast<long long>(a) * b; }

bool sameParity(int a, int b) { return (a % 2) == (b % 2); }

void q3_2(int a, int b) {
  std::cout << "The result of " << a << '*' << b << ": " << int_multiply(a, b)
            << std::endl;
  std::cout << a << " and " << b << " are" << (sameParity(a, b) ? "" : " not")
            << " same parity" << std::endl;
}
