#ifndef OUTPUTBUILDER_H
#define OUTPUTBUILDER_H

#include <string>
#include <stdexcept>
#include <iostream>
#include <iomanip>
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

    void buildOutputForGrade(Roster& currentRoster, int columnNumber, int columnWidth, bool includeGrades);

    string setNameToCamalCase(string name);

    string buildStudentDescriptionWithoutGrade(Student& student);

    string buildStudentDescriptionWithGrade(Student& student);

    void buildGradeHistogram();



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
    string buildFileOutput(Roster students);

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
    //@para displayHistogram
    //  true if displaying the histogram after the summary, false if not
    void buildFullOutput(Roster& students, int columnNumber, int columnWidth, bool includeGrades, bool sortByLastName, bool displayHistogram);

    //Displays the usage statement of the program.
    //@precondition
    //  none
    //@postcondition
    //  the usage statement is printed out
    void displayUsageStatement();

};

}

#endif // OUTPUTBUILDER_H
