#pragma once
#include <vector>

class LinearSystem
{
    std::vector<double> A; //(i,j) entry of matrix is A[3*(i-1)+j-1]
    std::vector<double> b;
    mutable std::vector<double> sol;

public:
    LinearSystem(std::vector<double> A, std::vector<double> b); // Initializes A to A1 and b to b1

    void solve() const;
    // Sets sol to solution of Ax=b if abs(det(A))>1e/-10
    // and sets sol to empty vector otherwise

    void print() const;
    // Prints solution to the screen;
    // if sol is empty, then prints message to the
    // screen that there is no unique solution
};

double sarrus_determinant(const std::vector<double> &mat);