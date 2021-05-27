#include "User.h"
#include <fstream>
#include <vector>
class Level
{
    int level;
public:
    int getLevel();
    void setLevel(int);
    void addLevel(string,int);
    bool showHistoryInformation(string);
    void test(string,string,string);
};

int findIndex(string);
