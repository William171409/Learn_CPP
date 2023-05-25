// My implementation insertion sort
#include <iostream>
#include <iterator> // for std::size
#include <utility>

namespace improved
{   
        template <typename T>
        void bubbleSort(T p, int size_array)
        {
            for(int i=0;i<size_array-1;i++)
            {
                int counter{};
                for(int j=0;j<size_array-1-i;j++)
                {
                    if(p[j]>p[j+1])
                    {
                        std::swap(p[j],p[j+1]);
                        counter++;
                    }
                }
                if(!counter)
                {
                    std::cout<<"Early termination on iteration "<<(i+1)<<std::endl;
                    break;
                }
            }
        } 
        template void bubbleSort(int* p, int size_array);
} // namespace improved

