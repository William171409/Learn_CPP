#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    int m_id{};
    std::string m_name{};

public:
    Employee(int id=0, std::string_view name=""):
        m_id{ id }, m_name{ name }
    {
        std::cout << "Employee " << m_name << " created. ID: "<<m_id<<'\n';
    }

    // Use a delegating constructor to minimize redundant code
    Employee(std::string_view name) : Employee{ 0, name }
    { }
    //TO understand these two constructors, the first constructor we can use list initializer to
    //provide both arguments, no arguments or first argument and using second default value as argument
    // the second constructor we use it to provide the second argument
};

int main()
{

    Employee e1{"bhjk"};
    return 0;
}