#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

namespace IO
{

class FileWriter
{
public:
    //Creates a new instance of a FileWriter
    //@precondition
    //  none
    //@postcondition
    //  a new FileWriter is created
    FileWriter();

    //De-constructs a FileWriter
    virtual ~FileWriter();

    //Writes a string to a new file using the given fileName.
    //@precondition
    //  file name cannot be empty
    //@postcondition
    //  the data is written to the file.
    void WriteFile(const string& fileName, const string& output);

};

}

#endif // FILEWRITER_H
