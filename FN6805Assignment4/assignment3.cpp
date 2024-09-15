#include "q3_2.hpp"
#include "q3_3.hpp"
#include "q3_7.hpp"
#include "q4_2.hpp"
#include <iostream>

/*

high quality work

q3_2: good
q3_3: good
q3_7: good. Alternative to return a quete nan, you could use what my slides has
shown,

raise logic_error("Unreachable code");

q4_2: good but a minor improvement

if (k < 1 || n < 0) {
  return 0;
} else if (n == 0) {
  return 1;

to

if (k < 1 || n < 0) {
  return 0;

if (n == 0) {
  return 1;

*/

// int main() {
//   // Consider this snippet from ./q3_2.cpp
//   q3_2(12, -891227);
//   std::cout << "\n";
//   // Consider this snippet from ./q3_3.cpp
//   q3_3(10, 0.5, 100);
//   std::cout << "\n";
//   // Consider this snippet from ./q3_7.cpp
//   q3_7(IC);
//   std::cout << "\n";
//   // Consider this snippet from ./q4_2.cpp
//   for (auto i = -2; i <= 50; i++) {
//     q4_2(i, i);
//     std::cout << "\n";
//   }

//   return 0;
// }