#include "functions.h"
bool isExistUser(string name)
{
    ifstream file;
    file.open("Users\\"+name+".txt");
    if (!file)
        return false;
    else
        return true;
}

void showLevels(int levels)
{
    for (int i=1; i<=levels;i++)
        cout<<i <<" ";
}

bool checkIfTeacher (string nameTeacher)
{
    ifstream checker("Users\\"+nameTeacher+".txt");
    string readIfTeacher;
    getline(checker, readIfTeacher);
    getline(checker, readIfTeacher);
    getline(checker, readIfTeacher);
    checker.close();
    if (readIfTeacher == "1")
        return true;
    else
        return false;
}

vector<string> readListOfCourses()
{
    vector<string> course;
    ifstream courses("courses.txt");
    if (!courses.is_open())
        return course;
    string reader;
    while (!courses.eof())
    {
        getline(courses,reader);
        if (reader.length()>0)
            course.push_back(reader);
    }
    courses.close();
    return course;
}

void showListCourses(vector<string> courses)
{
    for (int i=0; i<courses.size();i++)
        cout<<i+1 <<". " <<courses[i]<<endl;
}

bool isNum(string courseChoice)
{
    bool flag = true;
    for (int i = 0; i<courseChoice.length();i++)
    {
        if (!isdigit(courseChoice[i]))
        {
            return false;
        }
    }
    return flag;
}

bool isExist(string userName, string nameFile)
{
    bool flag = false;
    string reader;
    ifstream users(nameFile);
    while (!users.eof())
    {
        getline(users,reader);
        if (reader == userName)
            return true;
        getline(users, reader);
    }
    users.close();
    return flag;
}

int readOpenLevels(string userName, string nameFile)
{
    string reader;
    ifstream users(nameFile);
    while (!users.eof())
    {
        getline(users,reader);
        if (reader == userName)
        {
            getline(users, reader);
            return stoi(reader);
        }
        getline(users, reader);
    }
}

int findOpenLevels(string nameFile,string nameUser)
{
    ifstream listUsers (nameFile);
    if (listUsers.is_open())
    {
        if (!isExist(nameUser,nameFile))
        {
            ofstream users(nameFile,ios::app);
            users<<nameUser <<endl <<1 <<endl;
            users.close();
            return 1;
        }
        else
        {
            return readOpenLevels(nameUser,nameFile);
        }
    }
    else
    {
        ofstream users(nameFile);
        users<<nameUser <<endl <<1 <<endl;
        users.close();
        return 1;
    }
    listUsers.close();
}

vector<string> readCourses(string nameTeacher)
{
    ifstream userFile("Users\\"+nameTeacher+".txt");
    vector<string> buffer;
    string reader;
    getline(userFile,reader);
    getline(userFile,reader);
    getline(userFile,reader);
    while (!userFile.eof())
    {
        getline(userFile,reader);
        if (reader.length()>0)
            buffer.push_back(reader);
    }
    userFile.close();
    return buffer;
}

bool isExistInList(vector<string> listOfCourses, string course)
{
    for (int i = 0; i<listOfCourses.size();i++)
    {
        if (listOfCourses[i]==course)
            return true;
    }
    return false;
}


