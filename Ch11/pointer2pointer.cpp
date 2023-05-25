#include <algorithm> // std::sort
#include <iostream>
#include <string>
int main()
{
    int** array { new int*[10] }; // allocate an array of 10 int pointers — these are our rows
    for (int count { 0 }; count < 10; ++count)
        array[count] = new int[5]; // these are our columns
    array[9][4] = 3; // This is the same as (array[9])[4] = 3;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<5;j++)
            std::cout<<array[i][j]<<' ';
        std::cout<<'\n';
    }
    for (int count { 0 }; count < 10; ++count)
        delete[] array[count];
    delete[] array; // this needs to be done last

    return 0;
}
