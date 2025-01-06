#include "q6_1.hpp"
#include <numeric>

using multipath = vector<vector<double>>;
auto vasicek_multipath(double sd, double kappa, double r_mean, double r0,
                       double T, int paths, int steps, mt19937 &gen)
{
    double dt = T / steps;
    multipath v(paths, vector<double>(steps + 1));
    for (auto &v_path : v)
    {
        v_path[0] = r0;
    } // fill in the first value
    static normal_distribution<double> nd(0, 1);

    // Generate paths using STL algorithms
    for (auto &v_path : v)
    {
        vector<double> z(steps);
        generate(z.begin(), z.end(), [&]()
                 { return nd(gen); });

        transform(next(v_path.begin()), v_path.end(), v_path.begin(), next(v_path.begin()),
                  [=, i = 0, &z](double,double prev) mutable
                  {
                      double dz = z[i++];
                      return prev + kappa * (r_mean - prev) * dt + sd * sqrt(dt) * dz;
                  });
    }

    return v;
}

auto vasicek(double sd, double kappa, double r_mean, double r0,
             double T, int paths, int steps, mt19937 &gen)
{
    vector<double> sum_rates(paths);
    vector<double> end_rates(paths);
    multipath traj = vasicek_multipath(sd, kappa, r_mean, r0, T, paths, steps, gen);

    transform(traj.begin(), traj.end(), begin(end_rates),
              [](const auto &v)
              { return v.back(); });
    transform(traj.begin(), traj.end(), begin(sum_rates),
              [](const auto &v)
              { return accumulate(next(v.begin()), v.end(), 0.0); });

    return make_tuple(end_rates, sum_rates);
}
auto vasicek_valarray(double sd, double kappa, double r_mean, double r0,
             double T, int paths, int steps, mt19937 &gen)
{
    valarray<double> sum_rates(paths);
    valarray<double> end_rates(paths);
    multipath traj = vasicek_multipath(sd, kappa, r_mean, r0, T, paths, steps, gen);
    transform(traj.begin(), traj.end(), begin(end_rates),
              [](const auto &v)
              { return v.back(); });
    transform(traj.begin(), traj.end(), begin(sum_rates),
              [](const auto &v)
              { return accumulate(next(begin(v)), end(v), 0.0); });


    return make_tuple(end_rates, sum_rates);
}

void q6_1()
{
    seed_seq seed{90127};
    auto mtgen = mt19937{seed};
    auto [end_rates, sum_rates] =
        vasicek(sd, kappa, r_mean, r0, T, 20000, int(0.5 * 365),
                mtgen);
    auto end_rates_avg =
        accumulate(end_rates.begin(), end_rates.end(), 0.0)/
            end_rates.size();
    auto sum_rates_avg =
        accumulate(sum_rates.begin(), sum_rates.end(), 0.0)/
            sum_rates.size();
    cout << end_rates_avg << ", " << sum_rates_avg << "\n";
    // 0.0495695, 9.05915

    mtgen.seed(seed);
    auto [end_rates2, sum_rates2] =
    vasicek_valarray(
    sd, kappa, r_mean, r0, T, 20000, int(0.5 * 365), mtgen);
    end_rates_avg =
    accumulate(begin(end_rates2), end(end_rates2), 0.0) /
    end_rates2.size();
    sum_rates_avg =
    accumulate(begin(sum_rates2), end(sum_rates2), 0.0) /
    sum_rates2.size();
    cout << end_rates_avg << ", " << sum_rates_avg << "\n";
}