using namespace std;
class CasaPrinter{
public:
    printCheck(vector<Product> &check, int cash){
        int sum=0;
        for(int i=0; i<check.size();i++)
            sum=sum+check[i].price;
        cout<<"Your balance: "<<cash-sum<<endl;
        check.clear();
    }
};
