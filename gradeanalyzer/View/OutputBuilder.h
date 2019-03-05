#ifndef OUTPUTBUILDER_H
#define OUTPUTBUILDER_H

#include <string>
#include <stdexcept>
using namespace std;

#include "Student.h"
#include "Roster.h"
using namespace model;

namespace view
{



class OutputBuilder
{
private:
    Roster studentsWithGradeA;
    Roster studentsWithGradeB;
    Roster studentsWithGradeC;
    Roster studentsWithGradeD;
    Roster studentsWithGradeF;

    void determineStudentPlacement(Student& student, int grade);

    void sortStudentsIntoGradeCategories(Roster& students);

    string addSpacePaddingToColumn(string& studentDescription, int columnWidth);

    void sortAllStudentGroupsByFirstOrLastName(bool sortByLastName);

    string buildOutputForGrade(Roster& currentRoster, int columnNumber, int columnWidth, bool includeGrades);

    string setNameToCamalCase(string name);

    string buildStudentDescriptionWithoutGrade(Student& student);

    string buildStudentDescriptionWithGrade(Student& student);



public:
    //Creates a new instance of a OutputBuilder.
    //@precondition
    // none
    //@postcondition
    // a new OutputBuilder is created.
    OutputBuilder();

    //De-constructs a OutputBuilder.
    virtual ~OutputBuilder();

    //Builds the string output in a format for file output.
    //@precondition
    //  none
    //@return
    //  a string containing the file output
    string BuildFileOutput(Roster students);

    //Builds the string output for the console based on a variety of parameters.
    //@precondition
    //  column number cannot be less than or equal to zero
    //  column width cannot be less than or equal to zero
    //@postcondition
    //  the console output is built
    //@para students
    //  the unsorted roster of students.
    //@para columnNumber
    //  the number of columns in the console output
    //@para columnWidth
    //  the character width of each column
    //@para includeGrades
    //  true if grades are included in the output
    //@para sortByLastName
    //  true if sorting by last name, false if sorting by first name.
    string BuildFullOutput(Roster& students, int columnNumber, int columnWidth, bool includeGrades, bool sortByLastName);

};

}

#endif // OUTPUTBUILDER_H
