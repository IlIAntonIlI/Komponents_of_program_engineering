#include "functions.h"
string User::getName()
{
    return name;
}

void User::setName(string newName)
{
    name = newName;
}

string User::getPassword()
{
    return password;
}

void User::setPassword(string newPassword)
{
    password = newPassword;
}

void User::registrate()
{
    system("cls");
    string userData;
    cout<<"_________________________________REGISTRIZATION_________________________________\n";
    cout<<"Enter your nickname(to return write \"return\"): "; cin>>userData; this->setName(userData);
    while (isExistUser(userData))
    {
        system("cls");
         cout<<"_________________________________REGISTRIZATION_________________________________\n";
        cout<<"This nickname is already exist!\nEnter another nickname(to return write \"return\"): "; cin>>userData; this->setName(userData);
    }
    if (userData == "return")
    {
        this->setName("");
        return;
    }
    system("cls");
    cout<<"_________________________________REGISTRIZATION_________________________________\n";
    cout<<"Nickname: " <<this->getName() <<endl;
    cout<<"\nEnter your password: "; cin>>userData; this->setPassword(userData);
    ofstream file ("Users\\"+this->getName()+".txt");
    file<<userData <<endl<<1<<endl;
    file<<0;
    file.close();
}

void User::registrateTeacher()
{
    system("cls");
    string userData;
    cout<<"_________________________________REGISTRIZATION_________________________________\n";
    cout<<"Enter nickname(to return write \"return\"): "; cin>>userData; this->setName(userData);
    while (isExistUser(userData))
    {
        system("cls");
         cout<<"_________________________________REGISTRIZATION_________________________________\n";
        cout<<"This nickname is already exist!\nEnter another nickname(to return write \"return\"): "; cin>>userData; this->setName(userData);
    }
    if (userData == "return")
    {
        this->setName("");
        return;
    }
    system("cls");
    cout<<"_________________________________REGISTRIZATION_________________________________\n";
    cout<<"Nickname: " <<this->getName() <<endl;
    cout<<"\nEnter password: "; cin>>userData; this->setPassword(userData);
    ofstream file ("Users\\"+this->getName()+".txt");
    file<<userData <<endl<<1<<endl;
    file<<1 <<"\n";
    file.close();
}

void User::autoriz()
{
    system("cls");
    string userData;
    cout<<"__________________________________AUTORIZATION__________________________________\n";
    cout<<"Enter your nickname: "; cin>>userData; this->setName(userData);
    int numOfCalls=1;
    while (!isExistUser(userData))
    {
        if (numOfCalls>=5)
        {
            system("cls");
            cout<<"Too much input of incorrect data! Please, try later!" <<endl;
            this->setName("");
            return;
        }
        system("cls");
        cout<<"__________________________________AUTORIZATION__________________________________\n";
        cout<<"There are "<<5-numOfCalls <<" more attempts left\n";
        cout<<"We haven't user with this nickname, please enter correct nickname: "; cin>>userData; this->setName(userData);
        numOfCalls++;
    }

    ifstream file("Users\\"+this->getName()+".txt");
    string password;
    file>>password;
    file.close();
    system("cls");
    cout<<"__________________________________AUTORIZATION__________________________________\n";
    cout<< "Nickname: " <<this->getName()<<endl;
    cout<<"\nEnter password: "; cin>>userData; this->setPassword(userData);
    numOfCalls=1;
    while (this->getPassword()!=password)
    {
        if (numOfCalls>=5)
        {
            system("cls");
            cout<<"Too much input of incorrect data! Please, try later!" <<endl;
            this->setName("");
            return;
        }
        system("cls");
        cout<<"__________________________________AUTORIZATION__________________________________\n";
        cout<< "Nickname(name of course): " <<this->getName()<<endl;
        cout<<"\nThere are "<<5-numOfCalls <<" more attempts left\n";
        cout<<"Enter correct password: "; cin>>userData; this->setPassword(userData);
        numOfCalls++;
    }
}

void User::showListOfPupils(string course)
{
    string reader;
    ifstream users(course+"\\users.txt");
    int i=1;
    while (!users.eof())
    {
        getline(users, reader);
        if ((reader.length()==0)&&(i==1))
        {
            cout<<"No one pupil take this course.\n";
            return;
        }
        if (reader.length()>0)
        {
            cout<<i++ <<". "<<reader <<" - max level ";
            getline(users,reader);
            cout<<reader <<endl<<endl;
        }
    }
    users.close();
}

void User::addCourse()
{
    system("cls");
    cout<<"_____________________________________COURSE_____________________________________\n";
    cout<<"Enter name of your course: ";
    string reader="";
    getline(cin,reader);
    getline(cin,reader);

    vector<string> listOfCourses = readListOfCourses();
    while (isExistInList(listOfCourses,reader)&&!listOfCourses.empty())
    {
        system("cls");
        cout<<"_____________________________________COURSE_____________________________________\n";
        cout<<"Course with this name is exist. Enter name of your course: ";
        string reader="";
        getline(cin,reader);
        getline(cin,reader);
    }

    ofstream userFile("Users\\"+this->getName()+".txt",ios::app);
    userFile<<reader<<"\n";
    userFile.close();

    ofstream courses("courses.txt",ios::app);
    courses<<reader <<endl;
    courses.close();

    mkdir(reader.c_str());
}
