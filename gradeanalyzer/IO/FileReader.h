#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;

#include "Roster.h"
#include "Student.h"
using namespace model;

namespace IO
{

class FileReader
{
private:
    Student buildStudentFromString(string inputString);

    Roster buildRosterFromFile(vector<string> loadedFile);


public:
    //Creates a new instance of a FileReader.
    FileReader();

    //De-constructs a FileReader.
    virtual ~FileReader();

    //Reads a file from the given file name.
    //@precondition
    // the file name cannot be empty
    //@return
    //  A collection containing each line of the file as a string.
    Roster readFile(const string& fileName);

};

}
#endif // FILEREADER_H
