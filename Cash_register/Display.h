#include <iostream>
using namespace std;
class Display
{
public:
    void showPrice(int code, Database database)
    {
        cout<<"Price: "<<database.getPrice(code) <<"\n";
    }
    void showCheck(vector<Product>& check)
    {
        int sum=0;
        cout<<"==============================================================================="<<endl;
        cout<<"==============================================================================="<<endl;
        cout<<"Check:\n";
        for (int i=0; i<check.size();i++)
        {
             cout<<i+1 <<") " << check[i].nameProduct <<"-->" <<check[i].price <<" UAH.\n";
             sum=sum+check[i].price;
        }
        cout<<"\t Full cost: " <<sum<<endl;
        cout<<"==============================================================================="<<endl;
        cout<<"==============================================================================="<<endl<<endl;
    }
    void existMessage(bool exist)
    {
        if (exist==false)
            cout<< "Product isn't exist!\n";
        else
            cout<<"Product exist!\n";
    }
    void noEnoughMoney ()
    {
        cout<<"No enough money, pls enter more money or delete some products! \n1 - enter more money \n0 - delete some products from check."<<endl;
    }
    void showHelp (int flag4)
    {
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
            system("cls");
    }
};

