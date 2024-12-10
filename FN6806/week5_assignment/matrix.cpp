#include "matrix.h"
#include <cmath>
using namespace std;

Matrix Matrix::operator+(const Matrix &B) const
{
  if (n != B.rows() || m != B.columns())
  {
    throw logic_error("cannot add matrices");
  }

  Matrix Result(n, m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      Result.set_entry(i, j, get_entry(i, j) + B.get_entry(i, j));
  return Result;
}

Matrix Matrix::operator-(const Matrix &B) const
{
  if (n != B.rows() || m != B.columns())
  {
    throw logic_error("cannot add matrices");
  }

  Matrix Result(n, m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      Result.set_entry(i, j, get_entry(i, j) - B.get_entry(i, j));
  return Result;
}

Matrix Matrix::operator*(const Matrix &B) const
{
  if (m != B.rows())
  {
    throw logic_error("cannot multiply matrices");
  }
  Matrix Result(n, B.columns());
  double sum;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= B.columns(); j++)
    {
      sum = 0;
      for (int k = 1; k <= m; k++)
        sum += get_entry(i, k) * B.get_entry(k, j);
      Result.set_entry(i, j, sum);
    }
  return Result;
}

int Matrix::rows() const { return n; }

int Matrix::columns() const { return m; }

double Matrix::get_entry(int i, int j) const
{
  return entries[(i - 1) * m + j - 1];
}

void Matrix::set_entry(int i, int j, double x)
{
  entries[(i - 1) * m + j - 1] = x;
}

void Matrix::print() const
{
  for (size_t i = 1; i <= n; i++)
  {
    for (size_t j = 1; j <= m; j++)
      cout << setw(13) << entries[(i - 1) * m + j - 1];
    cout << "\n";
  }
}

std::ostream &operator<<(std::ostream &os, const Matrix &m)
{
  for (size_t i = 1; i <= m.n; i++)
  {
    for (size_t j = 1; j <= m.m; j++)
      os << setw(13) << m.entries[(i - 1) * m.m + j - 1];
    os << "\n";
  }
  return os;
}

void Matrix::row_add(int i, int j, double z)
{
  for (int k = 1; k <= m; k++)
    set_entry(j, k, get_entry(j, k) + z * get_entry(i, k));
}

void Matrix::swap_rows(int i, int j)
{
  if (i < 0 || i > n || j < 0 || j > m)
  {
    throw logic_error("Matrix::swap_rows: indices out of range");
  }

  double buffer;
  for (int k = 1; k <= m; k++)
  {
    buffer = get_entry(j, k);
    set_entry(j, k, get_entry(i, k));
    set_entry(i, k, buffer);
  }
}

Matrix Matrix::gauss_elim() const
{
  Matrix temp_mat{*this};
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
    temp_mat.swap_rows(i, max_row);
    for (auto k{i + 1}; k <= n; k++)
    {
      double c{-temp_mat.get_entry(k, i) / temp_mat.get_entry(i, i)};
      for (auto j{i}; j <= n; j++)
      {
        if (i == j)
        {
          temp_mat.set_entry(k, j,0);
        }
        else
        {
          temp_mat.set_entry(k, j,temp_mat.get_entry(k, j) + c * temp_mat.get_entry(i, j));
        }
      }
    }
  }

  return temp_mat;
};

/*
function GAUSS(A)
for (i=1; i<n; ++i) do
  // Search for maximum in the column
  max_El = abs( A_{i,i} )
  max_Row = i
  for (k=i+1; k <= n; ++k) do
    if abs (A_{k,i}) > max_El then
      max_El = A{k,i}
      max_Row = k
    end if
  end for
  // Swap maximum row with current row
  for (k=1; k <= n; ++k) do
    tmp = A_{maxRow, k}
    A_{maxRow, k} = A_{i,k}
    A_{i,k} = tmp
  end for
  ^/ Make all rows below this one 0 in current column
  for (k=i+1; k <= n; ++k) do
    c= - A_{k,i} / A_{i,i}
    for (j=i; j <= n; ++j) do
      if i==j then
        A_{k,j} = 0
      else
        A_{k,j} += c * A_{i,j}
      end if
    end for
  end for
end for
end function
*/
