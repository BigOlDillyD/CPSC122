#include "project8.h"
#include <iostream>


List2::List2()
{

   head = new doubleNode();

   tail = new doubleNode();

   head->prev = NULL;

   tail->next = NULL;

   length = 0;

}

List2::~List2()
{
  
   while(head->next != NULL)
   {
      doubleNode* tmp = head->next;
      delete head;
      head = tmp;
   }
   delete head;


 


}

