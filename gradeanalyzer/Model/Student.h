#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

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
        void setFirstName(const string& firstName);

        //Sets the last name of a student.
        //@precondition
        //  the last name cannot be none
        //@postcondition
        //  the last name is set
        void setLastName(const string& lastName);

        //Sets the grade of a student.
        //@precondition
        //  grade must be greater than or equal to 0
        //@postcondition
        //  the grade is set
        void setGrade(int grade);


};

#endif // STUDENT_H
