#include <iostream>
#include <vector>
using namespace std;
class CasaController
{
    int code;
public:
   vector<Product> check;
   void addProductToCheck(int code, Database database, Display display)
   {
        if (database.isProductExist(code))
        {
            Product bufer;
            bufer.nameProduct = database.getNameProduct(code);
            bufer.price = database.getPrice(code);
            check.push_back(bufer);
            database.changeNumOfProducts(code,true);
        }
        else
        {
            display.existMessage(false);
        }
        display.showCheck(check);
   }

   void deleteProductFromCheck (int numInCheck, Database database, Display display)
   {
        auto iter = check.cbegin();
        check.erase(iter+numInCheck-1);
        database.changeNumOfProducts(code,false);
        display.showCheck(check);
   }

};
