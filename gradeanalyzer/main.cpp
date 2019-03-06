#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;


#include "Student.h"
#include "Roster.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "OutputBuilder.h"
using namespace model;
using namespace view;
using namespace IO;



Roster unsortedRoster;
FileReader fileReader;
FileWriter fileWriter;
OutputBuilder outputBuilder;

int columnNumber = 4;
int columnWidth = 20;
bool hasEncounteredInfile = false;
bool hasEncounteredOutfile = false;
bool includeGrades = false;
bool sortByLastName = true;
bool displayHistrogram = false;
string outputFile;
string inputFile;

vector<string> argumentCollection;



void displayOutput()
{
    outputBuilder.buildFullOutput(unsortedRoster, columnNumber, columnWidth, includeGrades, sortByLastName, displayHistrogram);
}

void displayUsageStatement()
{
    outputBuilder.displayUsageStatement();
}

void loadFile()
{




}

void processArguments()
{
    int i = 0;
    while (i < argumentCollection.size())
    {
        string currentArgument = argumentCollection[i];
        if (currentArgument == "--help")
        {
            displayUsageStatement();
            i++;
        }
        else if (currentArgument == "-c")
        {
            int newColumnNumber = stoi(argumentCollection[i + 1]);
            columnNumber = newColumnNumber;
            i = i + 2;
        }
        else if (currentArgument == "-a")
        {
            string firstName = argumentCollection[i + 1];
            string lastName = argumentCollection[i + 2];
            int grade = stoi(argumentCollection[i + 3]);
            Student student(firstName, lastName, grade);
            unsortedRoster.addStudent(student);
            i = i + 4;
        }
        else if (currentArgument == "-g")
        {
            includeGrades = true;
            i++;
        }
        else if (currentArgument == "-h")
        {
            displayHistrogram = true;
            i++;
        }
        else if (currentArgument == "-sf")
        {
            sortByLastName = false;
            i++;
        }
        else if (currentArgument == "-w")
        {
            int newColumnWidth = stoi(argumentCollection[i + 1]);
            i = i + 2;
        }
        else
        {
            if (!hasEncounteredInfile)
            {
                inputFile = argumentCollection[i];
            }
            else if (!hasEncounteredOutfile)
            {
                outputFile = argumentCollection[i];
            }
            else
            {
                throw new invalid_argument("Not a valid argument!");
            }
            i++;
        }
    }
}

void outputToFile()
{
    streambuf *psbuf, *backup;
    ofstream filestr;
    filestr.open (outputFile);

    backup = cout.rdbuf();

    psbuf = filestr.rdbuf();
    cout.rdbuf(psbuf);

    displayOutput();

    cout.rdbuf(backup);

    filestr.close();
}

int main(int argc, char*argv[])
{
    if(argc == 0)
    {
        displayUsageStatement();
        exit(0);
    }

    string argumentValue;
    for (int i = 0; i < argc; i++)
    {
        char* charecter = argv[i];
        if (*charecter != ' ')
        {
            argumentValue += charecter;
        }
        else
        {
            argumentCollection.push_back(argumentValue);
            argumentValue = "";
        }
    }

    processArguments();
}
