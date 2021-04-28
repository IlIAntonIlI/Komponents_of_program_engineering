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
    cout<<"Write: \n 0 - scan price \n 1 - create a check \n-1 - end program"<<endl;
    cin>>flag;
    while(flag>=0)
    {
        int flag3=-1;

        if(flag==3)
        {
            system("cls");
            cout<<"Write: \n 0 - scan price \n 1 - create a check \n-1 - end program"<<endl;
            cin>>flag;
        }
        if(flag==-1) break;
        Scanner scan;
        code=scan.readCode();
        if(flag==0)
        {
            system("cls");
            cout<<"The price of "<<dataBaseProducts.getNameProduct(code)<<": "<<dataBaseProducts.getPrice(code)<<" UAH"<<endl<<endl;
            cout<<"Write: \n 0 - scan price \n 1 - create a check \n-1 - end program"<<endl;
            cin>>flag;
        }
        else if (flag==1)
        {
            system("cls");
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
                    if(flag3==1){system("cls");cout<<endl<<"Thanks for choosing our shop, take your check please."<<endl<<endl; printer.printCheck(casa.check); }
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
                if (!casa.check.empty()){system("cls");cout<<"Thanks for choosing our shop, take your check please."<<endl<<endl;printer.printCheck(casa.check);flag3=1;}
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
