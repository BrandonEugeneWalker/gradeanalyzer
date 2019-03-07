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
    vector<Student> getStudents();

    //Adds a student to the roster.
    //@precondition
    //  The student cannot be a null pointer.
    //@postcondition
    //  the student is added.
    //@para student
    //  the student to add
    void addStudent(Student& student);

    //Will sort the vector by last name.
    //@precondition
    // none
    //@postcondition
    // the vector is sorted by last name
    void sortByLastName();

    //Will sort the vector by first name.
    //@precondition
    // none
    //@postcondition
    //  the vector is sorted by first name
    void sortByFirstName();

    //Gets and returns the size of the Roster's collection.
    //@precondition
    //  none
    //@return
    //  the size of the Roster.
    int size();

    //Merges the given roster into the target roster.
    //@precondition
    //  none
    //@postcondition
    //  the rosters are merged.
    //@para roster
    //  the roster to merge with
    void merge(Roster roster);

};

}
#endif // ROSTER_H
