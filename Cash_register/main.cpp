#include <iostream>
#include <string>
#include "Product.h"
#include "Scanner.h"
#include "CasaController.h"
using namespace std;

int main()
{
    Scanner scan;
    CasaController casa;
    scan.readCode();
    return 0;
}
