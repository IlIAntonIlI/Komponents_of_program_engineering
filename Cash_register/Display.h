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
};

