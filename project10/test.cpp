#include "calc2.h"
#include <iostream>

int main(int argc, char** argv)
{

   Calc* c = new Calc(argc, argv);





   std::cout << c->Evaluate() << std::endl;
}
