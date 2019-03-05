#ifndef ROSTER_H
#define ROSTER_H

#include <vector>
#include <algorithm>
using namespace std;

#include "Student.h"


namespace model
{

class Roster
{
private:
    vector<Student> students;

public:

    //Creates a new roster object.
    //@precondition
    //  none
    //@postcondition
    //  a new roster is created
    Roster();

    //Destroys a roster object.
    virtual ~Roster();

    //Gets and returns a collection of students.
    //@precondition
    //  none
    //@return
    //  a collection of students
    vector<Student> GetStudents();

    //Adds a student to the roster.
    //@precondition
    //  The student cannot be a null pointer.
    //@postcondition
    //  the student is added.
    void AddStudent(Student& student);

    //Will sort the vector by last name.
    //@precondition
    // none
    //@postcondition
    // the vector is sorted by last name
    void SortByLastName();

    //Will sort the vector by first name.
    //@precondition
    // none
    //@postcondition
    //  the vector is sorted by first name
    void SortByFirstName();

    //Gets and returns the size of the Roster's collection.
    //@precondition
    //  none
    //@return
    //  the size of the Roster.
        int Size();

};

}
#endif // ROSTER_H
