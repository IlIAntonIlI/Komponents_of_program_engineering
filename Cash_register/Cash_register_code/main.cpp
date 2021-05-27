#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include "Scanner.h"
#include "Database.h"
#include "Display.h"
#include "CasaController.h"
#include "CashAcceptDevice.h"
#include "CasaPrinter.h"
using namespace std;

int main()
{
    int code;
    int flag=0;
    CasaController casa;
    CasaPrinter printer;
    Database dataBaseProducts;                                                                                                                                                                                                        dataBaseProducts.FillDatabase();
    Display display1;
    CashAcceptDevice device;
    Scanner scan;
    cout<<"Write: \n 0 - scan price \n 1 - create a check \n 2 - help\n-1 - end program"<<endl;
    cin>>flag;
    while(flag!=-1)
    {
        if((flag>3)||(flag<-1))
            flag=3;
        int flag3=-1;
        if(flag==2)
        {
            system("cls");
            int flag4;
            cout<<"Write \n0 - how to scan price\n1 - how to create check\n2 - how to end the program"<<endl;
            cin>>flag4;
            display1.showHelp(flag4);
            flag=3;
        }
        if(flag==3)
        {
            system("cls");
            cout<<"Write: \n 0 - scan price \n 1 - create a check \n 2 - help\n-1 - end program"<<endl;
            cin>>flag;
        }
        if(flag==-1) break;

        if(flag==0)
        {
            code=scan.readCode();
            system("cls");
            cout<<"The price of "<<dataBaseProducts.getNameProduct(code)<<": "<<dataBaseProducts.getPrice(code)<<" UAH"<<endl<<endl;
            cout<<"Write: \n 0 - scan price \n 1 - create a check \n 2 - help\n-1 - end program"<<endl;
            cin>>flag;
        }
        else if (flag==1)
        {
            system("cls");
            code=scan.readCode();
            casa.addProductToCheck(code,dataBaseProducts,display1);
            int flag1=0;
            cout<<"Write:\n1 - pay for products and print check \n0 - continue scan products"<<endl;
            cin>>flag1;
            if(flag1==1)
            {
                system("cls");
                int cash;
                display1.showCheck(casa.check);
                cout<<"Enter money, please: ";
                cin>>cash;
                while(!device.checkCash(casa.check,cash))
                {
                    system("cls");
                    cout<<"Entered money: "<<cash<<endl;
                    display1.showCheck(casa.check);
                    display1.noEnoughMoney();
                    cin>>flag3;
                    if(flag3==1)
                    {
                        system("cls");
                        cout<<"Entered money: "<<cash<<endl;
                        display1.showCheck(casa.check);
                        cout<<"Enter money: ";
                        int cash1;
                        cin>>cash1;
                        cash=cash+cash1;
                    }
                    else if(flag3==0)
                    {
                        system("cls");
                        cout<<"Entered money: "<<cash<<endl;
                        int code1;
                        display1.showCheck(casa.check);
                        cout << "Write the number of product you want to delete in check: ";
                        cin >> code1;
                        casa.deleteProductFromCheck(code1,dataBaseProducts,display1);
                        system("cls");
                    }
                }
                if (!casa.check.empty()){system("cls");cout<<"Thanks for choosing our shop, take your check please."<<endl;printer.printCheck(casa.check,cash);cout<<endl;flag3=1;}
            }
        }
        if ((casa.check.empty()) &&(flag3!=-1))
        {
            cout<<"Wait next client or end program? Write: \n1 - wait client \n0 - end program"<<endl;
            cin>>flag;
            if (flag==0) flag=-1;
            else
            {
                flag=3;
            }

        }
        cout<<endl;
    }

    return 0;
}
