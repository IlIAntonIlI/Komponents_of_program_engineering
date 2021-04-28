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
    while(flag>=0)
    {
        int flag3=-1;
        if(flag==2)
        {
            system("cls");
            int flag4;
            cout<<"Write \n0 - how to scan price\n1 - how to create check\n2 - how to end the program"<<endl;
            cin>>flag4;
            if(flag4==0)
            {
                system("cls");
                cout<<"======               SCANING PRICE OF PRODUCT               ======\n";
                cout<<"1)Choose \"0\" at the start menu.\n\n2)At the this step scan product:write ID (from 0 to 5) and you can see name of product and it's price.\n";
            }
            else if(flag4==1)
            {
                system("cls");
                cout<<endl<<"======               CREATING CHECK               ======\n";
                cout<<"1)Choose \"1\" at the start menu.\n\n2)At the this step scan product:write ID (from 0 to 5) and this product will be added to the check.\n\n";
                cout<<"3)If you want to add more products, select \"0\" in the next menu and repeat previous step.\n\n";
                cout<<"4)If you want to pay for the goods, select \"1\" in the menu described in step 3.\n\n";
                cout<<"5)In this step, enter the money in the cash register.\n\n";
                cout<<"    5.1)If entered enough money, your payment has been made successfully and you can take the check.\n\n";
                cout<<"    5.2)If entered not enough money, you need to add money (choose \"1\") or delete some products from check (choose\"0\").\n\n";
                cout<<"        5.2.1) If you choose \"1\", your payment has been made successfully and you can take the check.\n\n";
                cout<<"        5.2.2) If you choose \"0\", write the number of product you want to delete.\n\n";

            }
            else if(flag4==2)
            {
                system("cls");
                cout<<"======               END THE PROGRAM               ======\n";
                cout<<"1)Choose \"-1\" in main menu to close the program";
            }
            cout<<endl<<endl;
            system("pause");
            flag=3;
            system("cls");
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
            cout<<"Write: \n 0 - scan price \n 1 - create a check \n-1 - end program"<<endl;
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
                        //cout<<endl<<"Thanks for choosing our shop, take your check please."<<endl<<endl; printer.printCheck(casa.check);
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
