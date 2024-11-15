#include "linear_system.hpp"

int main()
{
    // Test case 1: Unique solution
    std::vector<double> A1 = {2, -1, 3, 1, 0, 4, 5, 2, -2}; // Determinant is non-zero
    std::vector<double> b1 = {8, 10, -2};
    LinearSystem system1(A1, b1);
    system1.solve();
    system1.print(); 

    // Test case 2: No solution (determinant close to zero)
    std::vector<double> A2 = {1, 1, 1, 1, 1, 1, 1, 1, 1}; // Determinant is zero, inconsistent system
    std::vector<double> b2 = {1, 2, 3};
    LinearSystem system2(A2, b2);
    system2.solve();
    system2.print(); 

    // Test case 3: Many solutions (determinant is zero but system is consistent)
    std::vector<double> A3 = {1, 1, 1, 1, 1, 1, 1, 1, 1}; // Determinant is zero, but consistent system
    std::vector<double> b3 = {2, 2, 2};                    // Consistent system with infinite solutions
    LinearSystem system3(A3, b3);
    system3.solve();
    system3.print(); 

    return 0;
}