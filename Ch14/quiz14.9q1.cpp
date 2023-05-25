#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


struct StudentGrade
{
    std::string name{};
    char grade{};
};
class GradeMap
{
    std::vector<StudentGrade> m_map{};
public:
    char& operator[](std::string n)
    {   
        auto flag = std::find_if(m_map.begin(),m_map.end(),[n](const StudentGrade& s)
        {
            return n==s.name;
        });
        if(flag!=m_map.end())
            return flag->grade;
        else
        {
            m_map.push_back({n,'?'});
            return m_map.back().grade;
        }
    }
};
int main()
{
    GradeMap grades{};
	grades["Joe"] = 'A';
	grades["Frank"] = 'B';
	grades["Frank"] = 'F';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';
	std::cout << "Marco has a grade of " << grades["Marco"] << '\n';

    return 0;
}


// int main()
// {
// 	GradeMap grades{};

// 	char& gradeJoe{ grades["Joe"] }; // does a push_back
// 	gradeJoe = 'A';

// 	char& gradeFrank{ grades["Frank"] }; // does a push_back
// 	gradeFrank = 'B';

// 	std::cout << "Joe has a grade of " << gradeJoe << '\n';
// 	std::cout << "Frank has a grade of " << gradeFrank << '\n';

// 	return 0;
// }