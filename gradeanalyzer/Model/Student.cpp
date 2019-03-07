#include "Student.h"

#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;


namespace model
{

Student::Student()
{
#if DEBUG_LEVEL >= 3
    cout << "In Student constructor" << endl;
#endif // DEBUG_LEVEL

    this -> firstName = string();
    this -> lastName = string();
    this -> grade = 0;
}

Student::Student(string firstName, string lastName, int grade)
{
    if (firstName == "")
    {
        throw invalid_argument(NAME_ERROR);
    }
    if (lastName == "")
    {
        throw invalid_argument(NAME_ERROR);
    }
    if (grade < 0 || grade > 100)
    {
        throw invalid_argument(GRADE_ERROR);
    }
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> grade = grade;
}

Student::~Student()
{
#if DEBUG_LEVEL >= 3
    cout << "In Student destructor" << endl;
#endif // DEBUG_LEVEL
}

string Student::getFirstName() const
{
    return this -> firstName;
}

string Student::getLastName() const
{
    return this -> lastName;
}

int Student::getGrade()
{
    return this -> grade;
}

void Student::setFirstName(const string& firstName)
{
    if (firstName.empty())
    {
        throw new invalid_argument(NAME_ERROR);
    }
    this -> firstName = firstName;
}

void Student::setLastName(const string& lastName)
{
    if (firstName.empty())
    {
        throw new invalid_argument(NAME_ERROR);
    }
    this -> lastName = lastName;
}

void Student::setGrade(int grade)
{
    if (grade < 0 || grade > 100)
    {
        throw new invalid_argument(GRADE_ERROR);
    }
    this -> grade = grade;
}

string Student::getDescription()
{
    string first = this -> firstName;
    string last = this -> lastName;
    string grade = to_string(this -> grade);
    string returnString = first + "," + last + "," + grade;

    return returnString;

}

}
