#include "FileReader.h"

namespace IO
{



FileReader::FileReader()
{
#if DEBUG_LEVEL > 3
        cout << "In FileReader constructor" << endl;
#endif // DEBUG_LEVEL
}

FileReader::~FileReader()
{
#if DEBUG_LEVEL > 3
    cout << "In FileReader destructor" << endl;
#endif // DEBUG_LEVEL
}

Student FileReader::buildStudentFromString(string inputString)
{
    string firstName;
    string lastName;
    string gradeString;
    int commaCount = 0;
    for (char currentChar : inputString)
    {
        if (currentChar == ',')
        {
            commaCount++;
        }
        else if (commaCount == 0)
        {
            firstName += currentChar;
        }
        else if (commaCount == 1)
        {
            lastName += currentChar;
        }
        else if(commaCount == 2)
        {
            gradeString += currentChar;
        }
    }
    int grade = stoi(gradeString);
    Student returnStudent(firstName, lastName, grade);
    return returnStudent;
}

Roster FileReader::buildRosterFromFile(vector<string> loadedFile)
{
    Roster returnRoster;
    for (string currentString : loadedFile)
    {
        Student newStudent = this -> buildStudentFromString(currentString);
        returnRoster.addStudent(newStudent);
    }
    return returnRoster;
}

Roster FileReader::readFile(const string& fileName)
{
    if (fileName.empty())
    {
        throw new invalid_argument("The file name cannot be empty!");
    }

    ifstream file(fileName);
    vector<string> loadedFile;

    if(file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            if (line != "")
            {
                loadedFile.push_back(line);
            }

        }
        file.close();
    }

    Roster returnRoster = this -> buildRosterFromFile(loadedFile);
    return returnRoster;
}

}
