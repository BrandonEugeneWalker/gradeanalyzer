#include "FileWriter.h"

namespace IO
{

FileWriter::FileWriter()
{
#if DEBUG_LEVEL >= 3
    cout << "In FileWriter constructor" << endl;
#endif // DEBUG_LEVEL
}

FileWriter::~FileWriter()
{
#if DEBUG_LEVEL >= 3
    cout << "In FileWriter destructor" << endl;
#endif // DEBUG_LEVEL
}

void FileWriter::WriteFile(const string& fileName, const string& output)
{
        if (fileName.empty())
        {
            throw new invalid_argument("The file name cannot be empty!");
        }

    ofstream file;
    file.open(fileName);
    file << output;
    file.close();

}



}
