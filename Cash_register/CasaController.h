#include <iostream>
#include <vector>
using namespace std;
class CasaController
{
    vector<Product> check;
    int code;
public:
   void addProductToCheck(int code, Database database, Display display)
   {
        if (database.isProductExist())
        {
            Product bufer;
            bufer.nameProduct = database.getName(code);
            bufer.price = datebase.getPrice(code);
            check.push_back(bufer);
            datebase.changeNumOfProducts(code,true);
        }
        else
        {
            display.existMessage(false);
        }
   }

   void deleteProductFromCheck (int numInCheck, Datebase datebase)
   {
        check.erase(numInCheck-1);
        datebase.changeNumOfProducts(code,false);
   }

};
