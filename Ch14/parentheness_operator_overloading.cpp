// There are two things to keep in mind: first, the parenthesis operator must be implemented 
// as a member function. Second, in non-object-oriented C++, 
// the () operator is used to call functions. In the case of classes, 
// operator() is just a normal operator that calls a function (named operator()) like 
// any other overloaded operator.
#include <iostream>
#include <cassert> // for assert()
class Matrix
{
private:
    double m_data[4][4]{};

public:
    double& operator()(int row, int col);
    double operator()(int row, int col) const;
    void operator()();
};

double& Matrix::operator()(int row, int col)
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return m_data[row][col];
}

double Matrix::operator()(int row, int col) const
{
    assert(col >= 0 && col < 4);
    assert(row >= 0 && row < 4);

    return m_data[row][col];
}

void Matrix::operator()()
{
    // reset all elements of the matrix to 0.0
    for (int row{ 0 }; row < 4; ++row)
    {
        for (int col{ 0 }; col < 4; ++col)
        {
            m_data[row][col] = 0.0;
        }
    }
}

int main()
{
    Matrix m{};
    m(1,3)=66;
    std::cout<<m(1,3)<<'\n';
    m();
    std::cout<<m(1,3)<<'\n';
    

    return 0;
}