#include <iostream>
#include <utility>

#ifndef INSERTIONSORT_HPP
#define INSERTIONSORT_HPP
namespace improved
{   
        template <typename T>
        void insertionSort(T p, int size_array)
        {
            for(int i=0;i<size_array-1;i++)
            {
                int counter{};
                for(int j{size_array-1};j>i;j--)
                {
                    if(p[j]<p[j-1])
                    {
                        std::swap(p[j],p[j-1]);
                        counter++;
                    }
                }
                for (int index{0}; index < size_array; ++index)
                {
                    std::cout << p[index] << ' ';
                }
                std::cout << '\n';
                if(!counter)
                {
                    std::cout<<"Early termination on iteration "<<(i+1)<<std::endl;
                    break;
                }
            }
        } 
} // namespace improved
#endif