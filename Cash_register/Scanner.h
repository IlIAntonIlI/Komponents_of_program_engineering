#include <iostream>
using namespace std;
class Scanner
{
public:
    int readCode()
    {
        int code;
        cout<<"Enter number from 0 to 5: ";
        cin >>code;
        return code;
    }
};

