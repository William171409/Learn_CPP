// Write the following program: Create a struct that holds a student’s
// first name and grade (on a scale of 0-100). Ask the user how many students
// they want to enter. Create a std::vector to hold all of the students.
// Then prompt the user for each name and grade. Once the user has entered
// all the names and grade pairs, sort the list by grade (highest first).
// Then print all the names and grades in sorted order.
#include <iostream>
#include <array>
#include <vector>
#include <iterator>
#include <string>
struct Students
{
    std::string firstName{};
    double grade{};
};

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
template <typename T>
T getStudentNumber()
{
    T studentNumber{};
    while (true)
    {

        std::cin >> studentNumber;
        if (!std::cin)
        {
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine();     // and remove the bad input
            std::cerr << "Oops, that input type is invalid. Please try again.\n\n";
        }
        else if (studentNumber < 0 || studentNumber > 100)
        {
            /* code */
            ignoreLine();
            std::cout << "Number out of range. Please try again!\n\n";
        }
        else
        {
            ignoreLine();
            return studentNumber;
        }
    }
}
std::string getString()
{
    std::string name{};
    std::getline(std::cin >> std::ws, name);
    return name;
}
void getStudentInfo(std::vector<Students> &vec, int index)
{
    vec.emplace_back();
    std::cout << "Student " << index << "'s grade: ";
    vec[index].grade = getStudentNumber<double>();
    std::cout << "Student " << index << "'s firstname: ";
    vec[index].firstName = getString();
}
bool greater(const Students &a, const Students &b)
{
    // Order @a before @b if @a is greater than @b.
    return (a.grade > b.grade);
}

int main()
{
    std::cout << "How many students are there? ";
    int studentNumber{getStudentNumber<int>()};
    std::vector<Students> student_vec{};
    for (int i{}; i < studentNumber; i++)
    {
        getStudentInfo(student_vec, i);
    }
    std::sort(student_vec.begin(), student_vec.end(), greater);
    std::cout << "\n\n";
    for (const Students &student : student_vec)
    {
        std::cout << student.firstName << " got a grade of " << student.grade << '\n';
    }

    return 0;
}
