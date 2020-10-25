#include <iostream>
#include "list.h"

int main(int argc, char** argv)
{

   List* list = new List();
   
   list->PutItemH(1);

   list->PutItemH(2);

   list->PutItemH(490);
 
   list->Print(); 
   
   delete list;

}
