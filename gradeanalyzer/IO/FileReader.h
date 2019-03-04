#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <string>
#include <vector>
using namespace std;

namespace IO
{

class FileReader
{
private:


public:
    FileReader();
    virtual ~FileReader();

    //Reads a file from the given file name.
    //@precondition
    // the file name cannot be empty
    //@return
    //  A collection containing each line of the file as a string.
    vector<string> ReadFile(const string& fileName);

};

}
#endif // FILEREADER_H
