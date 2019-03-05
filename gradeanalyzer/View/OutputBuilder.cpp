#include "OutputBuilder.h"

namespace view
{



OutputBuilder::OutputBuilder()
{
#if DEBUG_LEVEL >= 3
    cout << "In OutputBuilder constructor" << endl;
#endif // DEBUG_LEVEL
}

OutputBuilder::~OutputBuilder()
{
#if DEBUG_LEVEL >= 3
    cout << "In OutputBuilder destructor" << endl;
#endif // DEBUG_LEVEL
}

string OutputBuilder::addSpacePaddingToColumn(string& studentDescription, int columnWidth)
{
    int descriptionSize = studentDescription.size();
    int difference = columnWidth - descriptionSize;
    string returnString;

    if (difference > 0)
    {
        string padding(difference, ' ');
        returnString = studentDescription + padding;
    }
    else
    {
        returnString = studentDescription;
        for(int i = 0; i > abs(difference); i++)
        {
            returnString.pop_back();
        }
    }
    return returnString;
}

void OutputBuilder::determineStudentPlacement(Student& student, int grade)
{
    if (grade > 89)
    {
        this -> studentsWithGradeA.AddStudent(student);
    }
    else if (grade > 79)
    {
        this -> studentsWithGradeB.AddStudent(student);
    }
    else if (grade > 74)
    {
        this -> studentsWithGradeC.AddStudent(student);
    }
    else if (grade > 69)
    {
        this -> studentsWithGradeD.AddStudent(student);
    }
    else
    {
        this -> studentsWithGradeF.AddStudent(student);
    }
}

void OutputBuilder::sortStudentsIntoGradeCategories(Roster& students)
{
    vector<Student> unsortedStudents = students.GetStudents();
    for(Student currentStudent : unsortedStudents)
    {
        int grade = currentStudent.GetGrade();
        determineStudentPlacement(currentStudent, grade);
    }
}

string OutputBuilder::setNameToCamalCase(string name)
{
    string returnString;
    int count = 1;
    for(char currentChar : name)
    {
        if (count == 1)
        {
            returnString += toupper(currentChar);
        }
        else
        {
            returnString += tolower(currentChar);
        }
    }
    return returnString;
}

string OutputBuilder::buildStudentDescriptionWithoutGrade(Student& student)
{
    string firstName = this -> setNameToCamalCase(student.GetFirstName());
    string lastName = this -> setNameToCamalCase(student.GetLastName());
    string returnString = firstName + " " + lastName;
    return returnString;
}

string OutputBuilder::buildStudentDescriptionWithGrade(Student& student)
{
    string returnString = this -> buildStudentDescriptionWithGrade(student);
    int grade = student.GetGrade();
    returnString += " (" + to_string(grade) + ")";
    return returnString;
}

string OutputBuilder::buildOutputForGrade(Roster& currentRoster, int columnNumber, int columnWidth, bool includeGrades)
{
    vector<Student> students = currentRoster.GetStudents();
    string returnString;
    int currentColumn = 1;
    if (includeGrades)
    {
        for (Student currentStudent : students)
        {
            string studentDescription = this -> buildStudentDescriptionWithGrade(currentStudent);
            string paddedDescription = this -> addSpacePaddingToColumn(studentDescription, columnWidth);
            returnString += paddedDescription;
            if (currentColumn == columnNumber)
            {
                returnString += "\n";
                currentColumn = 1;
            }
            else
            {
                currentColumn++;
            }
        }
    }
    else
    {
        for (Student currentStudent : students)
        {
            string studentDescription = this -> buildStudentDescriptionWithoutGrade(currentStudent);
            string paddedDescription = this -> addSpacePaddingToColumn(studentDescription, columnWidth);
            returnString += paddedDescription;
            if (currentColumn == columnNumber)
            {
                returnString += "\n";
                currentColumn = 1;
            }
            else
            {
                currentColumn++;
            }
        }
    }
    returnString += "\n";
    return returnString;

}

void OutputBuilder::sortAllStudentGroupsByFirstOrLastName(bool sortByLastName)
{
    if (sortByLastName)
    {
        this -> studentsWithGradeA.SortByLastName();
        this -> studentsWithGradeB.SortByLastName();
        this -> studentsWithGradeC.SortByLastName();
        this -> studentsWithGradeD.SortByLastName();
        this -> studentsWithGradeF.SortByLastName();
    }
    else
    {
        this -> studentsWithGradeA.SortByFirstName();
        this -> studentsWithGradeB.SortByFirstName();
        this -> studentsWithGradeC.SortByFirstName();
        this -> studentsWithGradeD.SortByFirstName();
        this -> studentsWithGradeF.SortByFirstName();
    }
}

string OutputBuilder::buildGradeHistogram()
{
    int numberOfGradeA = this -> studentsWithGradeA.Size();
    int numberOfGradeB = this -> studentsWithGradeB.Size();
    int numberOfGradeC = this -> studentsWithGradeC.Size();
    int numberOfGradeD = this -> studentsWithGradeD.Size();
    int numberOfGradeF = this -> studentsWithGradeF.Size();
    string gradeAHistogramBar(numberOfGradeA, '*');
    string gradeBHistogramBar(numberOfGradeB, '*');
    string gradeCHistogramBar(numberOfGradeC, '*');
    string gradeDHistogramBar(numberOfGradeD, '*');
    string gradeFHistogramBar(numberOfGradeF, '*');


    string returnString = "Grade Histogram:\n";
    returnString += "A: " + gradeAHistogramBar + "\n";
    returnString += "B: " + gradeBHistogramBar + "\n";
    returnString += "C: " + gradeCHistogramBar + "\n";
    returnString += "D: " + gradeDHistogramBar + "\n";
    returnString += "F: " + gradeFHistogramBar + "\n";

    return returnString;
}

string OutputBuilder::BuildFileOutput(Roster students)
{
    vector<Student> outputStudents = students.GetStudents();
    string returnString;
    for (Student currentStudent : outputStudents)
    {
        returnString += currentStudent.GetDescription() + "\n";
    }
    return returnString;
}

string OutputBuilder::BuildFullOutput(Roster& students, int columnNumber, int columnWidth, bool includeGrades, bool sortByLastName, bool displayHistogram)
{
    if (columnNumber <= 0)
    {
        throw new invalid_argument("Column number must be a positive integer.");
    }
    if (columnWidth <= 0)
    {
        throw new invalid_argument("Column width must be a positive integer.");
    }

    this -> sortStudentsIntoGradeCategories(students);
    this -> sortAllStudentGroupsByFirstOrLastName(sortByLastName);
    string returnString;
    string baseStatementString = "Students earning an ";

    if (this -> studentsWithGradeA.Size() != 0)
    {
        returnString += baseStatementString + "A" + "\n";
        returnString += this -> buildOutputForGrade(this -> studentsWithGradeA, columnNumber, columnWidth, includeGrades);
        returnString += "\n";
    }
    if (this -> studentsWithGradeB.Size() != 0)
    {
        returnString += baseStatementString + "B" + "\n";
        returnString += this -> buildOutputForGrade(this -> studentsWithGradeB, columnNumber, columnWidth, includeGrades);
        returnString += "\n";
    }
    if (this -> studentsWithGradeC.Size() != 0)
    {
        returnString += baseStatementString + "C" + "\n";
        returnString += this -> buildOutputForGrade(this -> studentsWithGradeC, columnNumber, columnWidth, includeGrades);
        returnString += "\n";
    }
    if (this -> studentsWithGradeD.Size() != 0)
    {
        returnString += baseStatementString + "D" + "\n";
        returnString += this -> buildOutputForGrade(this -> studentsWithGradeD, columnNumber, columnWidth, includeGrades);
        returnString += "\n";
    }
    if (this -> studentsWithGradeF.Size() != 0)
    {
        returnString += baseStatementString + "F" + "\n";
        returnString += this -> buildOutputForGrade(this -> studentsWithGradeF, columnNumber, columnWidth, includeGrades);
        returnString += "\n";
    }
    if (displayHistogram)
    {
        returnString += this -> buildGradeHistogram();
    }

    return returnString;


}

}
