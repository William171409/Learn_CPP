#include "q4_1.hpp"
#include "q4_1_template.hpp"

// Operator Overloading & Template & Template Specialization
void q4_1()
{
    OptionWithComparison p1(100), p2(110);  
    std::cout<<mymax(p1, p2)<< "\n";
    OptionWithoutComparison p3(100), p4(110);
    std::cout<<mymax(p3, p4)<< "\n";
}
