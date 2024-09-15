#include <iostream>
void q2_3() {
  for (auto i = 1; i <= 10; i++) {
    for (auto j = 1; j <= 10; j++) {
      if (i != j) {
        std::cout << '(' << i << ',' << j << ')' << std::endl;
      }
    }
  }

  std::cout << std::endl;

  for (auto i = 1; i <= 100; i++) {
    if (!(i % 7 == 0 && i % 11 == 0))
      std::cout << i << std::endl;
  }
}