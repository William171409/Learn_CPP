#pragma once

#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
using namespace std;

/*
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Matrix {
  int n;                  // number of rows
  int m;                  // number of columns
  vector<double> entries; // entry in row i and column j
                          // is entries[(i-1)*m + j-1]
public:
  // constructors to support following creation.
  // Matrix A1(2, 2, {1, 2, 3, 4});
  // vector<double> vd{1, 2, 3, 4};
  // Matrix A2(2, 2, vd);
  // Matrix A3;           // empty matrix of 0x0
  // Matrix A4(2, 2);     // matrix of 2x2 with all entries =0
  // Matrix A5(2, 2, 1.); // matrix of 2x2 with all entries =1.

  Matrix(const Matrix &B); // copy constructor, do we need to define it?

  Matrix &
  operator=(const Matrix &B); // assignment operator, do we need to define it?

  ~Matrix(); // destructor, do we need to define it?

  int rows() const;                       // returns n
  int columns() const;                    // returns m
  double get_entry(int i, int j) const;   // returns the (i,j)-entry
  void set_entry(int i, int j, double x); // sets (i,j)-entry to x
  void print() const; // prints matrix to the screen row-wise

  Matrix operator+(const Matrix &B) const;
  Matrix operator-(const Matrix &B) const;
  Matrix operator*(const Matrix &B) const;
};
*/

class Matrix
{
  int n;                  // number of rows
  int m;                  // number of columns
  vector<double> entries; // entry in row i and column j
                          // is entries[(i-1)*m + j-1]
public:
  // should set n,m to zero
  Matrix(int n = 0, int m = 0) : n(n), m(m), entries(n * m, 0) {}

  Matrix(int n, int m, vector<double> A) : n(n), m(m), entries(A)
  {
    if (A.size() != n * m)
    {
      throw logic_error("Input matrix is not of expected size");
    }
  }
  Matrix(int n, int m, double v) : n(n), m(m), entries(n * m, v) {}

  // Matrix(const Matrix &B); // copy constructor, do we need to define it?

  // Matrix & operator=(const Matrix &B); // assignment operator, do we need
  // to define it?
  // ~Matrix(); // destructor, do we need to define it?

  int rows() const;                       // returns n
  int columns() const;                    // returns m
  double get_entry(int i, int j) const;   // returns the (i,j)-entry
  void set_entry(int i, int j, double x); // sets (i,j)-entry to x
  void print() const;                     // prints matrix to the screen row-wise

  Matrix operator+(const Matrix &B) const;
  Matrix operator-(const Matrix &B) const;
  Matrix operator*(const Matrix &B) const;

  friend std::ostream &operator<<(std::ostream &os, const Matrix &m);

  void swap_rows(int i, int j); // swaps rows i and j of the supporting object
  void row_add(int i, int j,
               double z); // adds z*(row i) to row j of the supporting object A;
                          // that is, A_{j,k} is replaced by A_{j,k} + zA_{i,k)
                          // for k=1,...,m
  Matrix
  gauss_elim() const; // returns the result of applying Gaussian elimination
                      // to the supporting object (the supporting object must
                      // not be changed; hence Gaussian elimination should
                      // be applied to a copy of the supporting object
};
