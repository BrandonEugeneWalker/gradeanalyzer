#include "FileReader.h"


namespace IO
{



FileReader::FileReader()
{
#if DEBUG_LEVEL >= 3
    cout << "In FileReader constructor" << endl;
#endif // DEBUG_LEVEL
}

FileReader::~FileReader()
{
#if DEBUG_LEVEL >= 3
    cout << "In FileReader destructor" << endl;
#endif // DEBUG_LEVEL
}

vector<string> FileReader::ReadFile(const string& fileName)
{
    ifstream file(fileName);
    vector<string> returnVector;

    if(file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            returnVector.push_back(line);
        }
        file.close();
    }
    return returnVector;
}

}
