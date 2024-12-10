#pragma once
#include <vector>
#include <tuple>
#include <memory>
#include <string>
using RateCurve = std::vector<std::tuple<int, double>>;
const RateCurve IC{{41082, 0.0},
                   {41083, 0.344720594377147},
                   {41085, 0.344720594377147},
                   {41092, 0.368368772605730},
                   {41116, 0.525570772180778},
                   {41146, 0.589858326742378},
                   {41179, 0.741119832110955},
                   {41188, 0.696749901029990},
                   {41278, 0.806659936532139},
                   {41368, 0.884475547507158},
                   {41461, 0.941966915221572},
                   {41552, 0.992016219922792},
                   {41649, 1.04351212131796},
                   {41816, 1.34312007757781},
                   {42181, 1.59973094475305},
                   {42546, 1.86320995459478},
                   {42911, 2.11609386013679},
                   {43279, 2.34400261226439},
                   {43643, 2.53599931753348},
                   {44007, 2.70067752825491},
                   {44372, 2.83822638195572},
                   {44738, 2.95830187616262},
                   {45470, 3.16075166306880},
                   {46564, 3.33878283257801},
                   {48390, 3.40297375743186},
                   {50216, 3.29434168467002},
                   {52043, 3.11704336212427}};

class YieldCurve
{
    RateCurve rate_curve{};

public:
    YieldCurve(RateCurve rate_curve) : rate_curve{rate_curve}
    {
    }
    double interpolate(const std::vector<int> &dates, const std::vector<double> &rates,
                       const int date);
    friend void transfer_ratecurve(std::vector<int> &, std::vector<double> &, const RateCurve &rc);
};

class FixRatedBond
{
    std::shared_ptr<YieldCurve> y_curve{};
    double face_value{};
    double coupon_rate{};
    double maturity{};
    std::string payment_schedule{};
    int today{};
    double ic_spread{};

public:
    FixRatedBond(std::shared_ptr<YieldCurve> y_curve, double face_value, double coupon_rate,
                 double maturity, const std::string &payment_schedule, int today, double ic_spread)
        : y_curve{y_curve}, face_value{face_value}, coupon_rate{coupon_rate},
          maturity{maturity}, payment_schedule{payment_schedule}, today{today}, ic_spread{ic_spread} {}
    auto get_df(const int end, int today);
    int getCouponFrequencyValue(const std::string &input);
    double bond_price_zero();
    std::tuple<int, double> calculate_date_df(int today, int i, int frequency);
};

void q5_1(void);
