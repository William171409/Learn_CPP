#include <cmath>
#include <iomanip>
#include <iostream>

double f_x(double x);

void q3_1() {
  double step{0.1};
  for (double i = 0; i <= 1; i += step) {
    std::cout << "x=" << std::setw(7) << i << std::setw(7)
              << "f(x)=" << std::setw(7) << f_x(i) << std::endl;
  }
}

// y = pow(sin(x), 2) + exp(-pow(x, 2)) + pow(x, 3) * log10(x + 1);

double f_x(double x) {
  return sin(pow(x, 2)) + exp(-pow(x, 2)) + pow(x, 3) * log(x + 1);
}
