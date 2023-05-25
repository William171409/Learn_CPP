#include <functional>
#include <iostream>
int main()
{
  // A regular function pointer. Only works with an empty capture clause (empty []).
  double (*addNumbers1)(double, double){
    [](double a, double b) {
      return (a + b);
    }
  };

  std::cout<< addNumbers1(1, 2)<<'\n';

  // Using std::function. The lambda could have a non-empty capture clause (discussed next lesson).
  std::function addNumbers2{ // note: pre-C++17, use std::function<double(double, double)> instead
    [](double a, double b) {
      return (a + b);
    }
  };

  std::cout<< addNumbers2(3, 4)<<'\n';

  // Using auto. Stores the lambda with its real type.
  auto addNumbers3{
    [](double a, double b) {
      return (a + b);
    }
  };

  std::cout<< addNumbers3(5, 6)<<'\n';

  return 0;
}