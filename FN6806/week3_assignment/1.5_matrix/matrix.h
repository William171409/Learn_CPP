#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
#include <stdexcept>
#include <cassert>
using namespace std;

class Matrix {
  int n;                  // number of rows
  int m;                  // number of columns
  vector<double> entries; // entry in row i and column j
                          // is entries[(i-1)*m + j-1]
public:
  Matrix():n{0},m{0},entries{{}}{}
  Matrix(int n, int m,vector<double> e_vec): n{n},m{m},entries{e_vec}{}
  Matrix(int n, int m, double e=0.0): n{n},m{m},entries{vector<double>(n*m,e)}{}
  // constructors to support following creation.
  // Matrix A1(2, 2, {1, 2, 3, 4});
  // vector<double> vd{1, 2, 3, 4};
  // Matrix A2(2, 2, vd);
  // Matrix A3;           // empty matrix of 0x0
  // Matrix A4(2, 2);     // matrix of 2x2 with all entries =0
  // Matrix A5(2, 2, 1.); // matrix of 2x2 with all entries =1.

  Matrix(const Matrix &B) = default; // copy constructor, do we need to define it? NO

  Matrix &
  operator=(const Matrix &B) = default; // assignment operator, do we need to define it? NO

  ~Matrix() = default; // destructor, do we need to define it?

  int rows() const
  {
    return n;
  }                       // returns n
  int columns() const
  {
    return m;
  }                    // returns m
  double get_entry(int i, int j) const
  {
    return entries[(i-1)*m + j-1];
  }   // returns the (i,j)-entry
  void set_entry(int i, int j, double x)
  {
    entries[(i-1)*m + j-1] = x;
  } // sets (i,j)-entry to x
  void print() const
  {
    for(auto i{1};i<=n;i++)
    {
      for(auto j{1};j<=m;j++)
      {
        cout<<setw(8)<<entries[(i-1)*m + j-1];
      }
      cout<<'\n';
    }
    cout<<'\n';

  }// prints matrix to the screen row-wise

  Matrix operator+(const Matrix &B) const
  {
    if(n!=B.n||m!=B.m)
    {
      throw logic_error("Dimensions of the matrix are incompatible!");
    }
    else
    {
      vector<double> vec_res{};
      for(auto i{0};i<B.n*B.m;i++)
      {
          vec_res.push_back(entries[i]+B.entries[i]);
      }      
      return {n,m,vec_res};
    }
  }
  Matrix operator-(const Matrix &B) const
  {
    if(n!=B.n||m!=B.m)
    {
      throw logic_error("Dimensions of the matrix are incompatible!");
    }
    else
    {
      vector<double> vec_res{};
      for(auto i{0};i<B.n*B.m;i++)
      {
          vec_res.push_back(entries[i]-B.entries[i]);
      }      
      return {n,m,vec_res};
    }
  }
  Matrix operator*(const Matrix &B) const
  {
    if(m!=B.n)
      throw logic_error("Dimensions of the matrix are incompatible!");
    else
    {
      vector<double> vec_res{};
      for(auto i{1};i<=n;i++)
      {
        for(auto j{1};j<=B.m;j++)
        {
          double element_val{0};
          for(auto k{1};k<=m;k++)
            element_val+=entries[(i-1)*m + k-1]*B.entries[(k-1)*B.m + j-1];
          vec_res.push_back(element_val);
        }
      }
      return {n,B.m,vec_res};

    }

  }
  friend ostream &operator<<(ostream &os, const Matrix &B) {
      B.print();
      return os;
  }

};