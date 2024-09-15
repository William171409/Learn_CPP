#include <cxxabi.h>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

/*
YY:

q1_1: very good.

q1_2: the comments are to the points.

q1_3: very good

q2_1: very good. The tests are implemented with function result == expected
result. Good use of struct.
*/

enum class VoucherValue { ONE = 1, TWO = 2, FIVE = 5, TEN = 10 };

struct VoucherV3 {
  VoucherValue value;
  bool spent = false;
};

struct Household {
  long id;
  std::string address;
};

using HouseholdID = long;
// A new version
struct HouseholdVouchersV2 {
  HouseholdID id;
  std::vector<VoucherV3> vouchers;
  int balance{};
  bool issued{};
  int issued_amount{};
};

// ChatGPT generated demangle function used to map type literals to their full
// names.
std::string demangle(const char *mangled) {
  int status = -1;
  char *demangled = abi::__cxa_demangle(mangled, nullptr, nullptr, &status);
  std::string result = (status == 0) ? demangled : mangled;
  free(demangled);
  return result;
}

int calculate_balance(const std::vector<VoucherV3> &vouchers) {
  int balance{0};
  for (const auto &voucher : vouchers) {
    if (!voucher.spent) {
      balance += static_cast<int>(voucher.value);
    }
  }
  return balance;
}

// ChatGPT generated print_unused_vouchers function
void print_unused_vouchers(const std::vector<VoucherV3> &vouchers) {
  std::map<VoucherValue, int> voucher_counts;

  // Count the number of unused vouchers for each value
  for (const auto &voucher : vouchers) {
    if (!voucher.spent) {
      voucher_counts[voucher.value]++;
    }
  }

  // Print the counts in the required format
  for (const auto &pair : voucher_counts) {
    int value = static_cast<int>(pair.first);
    int count = pair.second;
    std::cout << value << "$ " << count << std::endl;
  }
}

void q1_1() {
  // Lecture 1 Exercise 1
  auto num{1111111111111111111};
  std::string msg{" is a prime number!"};
  std::cout << num << msg << std::endl;
  std::cout << "Data type of num is: " << demangle(typeid(num).name())
            << std::endl;
}

void q1_2() {
  // Lecture 1 Exercise 2

  int i2 = 1024 * 1024 * 1024;
  std::cout << i2 * 2 << "\n";

  /*
    data overflow as the range for integer is [-2^31,2^31-1], the final output
    is -2^31
  */

  // double d1 = 1024 * 1024 * 1024 * 4;
  // std::cout << d1 << "\n";
  // std::cout << d1 * 2 << "\n";

  /*
    integer overflow as 1024*1024*1024*4 will be evaulated as integer, the
    result is 2^32 which is indeed out of range as range of integer is
    [-2^31,2^31-1] The compiler will report error during compilation.
  */

  auto u1 = 25u - 50;
  std::cout << u1 << "\n";

  /*
    data overflow as u1 will be calculated as an unsigned integer with value -25
    which is indeed out of range output should be 2^32-25
  */
}

void q1_3() {
  // Lecture 1 Exercise 3
  using namespace std::string_literals;

  Household h1{637659, "Hall12"s};
  Household h2{637719, "Hall4"s};
  Household h3{636960, "Banyan Hall"s};

  // TEST
  // std::cout << "h1.id: " << h3.id << "\n";
  // std::cout << "h1.address: " << h3.address << "\n";

  std::vector<VoucherV3> vouchers;
  for (int i = 1; i <= 11; i++) {
    if (i <= 5) {
      vouchers.push_back(VoucherV3{VoucherValue::TWO});
    } else if (i <= 9) {
      vouchers.push_back(VoucherV3{VoucherValue::FIVE});
    } else {
      vouchers.push_back(VoucherV3{VoucherValue::TEN});
    }
  }
  int balance{calculate_balance(vouchers)};
  bool issued_status{true};
  int issued_amount{50};

  HouseholdVouchersV2 h1_vouchers{h1.id, vouchers, balance, issued_status,
                                  issued_amount};
  HouseholdVouchersV2 h2_vouchers{h2.id, vouchers, balance, issued_status,
                                  issued_amount};
  HouseholdVouchersV2 h3_vouchers{h3.id, vouchers, balance, issued_status,
                                  issued_amount};

  std::cout << "Household h1\nid: " << h1_vouchers.id << "\n"
            << "vouchers:"
            << "\n";
  print_unused_vouchers(h1_vouchers.vouchers);
  std::cout << "balance: " << h1_vouchers.balance
            << "\nissued_status: " << h1_vouchers.issued
            << "\nissued_amount: " << h1_vouchers.issued_amount << std::endl;

  // assume use 5 2$ vouchers and 1 10$ voucher
  for (int i = 0; i <= 4; i++) {
    h1_vouchers.vouchers[i].spent = true;
  }
  h1_vouchers.vouchers[h1_vouchers.vouchers.size() - 1].spent = true;
  h1_vouchers.balance = calculate_balance(h1_vouchers.vouchers);

  std::cout << "\nAfter spending 20$\n\n";

  std::cout << "Household h1\nid: " << h1_vouchers.id << "\n"
            << "vouchers:"
            << "\n";
  print_unused_vouchers(h1_vouchers.vouchers);
  std::cout << "balance: " << h1_vouchers.balance
            << "\nissued_status: " << h1_vouchers.issued
            << "\nissued_amount: " << h1_vouchers.issued_amount << std::endl;
}

int calculate_weekday(int day, int month, int year) {
  if (month < 1 || month > 12) {
    throw std::invalid_argument("Month should be between 1 and 12");
  }
  if (day < 1 || day > 31) {
    throw std::invalid_argument("Day should be between 1 and 31");
  }

  if (month == 1 || month == 2) {
    month += 12;
    year -= 1;
  }

  int d = day;
  int m = month;
  int c = year / 100;
  int y = year - 100 * c;

  int w{(d + (13 * (m + 1)) / 5 + y + y / 4 + c / 4 - 2 * c) % 7};
  return w;
}

void test_zeller_spot() {
  struct TestCase {
    int day;
    int month;
    int year;
    int expected_weekday;
  };

  std::vector<TestCase> tescases{{1, 1, 2024, 2},   {15, 8, 2024, 5},
                                 {31, 12, 2024, 3}, {29, 2, 2024, 5},
                                 {30, 6, 2023, 6},  {1, 7, 2023, 0}};

  for (const auto &testcase : tescases) {
    std::cout << (calculate_weekday(testcase.day, testcase.month,
                                    testcase.year) == testcase.expected_weekday)
              << "\n";
  }
}

void q2_1(int day, int month, int year) {
  // Lecture 2 Exercise 1
  int weekday{calculate_weekday(day, month, year)};
  std::cout << "Date: " << day << "/" << month << "/" << year << "\n";
  std::cout << "Weekday: " << weekday << "\n";

  test_zeller_spot();
}

int main() {
  q1_1();
  // q1_2();
  q1_3();
  q2_1(2, 2, 2024);
  return 0;
}