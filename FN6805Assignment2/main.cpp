#include "q2_2.hpp"
#include "q2_3.hpp"
#include "q2_4.hpp"
#include "q3_1.hpp"
#include <iostream>
#include <string>

/*
YY:

q2_2: good
q2_3: good.
q2_4: good. but

The use of curr_loan_month as a bool is not clear for your intent.

    if (!curr_loan_month) {

could be

    if (curr_loan_month == 0) {


q3_1: good but when we use double as iterator variable because 0.1 + 0.1
.... for 10 times may not equal to 1.0, relax the condition.

for (double i = 0; i <= 1.09; i += 0.1) {
  print_func(i);
}

// Wrong formula

return sin(pow(x, 2)) + exp(-pow(x, 2)) + pow(x, 3) * log(x + 1);

should be

return pow(sin(x), 2) + exp(-pow(x, 2)) + pow(x, 3) * log(x + 1);

*/

int main() {
  // Q2_2 Slide 62
  int q2_2_input{1000};
  std::cout << "Final value of q2_2 is " << successive_decrease13(q2_2_input)
            << std::endl;

  // Q2_3 Slide 66
  q2_3();

  // Q2_4 Slide 73-78
  q2_4(loan_amount, loan_term, pay_f, annual_interest_rate);
  // q2_4(390123, 66, 12, 0.05);

  // Q3_1 Slide 27
  q3_1();

  return 0;
}