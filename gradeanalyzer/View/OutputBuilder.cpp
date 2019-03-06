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
        this -> studentsWithGradeA.addStudent(student);
    }
    else if (grade > 79)
    {
        this -> studentsWithGradeB.addStudent(student);
    }
    else if (grade > 74)
    {
        this -> studentsWithGradeC.addStudent(student);
    }
    else if (grade > 69)
    {
        this -> studentsWithGradeD.addStudent(student);
    }
    else
    {
        this -> studentsWithGradeF.addStudent(student);
    }
}

void OutputBuilder::sortStudentsIntoGradeCategories(Roster& students)
{
    vector<Student> unsortedStudents = students.getStudents();
    for(Student currentStudent : unsortedStudents)
    {
        int grade = currentStudent.getGrade();
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
    string firstName = this -> setNameToCamalCase(student.getFirstName());
    string lastName = this -> setNameToCamalCase(student.getLastName());
    string returnString = firstName + " " + lastName;
    return returnString;
}

string OutputBuilder::buildStudentDescriptionWithGrade(Student& student)
{
    string returnString = this -> buildStudentDescriptionWithGrade(student);
    int grade = student.getGrade();
    returnString += " (" + to_string(grade) + ")";
    return returnString;
}

void OutputBuilder::buildOutputForGrade(Roster& currentRoster, int columnNumber, int columnWidth, bool includeGrades)
{
    vector<Student> students = currentRoster.getStudents();
    int currentColumn = 1;
    if (includeGrades)
    {
        for (Student currentStudent : students)
        {
            string studentDescription = this -> buildStudentDescriptionWithGrade(currentStudent);
            cout << left << setw(columnWidth) << studentDescription;
            if (currentColumn == columnNumber)
            {
                cout << endl;
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
            cout << left << setw(columnWidth) << studentDescription;
            if (currentColumn == columnNumber)
            {
                cout << endl;
                currentColumn = 1;
            }
            else
            {
                currentColumn++;
            }
        }
    }
    cout << endl;
}

void OutputBuilder::sortAllStudentGroupsByFirstOrLastName(bool sortByLastName)
{
    if (sortByLastName)
    {
        this -> studentsWithGradeA.sortByLastName();
        this -> studentsWithGradeB.sortByLastName();
        this -> studentsWithGradeC.sortByLastName();
        this -> studentsWithGradeD.sortByLastName();
        this -> studentsWithGradeF.sortByLastName();
    }
    else
    {
        this -> studentsWithGradeA.sortByFirstName();
        this -> studentsWithGradeB.sortByFirstName();
        this -> studentsWithGradeC.sortByFirstName();
        this -> studentsWithGradeD.sortByFirstName();
        this -> studentsWithGradeF.sortByFirstName();
    }
}

void OutputBuilder::buildGradeHistogram()
{
    int numberOfGradeA = this -> studentsWithGradeA.size();
    int numberOfGradeB = this -> studentsWithGradeB.size();
    int numberOfGradeC = this -> studentsWithGradeC.size();
    int numberOfGradeD = this -> studentsWithGradeD.size();
    int numberOfGradeF = this -> studentsWithGradeF.size();
    string gradeAHistogramBar(numberOfGradeA, '*');
    string gradeBHistogramBar(numberOfGradeB, '*');
    string gradeCHistogramBar(numberOfGradeC, '*');
    string gradeDHistogramBar(numberOfGradeD, '*');
    string gradeFHistogramBar(numberOfGradeF, '*');


    string returnString = "Grade Histogram:\n";
    cout << "A: " << gradeAHistogramBar << endl;
    cout << "B: " << gradeBHistogramBar << endl;
    cout << "C: " << gradeCHistogramBar << endl;
    cout << "D: " << gradeDHistogramBar << endl;
    cout << "F: " << gradeFHistogramBar << endl;
}

string OutputBuilder::buildFileOutput(Roster students)
{
    vector<Student> outputStudents = students.getStudents();
    string returnString;
    for (Student currentStudent : outputStudents)
    {
        returnString += currentStudent.getDescription() + "\n";
    }
    return returnString;
}

void OutputBuilder::buildFullOutput(Roster& students, int columnNumber, int columnWidth, bool includeGrades, bool sortByLastName, bool displayHistogram)
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
    string baseStatementString = "Students earning an ";

    if (this -> studentsWithGradeA.size() != 0)
    {
        cout << baseStatementString << "A" << endl;
        this -> buildOutputForGrade(this -> studentsWithGradeA, columnNumber, columnWidth, includeGrades);
    }
    if (this -> studentsWithGradeB.size() != 0)
    {
        cout << baseStatementString << "A" << endl;
        this -> buildOutputForGrade(this -> studentsWithGradeB, columnNumber, columnWidth, includeGrades);
    }
    if (this -> studentsWithGradeC.size() != 0)
    {
        cout << baseStatementString << "A" << endl;
        this -> buildOutputForGrade(this -> studentsWithGradeC, columnNumber, columnWidth, includeGrades);
    }
    if (this -> studentsWithGradeD.size() != 0)
    {
        cout << baseStatementString << "A" << endl;
        this -> buildOutputForGrade(this -> studentsWithGradeD, columnNumber, columnWidth, includeGrades);
    }
    if (this -> studentsWithGradeF.size() != 0)
    {
        cout << baseStatementString << "A" << endl;
        this -> buildOutputForGrade(this -> studentsWithGradeF, columnNumber, columnWidth, includeGrades);
    }
    if (displayHistogram)
    {
        this -> buildGradeHistogram();
    }
}

void OutputBuilder::displayUsageStatement()
{
    cout << "Usage: gradeanalyzer infile [outfile] [options]" << endl;
    cout << "Performs a simple grade analysis of the students and grades contained in infile." << endl;

    cout << left << setw(20) << "infile" << left << setw(100) << "The input file to analyze the grades of." << endl;
    cout << left << setw(20) << "outfile" << left << setw(100) << "The output file to write the output to." << endl;

    cout << "Options:" << endl;

    cout << left << setw(20) << "--help" << left << setw(100) << "Displays this usage statement." << endl;
    cout << left << setw(20) << "-c <number>" << left << setw(100) << "Changes the number of output columns to the number specified. The default number of columns is 4." << endl;
    cout << left << setw(20) << "-a <first last grade>" << left << setw(100) << "Add the specified student (case insensitive) to the output. E.g., -a john doe 85 would add john doe with a 85 grade to output." << endl;
    cout << left << setw(20) << "-g" << left << setw(100) << "Displays student grade with the output." << endl;
    cout << left << setw(20) << "-h" << left << setw(100) << "Displays a histogram of the grades in addition to the other output" << endl;
    cout << left << setw(20) << "-sf" << left << setw(100) << "Displays the output in alphabetic order by student’s first name. The default order is by student’s last name." << endl;
    cout << left << setw(20) << "-w <number>" << left << setw(100) << "Changes the column width for the output columns. The default column width is 20." << endl;
    cout << endl;
}

}
