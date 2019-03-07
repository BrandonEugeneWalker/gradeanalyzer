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



void displayUsageStatement()
{
    outputBuilder.displayUsageStatement();
}

void displayOutput()
{

    outputBuilder.buildFullOutput(unsortedRoster, columnNumber, columnWidth, includeGrades, sortByLastName, displayHistrogram);

}

void loadFile()
{
    Roster loadedFile = fileReader.readFile(inputFile);
    unsortedRoster.merge(loadedFile);
}

void processArguments(int argc, char* argv[])
{
    int i = 1;
    while (i < argc)
    {
        string currentArgument = argv[i];

        if (currentArgument == "--help")
        {
            displayUsageStatement();
            exit(0);
        }
        else if (currentArgument == "-c")
        {
            int newColumnNumber = stoi(argv[i + 1]);
            columnNumber = newColumnNumber;
            i = i + 2;
        }
        else if (currentArgument == "-a")
        {
            string firstName = argv[i + 1];
            string lastName = argv[i + 2];
            int grade = stoi(argv[i + 3]);
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
            int newColumnWidth = stoi(argv[i + 1]);
            columnWidth = newColumnWidth;
            i = i + 2;
        }
        else
        {
            if (!hasEncounteredInfile && currentArgument[0] != '-')
            {
                inputFile = argv[i];
                hasEncounteredInfile = true;
            }
            else if (!hasEncounteredOutfile && currentArgument[0] != '-')
            {
                outputFile = argv[i];
                hasEncounteredOutfile = true;
            }
            else
            {
                throw invalid_argument("This is not a valid argument!");
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
    if(argc == 1)
    {
        displayUsageStatement();
    }

    try
    {
        processArguments(argc, argv);
        loadFile();
        displayOutput();
    }
    catch (exception& e)
    {
        displayUsageStatement();
        exit(0);
    }

    if (hasEncounteredOutfile)
    {
        outputToFile();
    }

    return(0);
}
