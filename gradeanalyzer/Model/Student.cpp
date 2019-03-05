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

Student::~Student()
{
#if DEBUG_LEVEL >= 3
    cout << "In Student destructor" << endl;
#endif // DEBUG_LEVEL
}

string Student::GetFirstName() const
{
    return this -> firstName;
}

string Student::GetLastName() const
{
    return this -> lastName;
}

int Student::GetGrade()
{
    return this -> grade;
}

void Student::SetFirstName(const string& firstName)
{
    if (firstName.empty())
    {
            throw new invalid_argument("The first name cannot be empty!");
    }
    this -> firstName = firstName;
}

void Student::SetLastName(const string& lastName)
{
    if (firstName.empty())
    {
        throw new invalid_argument("The last name cannot be empty!");
    }
    this -> lastName = lastName;
}

void Student::SetGrade(int grade)
{
    if (grade < 0)
    {
        throw new invalid_argument("The grade cannot be less than 0");
    }
    this -> grade = grade;
}

string Student::GetDescription()
{
    string first = this -> firstName;
    string last = this -> lastName;
    string grade = to_string(this -> grade);
    string returnString = first + "," + last + "," + grade;

    return returnString;

}

}
