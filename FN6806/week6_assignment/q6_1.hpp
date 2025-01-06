#pragma once

#include <iostream>
#include <vector>
#include <valarray>
#include <random>
#include <tuple>
#include <cmath>
using namespace std;

const double r0{0.05};
const double sd{0.1};
const double kappa{0.82};
const double r_mean{0.05};
const double T{0.5};
const int steps{static_cast<int>(T*365)};


auto vasicek(double sd, double kappa, double r_mean, double r0,
             double T, int paths, int steps, mt19937 &gen);

auto vasicek_valarray(double sd, double kappa, double r_mean, double r0,
             double T, int paths, int steps, mt19937 &gen);



auto vasicek_multipath(double sd, double kappa, double r_mean, double r0,
             double T, int paths, int steps, mt19937 &gen);

void q6_1(void);
