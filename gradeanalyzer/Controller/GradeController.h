#ifndef GRADECONTROLLER_H
#define GRADECONTROLLER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdexcept>
using namespace std;

#include "Student.h"
#include "Roster.h"
#include "FileReader.h"
#include "OutputBuilder.h"
using namespace model;
using namespace view;
using namespace IO;

namespace controller
{

class GradeController
{
private:
    Roster unsortedRoster;
    FileReader fileReader;
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

    void displayUsageStatement();

    void displayOutput();

    void loadFile();

    void processArguments(int argc, char*argv[]);

    void outputToFile();

public:
    //Creates a new instance of a grade controller.
    //@precondition
    //  none
    //@postcondition
    //  a new grade controller is created
    GradeController();

    //De-constructs a grade controller.
    virtual ~GradeController();

    //Directs the flow of the grade analyzer application.
    //@para argc
    //  the number of arguments
    //para argv
    //  the collection of arguments
    void run(int argc, char*argv[]);
};

}

#endif // GRADECONTROLLER_H
