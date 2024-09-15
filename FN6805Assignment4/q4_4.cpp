#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>

void q4_4() {
  // 1)
  std::list<int> L1(10);
  std::iota(L1.begin(), L1.end(), 0);
  std::cout << "L1: \n";
  for (auto element : L1) {
    std::cout << element << " ";
  }

  std::cout << std::endl;

  // 2)
  std::list<int> L2(10);
  std::iota(L2.begin(), L2.end(), 10);
  std::cout << "L2: \n";
  for (auto element : L2) {
    std::cout << element << " ";
  }

  std::cout << std::endl;

  // 3)
  L1.splice(L1.end(), L2);
  std::cout << "L1 after splice: \n";
  for (auto element : L1) {
    std::cout << element << " ";
  }

  std::cout << std::endl;

  // 4)
  std::cout << "L1'size = " << L1.size() << std::endl;
  std::cout << "L2'size = " << L2.size() << std::endl;

  // 5)
  L1.remove_if([](int x) { return x % 2 == 0; });
  std::cout << "L1 after removing even numbers: ";
  for (const auto &elem : L1) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;

  // 6)
  std::cout << "first element of L1: " << L1.front() << std::endl;
  std::cout << "last element of L1: " << L1.back() << std::endl;
}