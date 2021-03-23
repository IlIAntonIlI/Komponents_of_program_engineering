using namespace std;
class Database{
    Product listOfProducts[10];
public:
     string getNameProduct(int code){return this->listOfProducts[code].nameProduct;}
     double getPrice(int code){return this->listOfProducts[code].price;}
     bool isProductExist(int code){return this->listOfProducts[code].exist;}
     void changeNumOfProducts(int code,bool add_delete)
     {
         if(add_delete==true){
                this->listOfProducts[code].numOfProducts--;
                if (this->listOfProducts[code].numOfProducts==0)
                    listOfProducts[code].exist=false;
         }
         else if(add_delete==false){
                this->listOfProducts[code].numOfProducts++;
                listOfProducts[code].exist=true;
         }
     }
     void FillDatabase(Database dataBaseProducts)
     {
    dataBaseProducts.listOfProducts[0].exist=true;
    dataBaseProducts.listOfProducts[0].nameProduct="Fridge";
    dataBaseProducts.listOfProducts[0].numOfProducts=3;
    dataBaseProducts.listOfProducts[0].price=10000;

    dataBaseProducts.listOfProducts[1].exist=true;
    dataBaseProducts.listOfProducts[1].nameProduct="Microwave LG";
    dataBaseProducts.listOfProducts[1].numOfProducts=2;
    dataBaseProducts.listOfProducts[1].price=4000;

    dataBaseProducts.listOfProducts[2].exist=false;
    dataBaseProducts.listOfProducts[2].nameProduct="NoteBook HP";
    dataBaseProducts.listOfProducts[2].numOfProducts=0;
    dataBaseProducts.listOfProducts[2].price=15000;

    dataBaseProducts.listOfProducts[3].exist=true;
    dataBaseProducts.listOfProducts[3].nameProduct="Microwave Lenovo";
    dataBaseProducts.listOfProducts[3].numOfProducts=2;
    dataBaseProducts.listOfProducts[3].price=3500;

    dataBaseProducts.listOfProducts[4].exist=true;
    dataBaseProducts.listOfProducts[4].nameProduct="Coffee maker";
    dataBaseProducts.listOfProducts[4].numOfProducts=4;
    dataBaseProducts.listOfProducts[4].price=1000;

    dataBaseProducts.listOfProducts[5].exist=true;
    dataBaseProducts.listOfProducts[5].nameProduct="Stove";
    dataBaseProducts.listOfProducts[5].numOfProducts=1;
    dataBaseProducts.listOfProducts[5].price=7000;

    }

};













































