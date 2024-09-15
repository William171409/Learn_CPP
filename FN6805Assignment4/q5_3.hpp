#pragma once
#include "q3_7.hpp"
RateCurve parallel_updown(double delta, int today, const RateCurve &IC);
RateCurve short_rates_shock(double delta, int today, const RateCurve &IC);
RateCurve rotational_shock(double delta, int today, const RateCurve &IC);
void q5_3(void);

