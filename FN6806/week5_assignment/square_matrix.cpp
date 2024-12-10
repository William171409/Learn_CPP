#include "square_matrix.hpp"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

SquareMatrix::SquareMatrix()
{
  cout << "SquareMatrix default constructor\n";
  // no need to do anything;
  // default constructor of Matrix will automatically be called
}

SquareMatrix::SquareMatrix(int n1) : Matrix(n1, n1)
{
  cout << "SquareMatrix constructor1\n";
}

SquareMatrix::SquareMatrix(int n1, const vector<double> &A)
    : Matrix(n1, n1, A)
{
  cout << "SquareMatrix constructor2\n";
}

SquareMatrix::SquareMatrix(const SquareMatrix &B) : Matrix(B)
{
  cout << "SquareMatrix copy constructor\n";
}

SquareMatrix::SquareMatrix(const Matrix &B) : Matrix(B)
{
  cout << "Matrix to SquareMatrix constructor\n";
}

SquareMatrix SquareMatrix::power(int t) const
{
  SquareMatrix temp_sqmatrix{*this};
  for (auto i = 1; i <= t - 1; i++)
  {
    temp_sqmatrix = temp_sqmatrix*temp_sqmatrix;
  }
  return temp_sqmatrix;
}

tuple<SquareMatrix, int> SquareMatrix::gauss_elim() const
{
  SquareMatrix temp_mat{*this};
  auto n{rows()};
  int count_swap{0};
  for (auto i = 1; i < n; i++)
  {
    double max_el{abs(temp_mat.get_entry(i, i))};
    int max_row{i};
    for (auto k = i + 1; k <= n; k++)
    {
      if (abs(temp_mat.get_entry(k, i)) > max_el)
      {
        max_el = temp_mat.get_entry(k, i);
        max_row = k;
      }
    }
    if (max_row != i)
    {
      temp_mat.swap_rows(i, max_row);
      count_swap++;
    }

    for (auto k{i + 1}; k <= n; k++)
    {
      double c{-temp_mat.get_entry(k, i) / temp_mat.get_entry(i, i)};
      for (auto j{i}; j <= n; j++)
      {
        if (i == j)
        {
          temp_mat.set_entry(k, j,0 );
        }
        else
        {
          temp_mat.set_entry(k, j,temp_mat.get_entry(k, j) + c * temp_mat.get_entry(i, j));
        }
      }
    }
  }

  return make_tuple(temp_mat, count_swap);
}

double SquareMatrix::det() const
{
  auto ge_tuple{gauss_elim()};
  auto ge_mat{get<0>(ge_tuple)};
  auto ge_swap{get<1>(ge_tuple)};
  double det{1};
  for (auto i{1}; i <= ge_mat.rows(); i++)
  {
    det *= ge_mat.get_entry(i, i);
  }

  return det * pow(-1, ge_swap);
}


void square_matrix_test()
{
  SquareMatrix U1;
  SquareMatrix U2(3);
  vector<double> UB{6, 2, 9, 0, 5, 2.5, 0, 0, -19.0/6};
  SquareMatrix U(3, UB);
  cout << get<0>(U.gauss_elim()) << "\n";
  cout << U.det() << "\n";
  // << -95
  vector<double> VB = {9, 3, 4, 4, 3, 4, 1, 1, 1};
  SquareMatrix V(3, VB);
  cout << get<0>(V.gauss_elim()) << "\n";
  cout << V.det() << "\n";
  // << -5
}