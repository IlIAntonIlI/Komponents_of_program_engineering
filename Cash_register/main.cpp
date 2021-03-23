#include <iostream>
#include <string>
#include "Product.h"
#include "Scanner.h"
#include "Database.h"
#include "CasaController.h"
using namespace std;

int main()
{
    int code;
    Scanner scan;
    CasaController casa;
    code=scan.readCode();
    return 0;
}
