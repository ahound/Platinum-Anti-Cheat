#include <iostream>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <string>
#include <sstream>


using namespace std;

namespace dataRecord
{
    int stringOffenses = NULL;
    bool stringOffenseBool = false;
}

class stringQuery
{
private:
    size_t locateBlackList = {};
    bool query = false;
    bool confirmedCheat = false;
public:
    stringQuery(const string str, const string desiredstrings)
    {
        locateBlackList = (std::string::npos != str.find((desiredstrings))); // Variable for locating a blacklisted word within a line
    }

    void scanStrings() noexcept
    {
        if (locateBlackList) // If anti-cheat detects a any of the blacklisted words in a line then perform the below actions
        {
            query = true;
        }

        if (query == true) // If cheat is found then do this, dig deeper
        {
            query = false;
            confirmedCheat = true;

            dataRecord::stringOffenses += 1;

            printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
            printf("! BLACKLISTED STRING DETECTED IN LINE ABOVE !\n");
            printf("--------------------------------------------------------------\n");
        }
    }

    void outAC(const string var)
    {
        cout << var << endl;
    }

};

