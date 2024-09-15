#include <iostream>
#include <random>
#include <vector>

// Global variables
std::random_device rd{};
auto mtgen = std::mt19937{rd()};

std::vector<double> rand_vector(int n, double a, double b) {
  auto urdd = std::uniform_real_distribution<double>{a, b};
  std::vector<double> result(n);
  for (auto &num : result) {
    num = urdd(mtgen);
  }
  return result;
}

void q3_3(int n, double a, double b) {
  std::vector<double> vec = rand_vector(n, a, b);
  for (const auto &num : vec) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}