// #include <iostream>
// #include "interpolator.h"
// int main()
// {
//     {
//         using namespace InterpolatorInheritance;
//         using YieldTermStructure = TermStructure<LinearInterpolator>;
//         using VolatilityTermStructure = TermStructure<SquaredInterpolator>;

//         cout << "InterpolatorInheritance with TermStructure:\n";
//         YieldTermStructure linear({1, 2, 3}, {1, 2, 3});
//         cout << linear.interpolate(0.5) << ", " << linear.interpolate(3.5) << ", "
//              << linear.interpolate(2.3) << "\n";

//         VolatilityTermStructure squared({1, 2, 3}, {1, 2, 3});
//         cout << squared.interpolate(0.5) << ", " << squared.interpolate(3.5) << ", "
//              << squared.interpolate(2.3) << "\n";
//         cout << "\n";
//     }

//     return 0;
// }
