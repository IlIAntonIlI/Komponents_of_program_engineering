#include <string>
#include <iostream>
#include <dir.h>
#include <filesystem>
using namespace std;

class User
{
    string name,
           password;
public:
    User():name(""), password("") {}
    string getName();
    void setName(string);
    string getPassword();
    void setPassword(string);
    void registrate();
    void registrateTeacher();
    void autoriz();
    void showListOfPupils(string);
    void addCourse();
};
