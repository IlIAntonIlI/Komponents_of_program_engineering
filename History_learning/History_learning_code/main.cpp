#include "functions.h"

int main()
{
    string flag = "2";
    while (flag=="2")
    {
        string action = "0";
        system("cls");
        cout<<"                     You want to register or log in?\n\n 1 - register\n\n 2 - log in\n\n";
        cin>>action;
        while ((action!="1")&&(action!="2"))
        {
            system("cls");
            cout<<"                         Error, enter correct data!\n\n 1 - register\n\n 2 - log in\n\n"; cin>>action;
        }

        User currentUser;
        if (action=="1")
        {
            string typeReg = "0";
            system("cls");
            cout<<"                    You want to register teacher or pupil?\n\n 1 - register teacher\n\n 2 - register pupil\n\n";
            cin>>typeReg;
            while ((typeReg!="1")&&(typeReg!="2"))
            {
                system("cls");
                cout<<"                         Error, enter correct data!\n\n 1 - register teacher\n\n 2 - register pupil\n\n"; cin>>typeReg;
            }
            if (typeReg=="2")
                currentUser.registrate();
            else if (typeReg=="1")
            {
                currentUser.registrateTeacher();
            }
        }
        else if (action=="2")
        {
            currentUser.autoriz();
        }

        if (currentUser.getName()!="")
        {
            if (checkIfTeacher(currentUser.getName()))
            {
                Level newLevel;
                string whatAdd = "";
                while (whatAdd!="0")
                {
                    system("cls");
                    cout<<"_____________________________________COURSE_____________________________________\n";
                    cout<<"                              What you want to do?\n\n 1 - add lesson\n\n 2 - check list of pupils\n\n 3 - add course\n\n 4 - show list of my courses \n\n 5 - switch account\n\n 6 - exit\n";
                    cin>>whatAdd;
                    while ((whatAdd != "3")&&(whatAdd != "4")&&(whatAdd !="1")&&(whatAdd!="2")&&(whatAdd!="5")&&(whatAdd!="6"))
                    {
                        system("cls");
                        cout<<"                         Error, enter correct data!\n\n 1 - add lesson\n\n 2 - check list of pupils\n\n 3 - add course \n\n 4 - show list of my courses \n\n 5 - switch account\n\n 6 - exit\n";
                        cin>>whatAdd;
                    }
                    if (whatAdd == "1")
                    {
                        system("cls");
                        cout<<"____________________________________ADD LEVEL___________________________________\n";
                        vector<string> teacherCourses = readCourses(currentUser.getName());
                        if (teacherCourses.empty())
                        {
                            cout<<"List of your courses is empty. Please, firstly create one."<<endl;
                            system("pause");
                        }
                        else
                        {
                            string courseChoice;
                            system("cls");
                            cout<<"____________________________________ADD LEVEL___________________________________\n";
                            cout<<"Choose to what course you want to add lesson:\n";
                            showListCourses(teacherCourses);
                            cout<<endl;
                            cin>>courseChoice;
                            while (!isNum(courseChoice))
                            {
                                system("cls");
                                cout<<"____________________________________ADD LEVEL___________________________________\n";
                                cout<<"Enter correct data! List of courses:\n";
                                showListCourses(teacherCourses);
                                cout<<endl;
                                cin>>courseChoice;
                            }
                            while (teacherCourses.size()<stoi(courseChoice)||(stoi(courseChoice)<=0))
                            {
                                system("cls");
                                cout<<"____________________________________ADD LEVEL___________________________________\n";
                                cout<<"Enter correct data! List of courses:\n";
                                showListCourses(teacherCourses);
                                cout<<endl;
                                cin>>courseChoice;
                                while (!(isNum(courseChoice)))
                                {
                                    system("cls");
                                    cout<<"____________________________________ADD LEVEL___________________________________\n";
                                    cout<<"Enter correct data! List of courses:\n";
                                    showListCourses(teacherCourses);
                                    cout<<endl;
                                    cin>>courseChoice;
                                }
                            }

                            string numOfLesson="ab";
                            while (!isNum(numOfLesson))
                            {
                                system("cls");
                                cout<<"____________________________________ADD LEVEL___________________________________\n";
                                cout<<"Enter number of lesson you want to add: "; cin>>numOfLesson;
                            }
                            newLevel.addLevel(teacherCourses[stoi(courseChoice)-1],stoi(numOfLesson));

                        }
                    }
                    else if (whatAdd == "2")
                    {
                        system("cls");
                        cout<<"_________________________________LIST OF PUPILS_________________________________\n";
                        vector<string> teacherCourses = readCourses(currentUser.getName());
                        if (teacherCourses.empty())
                        {
                            cout<<"List of your courses is empty. Please, firstly create one."<<endl;
                            system("pause");
                        }
                        else
                        {
                            string courseChoice;
                            system("cls");
                            cout<<"_________________________________LIST OF PUPILS_________________________________\n";
                            cout<<"Choose to what course you want to add lesson:\n";
                            showListCourses(teacherCourses);
                            cout<<endl;
                            cin>>courseChoice;
                            while (!isNum(courseChoice))
                            {
                                system("cls");
                                cout<<"_________________________________LIST OF PUPILS_________________________________\n";
                                cout<<"Enter correct data! List of courses:\n";
                                showListCourses(teacherCourses);
                                cout<<endl;
                                cin>>courseChoice;
                            }
                            while (teacherCourses.size()<stoi(courseChoice)||(stoi(courseChoice)<=0))
                            {
                                system("cls");
                                cout<<"_________________________________LIST OF PUPILS_________________________________\n";
                                cout<<"Enter correct data! List of courses:\n";
                                showListCourses(teacherCourses);
                                cout<<endl;
                                cin>>courseChoice;
                                while (!(isNum(courseChoice)))
                                {
                                    system("cls");
                                    cout<<"_________________________________LIST OF PUPILS_________________________________\n";
                                    cout<<"Enter correct data! List of courses:\n";
                                    showListCourses(teacherCourses);
                                    cout<<endl;
                                    cin>>courseChoice;
                                }
                            }
                            system("cls");
                            cout<<"_________________________________LIST OF PUPILS_________________________________\n";
                            cout<<stoi(courseChoice) <<". "<<teacherCourses[stoi(courseChoice)-1] <<endl;
                            cout<<"\nList of pupils:\n";
                            currentUser.showListOfPupils(teacherCourses[stoi(courseChoice)-1]);
                            system("pause");
                        }
                    }
                    else if (whatAdd == "3")
                    {
                        currentUser.addCourse();
                    }
                    else if (whatAdd == "4")
                    {
                        system("cls");
                        cout<<"_________________________________LIST OF COURSES________________________________\n";
                        vector<string> teacherCourses = readCourses(currentUser.getName());
                        if (teacherCourses.empty())
                        {
                            cout<<"List of your courses is empty. Please, firstly create one."<<endl;
                            system("pause");
                        }
                        else
                        {
                            string courseChoice;
                            system("cls");
                            cout<<"_________________________________LIST OF COURSES________________________________\n";
                            cout<<"List of your courses:\n";
                            showListCourses(teacherCourses);
                            system("pause");
                        }
                    }

                    if (whatAdd=="5")
                    {
                        flag = "2";
                        whatAdd="0";
                    }
                    if (whatAdd=="6")
                    {
                        flag = "0";
                        whatAdd="0";
                    }

                }

            }
            else
            {
                flag ="1";
                Level currentLevel;
                while(flag=="1")
                {
                    int openLevels = 0;
                    string courseChoice;
                    system("cls");
                    cout<<"_____________________________________COURSES____________________________________\n";
                    vector<string> courses = readListOfCourses();
                    cout<<"Choose course. List of courses:\n";
                    showListCourses(courses);
                    cout<<endl;
                    cin>>courseChoice;
                    while (!isNum(courseChoice))
                    {
                        system("cls");
                        cout<<"_____________________________________COURSES____________________________________\n";
                        cout<<"Enter correct data! List of courses:\n";
                        showListCourses(courses);
                        cout<<endl;
                        cin>>courseChoice;
                    }
                    while (courses.size()<stoi(courseChoice)||(stoi(courseChoice)<=0))
                    {
                        system("cls");
                        cout<<"_____________________________________COURSES____________________________________\n";
                        cout<<"Enter correct data! List of courses:\n";
                        showListCourses(courses);
                        cout<<endl;
                        cin>>courseChoice;
                        while (!(isNum(courseChoice)))
                        {
                            system("cls");
                            cout<<"_____________________________________COURSES____________________________________\n";
                            cout<<"Enter correct data! List of courses:\n";
                            showListCourses(courses);
                            cout<<endl;
                            cin>>courseChoice;
                        }
                    }
                    openLevels = findOpenLevels(courses[stoi(courseChoice)-1]+"\\users.txt",currentUser.getName());
                    system("cls");
                    cout<<"_____________________________________LEVELS_____________________________________\n";
                    cout<<"Availables levels: ";
                    showLevels(openLevels);

                    string level;
                    cout<<"\nChoose what level you want to complete: "; cin>>level;
                    while ((level.length()>1)||(!isNum(level)))
                    {
                        system("cls");
                        cout<<"_____________________________________LEVELS_____________________________________\n";
                        cout<<"Availables levels: ";
                        showLevels(openLevels);
                        cout<<"\nError enter correct data!";
                        cout<<"\nChoose what level you want to complete: "; cin>>level;
                    }
                    while (openLevels<stoi(level)||(stoi(level)<=0))
                    {
                        system("cls");
                        cout<<"_____________________________________LEVELS_____________________________________\n";
                        cout<<"Availables levels: ";
                        showLevels(openLevels);
                        cout<<"\nError you can't choose this level!\nChoose what level you want to complete: "; cin>>level;
                        while ((level.length()>1)||!(isNum(level)))
                        {
                            system("cls");
                            cout<<"_____________________________________LEVELS_____________________________________\n";
                            cout<<"Availables levels: ";
                            showLevels(openLevels);
                            cout<<"\nError enter correct data!";
                            cout<<"\nChoose what level you want to complete: "; cin>>level;
                        }
                    }
                    currentLevel.setLevel(stoi(level));
                    bool isNeedTest = currentLevel.showHistoryInformation(courses[stoi(courseChoice)-1]+"\\"+level+"TH.txt");
                    if (isNeedTest)
                    {
                    system("pause");
                    currentLevel.test(courses[stoi(courseChoice)-1]+"\\"+level+"TA.txt", courses[stoi(courseChoice)-1],currentUser.getName());
                    system("pause");
                    }
                    system("cls");
                    cout<<"                                      Write:\n 0 - end learning\n\n 1 - continue\n\n 2 - switch user\n\n"; cin>>flag;
                    while ((flag!="0")&&(flag!="1")&&(flag!="2"))
                    {
                        system("cls");
                        cout<<"                           Error, enter correct data!\n                                      Write:\n 0 - end learning\n\n 1 - continue\n\n 2 - switch user\n\n"; cin>>flag;
                    }
                }
            }
        }
    }
    return 0;
}
