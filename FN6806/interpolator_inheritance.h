#pragma once

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <vector>

using std::cout;
using std::logic_error;
using std::tuple;
using std::vector;

namespace InterpolatorInheritance {

class Interpolator {
public:
  using T1_type = double;
  using T2_type = double;
  using Series1 = vector<T1_type>;
  using Series2 = vector<T2_type>;

protected:
  Series1 dates;
  Series2 values;

public:
  Interpolator(const Series1 &dates, const Series2 &values)
      : dates(dates), values(values) {
    if (dates.size() != values.size())
      throw logic_error("unequal length x and y");
  }

protected:
  tuple<bool, T2_type> flat_extrapolate(const T1_type &date) const {
    if (date <= dates.front())
      return {true, values.front()};
    if (date >= dates.back())
      return {true, values.back()};
    return {false, 0.0};
  }
};

class LinearInterpolator : public Interpolator {
public:
  using Interpolator::Interpolator;

  T2_type operator()(T1_type date) const {
    auto [b, v] = this->flat_extrapolate(date);
    if (b)
      return v;
    size_t i = 0;
    while (date > this->dates[i])
      ++i;
    return this->values[i - 1] + (this->values[i] - this->values[i - 1]) /
                                     (this->dates[i] - this->dates[i - 1]) *
                                     (date - this->dates[i - 1]);
  }
};

class SquaredInterpolator : public Interpolator {
public:
  using Interpolator::Interpolator;
  T2_type operator()(T1_type date) const {
    auto [b, v] = this->flat_extrapolate(date);
    if (b)
      return v;
    size_t i = 0;
    while (date > this->dates[i])
      ++i;
    const T2_type values_i1_s = this->values[i - 1] * this->values[i - 1];
    const T2_type values_i_s = this->values[i] * this->values[i];
    return sqrt(values_i1_s + (values_i_s - values_i1_s) /
                                  (this->dates[i] - this->dates[i - 1]) *
                                  (date - this->dates[i - 1]));
  }
};

} // namespace InterpolatorInheritance