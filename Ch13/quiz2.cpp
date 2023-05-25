#include <iostream>
#include <cstring> // for strlen, strcpy
#include <string_view>
class HelloWorld
{
private:
    char *m_data{};

public:
    HelloWorld()
    {
        m_data = new char[14];
        const std::string_view init{"Hello, World!?"};
        for (int i = 0; i < 14; ++i)
            m_data[i] = init[i];
    }
    HelloWorld(const std::string_view sv)
    {
        m_data = new char[14];
        if (sv.size() >= 14)
        {
            for (int i = 0; i < 14; ++i)
                m_data[i] = sv[i];
        }
        else
        {
            for (int i = 0; i < sv.size(); ++i)
                m_data[i] = sv[i];
        }
    }

    ~HelloWorld()
    {
        // replace this comment with your destructor implementation
        delete[] m_data;
    }

    void print() const
    {
        std::cout << m_data << '\n';
    }
};

int main()
{
    HelloWorld hello1{"jfkwal jklew flwe "};  //Call HelloWorld(const std::string_view sv)
    hello1.print();
    HelloWorld hello2{""}; //Call HelloWorld(const std::string_view sv)
    hello2.print();
    HelloWorld hello3{}; //Call HelloWorld() default constructor
    hello3.print();
    return 0;              
}