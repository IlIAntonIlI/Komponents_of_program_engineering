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
            bufer.name = database.getName(code);
            bufer.price = datebase.getPrice(code);
            datebase.changeNumOfProducts(code,true);
        }
        else
        {
            display.existMessage();

        }
   }

   void deleteProductFromCheck (int numInCheck)
   {
        check.erase(numInCheck-1);
        datebase.changeNumOfProducts(code,false);
   }

};
