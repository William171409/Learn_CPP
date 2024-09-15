#pragma once
#include <string>

auto bond_price_zero(double face_value, double coupon_rate,
double maturity, std::string ps, int today, double ic_spread = 0.0);

auto get_df(const int end, int today);

void q4_10(void);