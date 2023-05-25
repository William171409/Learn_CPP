#include <vector>
#include <iostream>

int main()
{
  std::vector<int> array{5,0};
  array = { 0, 1, 2, 3, 4 }; // okay, array length = 5
  std::cout << "length: " << array.size() << "  capacity: " << array.capacity() << '\n';

  array = { 9, 8, 7 }; // okay, array length is now 3!
  std::cout << "length: " << array.size() << "  capacity: " << array.capacity() << '\n';
    
    //Can we still access the memory in array[3]
    //at() are based on length, not capacity
    std::cout<<array.at(4)<<'\n'; //weird!
    
  return 0;
}