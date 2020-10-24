#include <iostream>
#include "list.h"

int main(int argc, char** argv)
{

   List* list = new List();
   
   list->PutItemH(1);

   list->PutItemH(2);
 
   std::cout << list->Find(1) << std::endl;
 
   
   delete list;

}
