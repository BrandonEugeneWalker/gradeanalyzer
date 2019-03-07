#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

#define NAME_ERROR "A name cannot be empty."
#define GRADE_ERROR "A grade must be between 0 and 100 inclusive."


namespace model
{



class Student
{
private:
    string firstName;
    string lastName;
    int grade;

public:
    //Creates a new Student object with default values.
    //@precondition
    //  none
    //@postcondition
    //  A new student object is created with default values.
    Student();

    //Creates a new Student object with the given parameters.
    //@precondition
    //  first name cannot be empty
    //  last name cannot be empty
    // grade must be between 0 and 100 inclusive
    //@postcondition
    //  a new student is created
    //@para firstName
    //  the first name
    //@para lastName
    //  the last name
    //@para grade
    //  the grade
    Student(string firstName, string lastName, int grade);

    //Destroys a student object.
    virtual ~Student();

    //Gets the first name of a student.
    //@precondition
    //  none
    //@return
    //  the student's first name
    string getFirstName() const;

    //Gets the last name of a student.
    //@precondition
    //  none
    //@return
    //  the student's last name
    string getLastName() const;

    //Gets the student's grade.
    //@precondition
    //  none
    //@return
    //  the student's grade
    int getGrade();

    //Sets the first name of a student.
    //@precondition
    //  the first name cannot be none
    //@postcondition
    //  the first name is set
    //@para firstName
    //  the first name
    void setFirstName(const string& firstName);

    //Sets the last name of a student.
    //@precondition
    //  the last name cannot be none
    //@postcondition
    //  the last name is set
    //@para lastName
    //  the last name
    void setLastName(const string& lastName);

    //Sets the grade of a student.
    //@precondition
    //  grade must be between 0 and 100 inclusive
    //@postcondition
    //  the grade is set
    //@para grade
    //  the grade
    void setGrade(int grade);

    //Gets the combined description of the Student.
    //@precondition
    //  none
    //@return
    //  a description of the student
    string getDescription();



};

}

#endif // STUDENT_H
