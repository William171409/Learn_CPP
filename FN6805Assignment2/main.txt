#include <iostream>
#include <string>
using namespace std;

void exercise1(double num, string str_msg) {
  cout << typeid(num).name() << "\n";
  cout << num << str_msg << "\n";
}

void exercise2() {
  // data type overflow refer to learncpp.com type size
  int i2 = 1024 * 1024 * 1024;
  cout << i2 * 2 << "\n";
  // double d1 = 1024 * 1024 * 1024 * 4; //integer overflow
  // cout << d1 << "\n";
  // cout << d1 * 2 << "\n";
  auto u1 = 25u - 50;
  cout << u1 << "\n";
}

void test4() {
  // like vector(size, value), this creates a string of 16 x
  string password(16, 'x');
  auto s0{"abc"s};
  string s1{};              // Empty string
  s1 = "Today is Saturday"; // assign it to value
  string s2(s1);
  // string s2("Today is Saturday");
  s2[0] = 't';
  cout << s1 << "\n" << s2 << "\n" << (s1 == s2) << "\n";
}

struct Ticket {
  int concert_id;
  string seat_id;
};

int main() {
  // std::string
  test4();

  // struct
  Ticket tk{1123112, "A123"};
  /*Optionally, we can add the field names Ticket tk2{
                      .concert_id = 1123112, .seat_id = "A123"};*/
  auto [concert_id, seat_id] = tk;
  cout << concert_id << ", " << seat_id << "\n";
  tk.seat_id = "B123";
  cout << "After update: " << tk.concert_id << ", " << tk.seat_id << "\n";

  // enum
  // enum type
  enum PayoffType { CALL = 0, PUT = 1 };
  enum OptionType { European = 0, American = 1 };

  // Compiler error with below comparison
  // cout << (PayoffType::CALL == OptionType::European) << "\n";

  // enum class
  enum class PayoffTypeC { CALL = 0, PUT = 1 };
  enum class OptionTypeC { European = 0, American = 1 };

  // Compiler error with below comparison
  // auto comp = (PayoffTypeC::CALL == OptionTypeC::European);

  // This will force conversion to int
  auto res = static_cast<int>(PayoffTypeC::CALL);
  cout << res << "\n";

  auto num{1111111111111111111};
  string msg{" is a prime number!"s};
  cout << "The type of num when auto is used: " << typeid(num).name() << "\n";
  exercise1(num, msg);
  exercise2();

  int user_input{};
  int user_input2{};
  std::string dummy{};
  std::cout << "Enter an integer: ";
  std::cin >> user_input;
  if (std::cin.fail()) {
    std::cout << "Invalid input\n";
  } else {
    std::cout << "User's input is " << user_input << "\n";
  }

  // std::getline(std::cin,dummy);
  std::cin >> user_input2;
  std::cout << "The remaining string in output stream: " << user_input2 << "\n";
  return 0;
}