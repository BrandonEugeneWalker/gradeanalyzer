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

vector<Student> Roster::getStudents()
{
    return this -> students;
}

void Roster::addStudent(Student& student)
{
    this -> students.push_back(student);
}

bool compareStudentsByLastName(const Student &firstStudent, const Student &secondStudent)
{
    return firstStudent.getLastName() < secondStudent.getLastName();
}

void Roster::sortByLastName()
{
    sort(this -> students.begin(), this -> students.end(), compareStudentsByLastName);
}

bool compareStudentsByFirstName(const Student &firstStudent, const Student &secondStudent)
{
    return firstStudent.getFirstName() < secondStudent.getFirstName();
}

void Roster::sortByFirstName()
{
    sort(this -> students.begin(), this -> students.end(), compareStudentsByFirstName);
}

int Roster::size()
{
    return this -> students.size();
}

void Roster::merge(Roster roster)
{
    vector<Student> rosterCollection = roster.getStudents();
    this -> students.reserve(students.size() + rosterCollection.size());
    this -> students.insert(students.end(), rosterCollection.begin(), rosterCollection.end());
}



}
