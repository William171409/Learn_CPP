#include <iostream>
#include <iterator>

enum StudentNames
{
    kenny,       // 0
    kyle,        // 1
    stan,        // 2
    butters,     // 3
    cartman,     // 4
    wendy,       // 5
    max_students // 6
};

// void printSize(int array[])
// {
//     std::cout << std::size(array) << '\n'; // Error
// }
int main()
{
    // int array[5]{};         // uninitialized (since int doesn't self-initialize) In this case, the array will store the garbage values
    const int array[5]{1}; //
    std::cout << array[0] << '\n';
    std::cout << array[1] << '\n';
    std::cout << array[2] << '\n';
    std::cout << array[3] << '\n';
    std::cout << array[4] << '\n';

    int testScores[max_students]{}; // allocate 6 integers
    testScores[stan] = 76;          // still works
    std::cout<<"Stan's score is "<<*(testScores+2)<<'\n';
    std::cout<<"Stan's score is "<<testScores[2]<<'\n';
    std::cout<<"Stan's score is "<<*(&testScores[0]+2)<<'\n';
    //Notice that the name of the array is essentially a pointer that stores the address of
    //the first element of the array
    //Thus, &array[0] == array ->TRUE!!!!!!!!!!!!!!!1


    int array2[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << std::size(array2) << '\n'; // will print the size of the array in C++17!!!
    // printSize(array2); 
    //ARRAY is essentially a pointer, if we want to get the size of this
    // array. Use
    

    return 0;
}




