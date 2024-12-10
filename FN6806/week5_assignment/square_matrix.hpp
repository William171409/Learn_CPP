#pragma once

#include "matrix.h"
#include <tuple>
class SquareMatrix : public Matrix
{
public:
  SquareMatrix(); // default constructor;
  SquareMatrix(int n1);
  // constructor; should create a matrix with
  // n1 rows and n1 columns, and set all entries to zero
  SquareMatrix(int n1, const vector<double> &A);
  // constructor; should create an n1xn1 matrix
  // and initialize entries with elements of A
  SquareMatrix(const Matrix &B);       // converts matrix to square matrix
  SquareMatrix(const SquareMatrix &B); // copy constructor
  SquareMatrix power(int t) const;     // returns A^t where A is the supporting object
  tuple<SquareMatrix, int> gauss_elim() const;
  double det() const;                  // returns determinant of supporting object
};

void square_matrix_test(void);