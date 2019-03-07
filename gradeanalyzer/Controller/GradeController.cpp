#include "GradeController.h"

namespace controller
{

GradeController::GradeController()
{
#if DEBUG_LEVEL > 3
    cout << "In GradeController constructor" << endl;
#endif // DEBUG_LEVEL
}

GradeController::~GradeController()
{
#if DEBUG_LEVEL > 3
    cout << "In GradeController destructor" << endl;
#endif // DEBUG_LEVEL
}


void GradeController::displayUsageStatement()
{
    this -> outputBuilder.displayUsageStatement();
}

void GradeController::displayOutput()
{

    this -> outputBuilder.buildFullOutput(unsortedRoster, columnNumber, columnWidth, includeGrades, sortByLastName, displayHistrogram);

}

void GradeController::loadFile()
{
    try
    {
        Roster loadedFile = fileReader.readFile(inputFile);
        this -> unsortedRoster.merge(loadedFile);
    }
    catch (invalid_argument ie)
    {
        this -> displayUsageStatement();
        exit(0);
    }

}

void GradeController::processArguments(int argc, char* argv[])
{
    int i = 1;
    while (i < argc)
    {
        string currentArgument = argv[i];

        if (currentArgument == "--help")
        {
            this -> displayUsageStatement();
            exit(0);
        }
        else if (currentArgument == "-c")
        {
            int newColumnNumber = stoi(argv[i + 1]);
            this -> columnNumber = newColumnNumber;
            i = i + 2;
        }
        else if (currentArgument == "-a")
        {
            string firstName = argv[i + 1];
            string lastName = argv[i + 2];
            int grade = stoi(argv[i + 3]);
            Student student(firstName, lastName, grade);
            this -> unsortedRoster.addStudent(student);
            i = i + 4;
        }
        else if (currentArgument == "-g")
        {
            this -> includeGrades = true;
            i++;
        }
        else if (currentArgument == "-h")
        {
            this -> displayHistrogram = true;
            i++;
        }
        else if (currentArgument == "-sf")
        {
            this -> sortByLastName = false;
            i++;
        }
        else if (currentArgument == "-w")
        {
            int newColumnWidth = stoi(argv[i + 1]);
            this -> columnWidth = newColumnWidth;
            i = i + 2;
        }
        else
        {
            if (!this -> hasEncounteredInfile && currentArgument[0] != '-')
            {
                this -> inputFile = argv[i];
                this -> hasEncounteredInfile = true;
            }
            else if (!this -> hasEncounteredOutfile && currentArgument[0] != '-')
            {
                this -> outputFile = argv[i];
                this -> hasEncounteredOutfile = true;
            }
            else
            {
                throw invalid_argument("This is not a valid argument!");
            }
            i++;
        }
    }
}

void GradeController::outputToFile()
{
    streambuf *psbuf, *backup;
    ofstream filestr;
    filestr.open(this -> outputFile);

    backup = cout.rdbuf();

    psbuf = filestr.rdbuf();
    cout.rdbuf(psbuf);

    this -> displayOutput();

    cout.rdbuf(backup);

    filestr.close();
}

void GradeController::run(int argc, char*argv[])
{
    if (argc == 1)
    {
        this -> displayUsageStatement();
    }

    try
    {
        this -> processArguments(argc, argv);
        this -> loadFile();
        this -> displayOutput();
    }
    catch (exception& e)
    {
        this -> displayUsageStatement();
        exit(0);
    }

    if (hasEncounteredOutfile)
    {
        this -> outputToFile();
    }
}

}

