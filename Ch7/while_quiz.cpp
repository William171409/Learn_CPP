#include <iostream>

// Q2
//  int main()
//  {
//      char ch = 'a';
//      while (ch <= 'z')
//      {
//          std::cout << ch << ' ';
//          ch++;
//      }
//      std::cout <<'\n';
//      return 0;
//  }

// Q3
// int main()
// {
//     int outer{matrix_size};
//     while (outer > 0)
//     {
//         int inner{outer};
//         while (inner > 0)
//         {
//             std::cout << inner << ' ';
//             inner--;
//         }
//         std::cout<<'\n';
//         outer--;
//     }
//     return 0;
// }

// Q4
int main()
{
    int matrix_size{5};
    int outer{1};
    while (outer <= matrix_size)
    {
        int inner{matrix_size};
        while (inner > 0)
        {
            if (inner > outer)
                std::cout << "  ";
            else
            {
                std::cout << inner << ' ';
            }
            inner--;
        }
        std::cout << '\n';
        outer++;
    }
    return 0;
}