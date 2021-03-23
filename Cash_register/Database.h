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
     void FillDatabase()
     {
    listOfProducts[0].exist=true;
    listOfProducts[0].nameProduct="Fridge";
    listOfProducts[0].numOfProducts=3;
    listOfProducts[0].price=10000;

    listOfProducts[1].exist=true;
    listOfProducts[1].nameProduct="Microwave LG";
    listOfProducts[1].numOfProducts=2;
    listOfProducts[1].price=4000;

    listOfProducts[2].exist=false;
    listOfProducts[2].nameProduct="NoteBook HP";
    listOfProducts[2].numOfProducts=0;
    listOfProducts[2].price=15000;

    listOfProducts[3].exist=true;
    listOfProducts[3].nameProduct="Microwave Lenovo";
    listOfProducts[3].numOfProducts=2;
    listOfProducts[3].price=3500;

    listOfProducts[4].exist=true;
    listOfProducts[4].nameProduct="Coffee maker";
    listOfProducts[4].numOfProducts=4;
    listOfProducts[4].price=1000;

    listOfProducts[5].exist=true;
    listOfProducts[5].nameProduct="Stove";
    listOfProducts[5].numOfProducts=1;
    listOfProducts[5].price=7000;

    }

};













































