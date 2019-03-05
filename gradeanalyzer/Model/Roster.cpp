#include "Roster.h"

namespace model
{

Roster::Roster()
{
#if DEBUG_LEVEL >= 3
    cout << "In Roster constructor" << endl;
#endif // DEBUG_LEVEL
}

Roster::~Roster()
{
#if DEBUG_LEVEL >= 3
    cout << "In Roster destructor" << endl;
#endif // DEBUG_LEVEL
}

vector<Student> Roster::GetStudents()
{
    return this -> students;
}

void Roster::AddStudent(Student& student)
{
    this -> students.push_back(student);
}

bool compareStudentsByLastName(const Student &firstStudent, const Student &secondStudent)
{
    return firstStudent.GetLastName() < secondStudent.GetLastName();
}

void Roster::SortByLastName()
{
    sort(this -> students.begin(), this -> students.end(), compareStudentsByLastName);
}

bool compareStudentsByFirstName(const Student &firstStudent, const Student &secondStudent)
{
    return firstStudent.GetFirstName() < secondStudent.GetFirstName();
}

void Roster::SortByFirstName()
{
    sort(this -> students.begin(), this -> students.end(), compareStudentsByFirstName);
}

int Roster::Size()
{
    return this -> students.size();
}



}
