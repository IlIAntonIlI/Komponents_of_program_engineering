#include "Level.h"
int Level::getLevel()
{
    return level;
};

void Level::setLevel(int newLevel)
{
    level = newLevel;
}

void Level::addLevel(string course, int numOfLevel)
{
    string reader="";
    system("cls");
    cout<<"____________________________________ADD LEVEL___________________________________\n";
    cout<<"Enter theory to the lesson(to create next part enter \"test\" from new line): " <<endl;
    int indexLevel = findIndex(course);
    if (numOfLevel<indexLevel)
        indexLevel = numOfLevel;
    ofstream levelFileTH(course+"\\"+to_string(indexLevel)+"TH.txt");
    ofstream levelFileTA(course+"\\"+to_string(indexLevel)+"TA.txt");
    while (reader!="test")
    {
        getline(cin, reader);
        if (reader == "test")
            break;
        else
            levelFileTH<<reader <<endl;
    }

    for (int j = 1; j<=5; j++)
    {
        system("cls");
        cout<<"____________________________________ADD LEVEL___________________________________\n";
        cout<<"Enter "+to_string(j)+" question: "; cin.ignore();getline(cin,reader);
        levelFileTA<<reader<<endl;
        cout<<endl;
        cout<<"Enter four answers(like a)1500 b)780 ...): "; getline(cin,reader);
        levelFileTA<<reader<<endl;
        cout<<endl;
        cout<<"Enter right answers(one symbol): "; cin>>reader;
        levelFileTA<<reader[0]<<endl;
        cout<<endl;
    }
    levelFileTA.close();
    levelFileTH.close();
}

int findIndex(string Teacher)
{
    int i = 1;
    while (i>0)
    {
        ifstream file(Teacher+"\\"+to_string(i)+"TH.txt");
        if (file.is_open())
            i++;
        else
            return i;
    }
}

bool Level::showHistoryInformation(string nameFile)
{
    ifstream file (nameFile);
    if (!file.is_open())
    {
        system("cls");
        cout<<"_____________________________________COURSES____________________________________";
        cout<<endl<<endl<<"             This level has not yet been created by teacher!" <<endl;
        system("pause");
        return false;
    }
    string reader;
    system("cls");
    cout<<"_____________________________________LEVEL "<<this->level <<"____________________________________" <<endl;
    cout<<"                                     THEORY                                     " <<endl;

    while (!file.eof())
    {
        getline(file, reader);
        cout<<reader <<endl;
    }
    cout<<endl;
    file.close();
    return true;
}

void Level::test(string nameFile, string Teacher, string nameUser)
{
    char userAnswers[5], rightAnswers[5];
    string reader, userAnsw;
    ifstream file (nameFile);
    for (int i=0; i<5;i++)
    {
        system("cls");
        cout<<"_____________________________________LEVEL "<<this->level <<"____________________________________" <<endl;
        cout<<"                                      TASK                                      " <<endl;
        cout<<"                                    QUESTION "<<i+1<<"                                  " <<endl;
        getline(file, reader);
        cout<<reader <<endl<<endl;
        getline(file, reader);
        cout<<reader <<endl;
        getline(file, reader);
        rightAnswers[i] = reader[0];
        cout<<"\nYour answer(only the first letter is taken): "; cin>>userAnsw; cout<<endl;
        userAnswers[i] = userAnsw[0];
    }
    file.close();
    system("cls");
    cout<<"_____________________________________LEVEL "<<this->level <<"____________________________________" <<endl;
    cout<<"                                   CONCLUSION                                   " <<endl;
    cout<<"                        Your answers:             Rigth answers:" <<endl;
    int grade = 0;
    for (int i=0; i<5;i++)
    {
        cout<<"                        "<<i+1 <<". " <<userAnswers[i] <<"                      " <<i+1 <<". " <<rightAnswers[i] <<endl;
        if (userAnswers[i]==rightAnswers[i])
            grade++;
    }

    if (grade>=4)
    {
        bool lastMassage = false;
        cout<<"                                 Your grade:" <<grade <<"p."<<endl;
        vector<string> listOfUsers;
        string reader1;
        ifstream users(Teacher+"\\users.txt");
        while (!users.eof())
        {
            getline(users,reader1);
            if (reader1.length()>0)
                listOfUsers.push_back(reader1);
        }
        users.close();
        ofstream users1(Teacher+"\\users.txt");
        int i = 0;
        while (i<listOfUsers.size())
        {
            if (listOfUsers[i]==nameUser)
            {
                ifstream check (Teacher+"\\"+to_string(stoi(listOfUsers[i+1])+1)+"TH.txt");
                if (check.is_open())
                {
                    users1<<nameUser <<endl <<stoi(listOfUsers[i+1])+1<<endl;
                    i+=2;
                }
                else
                {
                    users1<<nameUser <<endl <<stoi(listOfUsers[i+1])<<endl;
                    i+=2;
                    lastMassage = true;
                }
            }
            else
            {
                users1<<listOfUsers[i] <<endl <<listOfUsers[i+1]<<endl;
                i+=2;
            }
        }
        users1.close();
        if (lastMassage)
        {
            system("pause");
            system("cls");
            cout<<"\n\n\n\n            Congratulation! You pass all test available for nowadays!           ";
        }
        else
        {
            system("pause");
            system("cls");
            cout<<"\n\n\n\n                Congratulation! You open new level on this course!              ";
        }
    }
    else
    {
        cout<<"                                 Your grade:" <<grade <<"p." <<endl <<endl <<"              You should try better, please complete the level again!\n"<<endl;
    }
}
