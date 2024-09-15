#include <iostream>
#include <limits>
#include <tuple>
#include <vector>

void transfer_ratecurve(std::vector<int> &dates, std::vector<double> &rates,
                        const std::vector<std::tuple<int, double>> &IC) {
  for (auto i = 0; i < IC.size(); i++) {
    auto [d, r] = IC[i];
    dates[i] = d;
    rates[i] = r;
  }
}

double interpolate(const std::vector<int> &dates,
                   const std::vector<double> &rates, const int date) {

  if (date <= dates.front()) {
    return rates.front();
  }
  if (date >= dates.back()) {
    return rates.back();
  }

  for (size_t i = 0; i < dates.size() - 1; ++i) {
    if (date >= dates[i] && date <= dates[i + 1]) {
      double d1 = dates[i];
      double d2 = dates[i + 1];
      double r1 = rates[i];
      double r2 = rates[i + 1];
      return r1 + (r2 - r1) * (date - d1) / (d2 - d1);
    }
  }

  // Fallback return value for safety. This should ideally not be reached if the
  // input is correct.
  // ChatGPT generated this line to deal with compiler warning
  return std::numeric_limits<double>::quiet_NaN();
}

void q3_7(const std::vector<std::tuple<int, double>> &IC) {
  std::vector<int> dates(IC.size(), 0);
  std::vector<double> rates(IC.size(), 0.0);

  transfer_ratecurve(dates, rates, IC);

  std::cout << "Dates and Rates:" << std::endl;
  for (size_t i = 0; i < dates.size(); ++i) {
    std::cout << "Date: " << dates[i] << ", Rate: " << rates[i] << std::endl;
  }

  std::vector<int> test_dates = {41081, 41084, 41090, 41100, 41800, 42500,
                                 44010, 45000, 47000, 91124, 41095};

  std::cout << "Testing interpolation:" << std::endl;
  for (const auto &date : test_dates) {
    double interpolated_rate = interpolate(dates, rates, date);
    std::cout << "Date: " << date
              << ", Interpolated Rate: " << interpolated_rate << std::endl;
  }
}
