#include <iostream>
#include "list.h"
#include <cstdlib>
int main(int argc, char** argv)
{

   List* list = new List();
   
   list->PutItemH(1);

   list->PutItemH(2);

   list->PutItemH(490);
 
   list->Print(); 

   list->DeleteItem(atoi(argv[1]));

   list->Print();   
 
   delete list;

}
