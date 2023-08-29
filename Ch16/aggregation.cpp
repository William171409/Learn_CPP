#include <iostream>
#include <functional>
#include <string>
#include <vector>


// To qualify as an aggregation, a whole object and its parts must have the following relationship:

// The part (member) is part of the object (class)
// The part (member) can (if desired) belong to more than one object (class) at a time
// The part (member) does not have its existence managed by the object (class)
// The part (member) does not know about the existence of the object (class)
class Teacher
{
    std::string m_name{};
public:
    Teacher(std::string name ): m_name{name}
    {

    }
    
    const std::string&  getName() const { return m_name; }

};

class Department
{
private:
    std::vector<std::reference_wrapper<Teacher>> teacher_vec{};
//   const Teacher& m_teacher; // This dept holds only one teacher for simplicity, but it could hold many teachers

public:
    Department(){}

    void add(Teacher& teacher)
    {
        teacher_vec.push_back(teacher);
    }
    friend void printDepartment(const Department& dept);
};

void printDepartment(const Department& dept)
{
    for(auto teacher:dept.teacher_vec)
    {
        std::cout<<"Teacher's name is "<<teacher.get().getName()<<'\n';
    }
}


int main()
{
  // Create a teacher outside the scope of the Department
  Teacher t1{ "Bob" };
  Teacher t2{ "Frank" };
  Teacher t3{ "Beth" };

  {
    // Create a department and add some Teachers to it
    Department department{}; // create an empty Department

    department.add(t1);
    department.add(t2);
    department.add(t3);
    printDepartment(department);

    
  } // department goes out of scope here and is destroyed

  std::cout << t1.getName() << " still exists!\n";
  std::cout << t2.getName() << " still exists!\n";
  std::cout << t3.getName() << " still exists!\n";

  return 0;
}