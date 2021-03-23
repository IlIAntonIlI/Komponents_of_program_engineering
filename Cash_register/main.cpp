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
    cout<<"If you want to scan price write \"0\" or \"1\" if you want to create a check.(for end write -1)"<<endl;
    cin>>flag;
    while(flag>=0)
    {
        int flag3=-1;

        if(flag==3)
        {
            cout<<"If you want to scan price write \"0\" or \"1\" if you want to create a check.(for end write -1)"<<endl;
            cin>>flag;
        }
        if(flag==-1) break;
        Scanner scan;
        code=scan.readCode();
        if(flag==0)
        {
            Database dataBaseProducts;                                                                                                                                                                                                          dataBaseProducts.FillDatabase();
            cout<<"The price of "<<dataBaseProducts.getNameProduct(code)<<": "<<dataBaseProducts.getPrice(code)<<" UAH"<<endl;
            cout<<"If you want to scan price write \"0\" or \"1\" if you want to create a check.(for end write -1)"<<endl;
            cin>>flag;
        }
        else if (flag==1)
        {
            CasaPrinter printer;
            Database dataBaseProducts;                                                                                                                                                                                                        dataBaseProducts.FillDatabase();
            Display display1;
            CashAcceptDevice device;
            casa.addProductToCheck(code,dataBaseProducts,display1);
            int flag1=0;
            cout<<"Do you want to pay for products and print check(write \"1\") or continue scan products(write \"0\")"<<endl;
            cin>>flag1;
            if(flag1==1)
            {
                int cash;
                cout<<"Enter money, please: ";
                cin>>cash;
                while(!device.checkCash(casa.check,cash)){display1.noEnoughMoney();
                cin>>flag3;
                if(flag3==1){cout<<"Thanks for choosing our shop, take you check please."<<endl; printer.printCheck(casa.check); }
                else if(flag3==0)
                {
                    int code1;
                    display1.showCheck(casa.check);
                    cout << "Write the number of product you want to delete in check: ";
                    cin >> code1;
                    casa.deleteProductFromCheck(code1,dataBaseProducts,display1);
                }
                }
                if (!casa.check.empty()){cout<<"Thanks for choosing our shop, take you check please."<<endl;printer.printCheck(casa.check);}
            }
        }
        if ((casa.check.empty()) &&(flag3!=-1))
        {
            cout<<"Wait next client or end program? 1 - wait client 0-end program"<<endl;
            cin>>flag;
            if (flag==0) flag=-1;
            else flag=3;
        }
        cout<<endl;
    }

    return 0;
}
