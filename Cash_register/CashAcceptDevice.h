using namespace std;
class CashAcceptDevice{
public:
    bool checkCash(vector<Product> &check,int money){
        double sum=0;
        bool checkMoney;
        for(int i=0;i<check.size();i++)
            sum=sum+check[i].price;
        if(money>=sum)
            checkMoney=true;
        else
            checkMoney=false;
        return checkMoney;
    }
};
