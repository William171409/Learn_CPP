#include <iostream>
#include <string>
void foo(const int* p)
{
    std::cout<<p[2]<<'\n';
}
struct StudentGrade
{
    std::string name{};
    char grade{};
};
int main()
{
    int arr[]{12, 45, 85};
    int *p = arr;
    std::cout << arr[0] << ' ' << p[0] << '\n';
    foo(p);
    StudentGrade s1{"Michael"};
    std::cout<<s1.name<<"'s grade is "<<s1.grade<<'\n';

    return 0;
}