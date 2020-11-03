#include <iostream>
#include "project7.h"
#include <cstdlib>
int main(int argc, char** argv)
{

   List1* list = new List1();

   list->PutItemH(8);

   list->PutItemH(7);

   list->PutItemT(9);

   list->Print();

   list->DeleteItemT();

   list->Print();
   
   std::cout << list->FindItem(atoi(argv[1])) << std::endl;
   delete list;
}
