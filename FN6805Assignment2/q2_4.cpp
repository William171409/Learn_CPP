#include <cmath>
#include <iostream>

void print_bullet(double, int, int, double);
void print_equal_principal(double, int, int, double);
void print_equal_total(double, int, int, double);

void q2_4(double loan_amount, int loan_term, int pay_f,
          double annual_interest_rate) {
  std::cout << '\n' << "bullet:" << std::endl;
  print_bullet(loan_amount, loan_term, pay_f, annual_interest_rate);
  std::cout << '\n' << "equal_principal:" << std::endl;
  print_equal_principal(loan_amount, loan_term, pay_f, annual_interest_rate);
  std::cout << '\n' << "equal_total:" << std::endl;
  print_equal_total(loan_amount, loan_term, pay_f, annual_interest_rate);
}

void print_bullet(double loan_amount, int loan_term, int pay_f,
                  double annual_interest_rate) {
  double curr_balance{loan_amount};
  double all_payments{0};
  double all_interest{0};
  double all_principal{0};
  for (auto curr_loan_month = 0; curr_loan_month <= loan_term;
       curr_loan_month++) {
    if (!curr_loan_month) {
      std::cout << "CM: " << curr_loan_month << " CPI: " << 0 << " CI: " << 0
                << " CP: " << 0 << " Bal: " << curr_balance << "\n";
    } else {
      double curr_interest_payment =
          curr_balance * annual_interest_rate / pay_f;
      double curr_principal_payment =
          (curr_loan_month == loan_term) ? loan_amount : 0.0;
      double curr_payment = curr_interest_payment + curr_principal_payment;

      if (curr_loan_month == loan_term) {
        curr_balance = 0.0;
      }
      // per period
      std::cout << "CM: " << curr_loan_month << " CPI: " << curr_payment
                << " CI: " << curr_interest_payment
                << " CP: " << curr_principal_payment << " Bal: " << curr_balance
                << "\n";

      all_payments += curr_payment;
      all_interest += curr_interest_payment;
      all_principal += curr_principal_payment;
    }
  }
  // summary and help to check the calculation
  std::cout << "Total PI: " << all_payments << " I: " << all_interest
            << " P: " << all_principal << "\n";
}

void print_equal_principal(double loan_amount, int loan_term, int pay_f,
                           double annual_interest_rate) {
  double curr_balance{loan_amount};
  double all_payments{0};
  double all_interest{0};
  double all_principal{0};
  double curr_principal_payment = loan_amount / loan_term;

  for (auto curr_loan_month = 0; curr_loan_month <= loan_term;
       curr_loan_month++) {
    if (!curr_loan_month) {
      std::cout << "CM: " << curr_loan_month << " CPI: " << 0 << " CI: " << 0
                << " CP: " << 0 << " Bal: " << curr_balance << "\n";
    } else {
      double curr_interest_payment =
          curr_balance * annual_interest_rate / pay_f;
      double curr_payment = curr_interest_payment + curr_principal_payment;
      curr_balance -= curr_principal_payment;
      // per period
      std::cout << "CM: " << curr_loan_month << " CPI: " << curr_payment
                << " CI: " << curr_interest_payment
                << " CP: " << curr_principal_payment << " Bal: " << curr_balance
                << "\n";
      all_payments += curr_payment;
      all_interest += curr_interest_payment;
      all_principal += curr_principal_payment;
    }
  }
  // summary and help to check the calculation
  std::cout << "Total PI: " << all_payments << " I: " << all_interest
            << " P: " << all_principal << "\n";
}

void print_equal_total(double loan_amount, int loan_term, int pay_f,
                       double annual_interest_rate) {
  double monthly_interest_rate = annual_interest_rate / pay_f;
  int total_payments = loan_term / (12 / pay_f);

  double curr_payment =
      (loan_amount * monthly_interest_rate *
       std::pow(1 + monthly_interest_rate, total_payments)) /
      (std::pow(1 + monthly_interest_rate, total_payments) - 1);

  double curr_balance{loan_amount};
  double all_payments{0};
  double all_interest{0};
  double all_principal{0};

  for (auto curr_loan_month = 0; curr_loan_month <= loan_term;
       curr_loan_month++) {
    if (!curr_loan_month) {
      std::cout << "CM: " << curr_loan_month << " CPI: " << 0 << " CI: " << 0
                << " CP: " << 0 << " Bal: " << curr_balance << "\n";
    } else {
      double curr_interest_payment = curr_balance * monthly_interest_rate;
      double curr_principal_payment = curr_payment - curr_interest_payment;
      curr_balance -= curr_principal_payment;
      // per period
      std::cout << "CM: " << curr_loan_month << " CPI: " << curr_payment
                << " CI: " << curr_interest_payment
                << " CP: " << curr_principal_payment << " Bal: " << curr_balance
                << "\n";
      all_payments += curr_payment;
      all_interest += curr_interest_payment;
      all_principal += curr_principal_payment;
    }
  }
  // summary and help to check the calculation
  std::cout << "Total PI: " << all_payments << " I: " << all_interest
            << " P: " << all_principal << "\n";
}