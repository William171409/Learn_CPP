#include <iostream>
#include <vector>
using namespace std;
#include "matrix.h"

int main() {
  {
    cout << "test creation"
         << "\n";

    Matrix A1(2, 2, {1, 2, 3, 4});
    vector<double> vd{1, 2, 3, 4};
    Matrix A2(2, 2, vd);
    Matrix A3;           // empty matrix of 0x0
    Matrix A4(2, 2);     // matrix of 2x2 with all entries =0
    Matrix A5(2, 2, 1.); // matrix of 2x2 with all entries =1.

    A1.print();
    A2.print();
    A3.print();
    A4.print();
    A5.print();
  }

  {
    Matrix A(3, 3);
    cout << "Number of rows and columns:"
         << "\n";
    cout << A.rows() << "\n";
    cout << A.columns() << "\n";
    A.set_entry(1, 1, 0.34384);
    cout << "(1,1)-entry of A: ";
    cout << A.get_entry(1, 1) << "\n"; // output 0.34384
    cout << "Matrix A:"
         << "\n";
    A.print();
  }

  {
    cout << "Test arithmetic"
         << "\n";
    Matrix A(2, 2);
    A.set_entry(1, 1, 1);
    A.set_entry(2, 2, 1);
    A.set_entry(1, 2, 2);
    A.set_entry(2, 1, 1);
    A.print();

    cout << "\n";
    (A + A).print();
    cout << "\n";
    (A * (A + A)).print();
    cout << "\n";
    Matrix B;
    cout << "Matrix B: "
         << "\n";
    B = A * A * A * A * A;
    B.print();
    cout << B << "\n";

    cout << "A+B: "
         << "\n";
    (A + B).print();
    cout << "A*B: "
         << "\n";
    (A * B).print();

    Matrix C = B - A;
    cout << "Matrix C: "
         << "\n";
    cout << C << "\n";
  }
}