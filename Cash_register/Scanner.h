#include <iostream>
using namespace std;
class Scanner
{
public:
    int readCode()
    {
        int code;
        cout<<"Enter number from 0 to 9: ";
        cin >>code;
        return code;
    }
};
