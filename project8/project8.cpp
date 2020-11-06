#include "project8.h"
#include <iostream>


List2::List2()
{

   head = new doubleNode();

   tail = head;

   head->prev = NULL;

   tail->next = NULL;

   length = 0;

}





List2::List2(List2* lst)
{
   head = new doubleNode();

   tail = head;

   head->prev = NULL;

   tail->next = NULL;

   length = 0;

   for(int i = 0; i < lst->length; i++)
   {
      doubleNode* tmp = lst->FindPosition(i);
      Insert(tmp->item, i);      

   }   


   
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

void List2::Insert(itemType item, int pos)
{
   
   if(length == 0)
   {
      head->item = item;
      head->next = NULL;
      head->prev = NULL;
      length = 1;
      return;
   }

   if(pos == length)
   {
      tail->next = new doubleNode();
      tail->next->prev = tail;
      tail = tail->next;
      tail->item = item;
      tail->next = NULL;
      length++;
      return;
   }

   if(pos == 0)
   {
      doubleNode* tmp = new doubleNode();
      tmp->next = head;
      tmp->item = item;
      tmp->prev = NULL;
      head->prev = tmp;
      head = tmp;
      length++;
      return;

   }

   doubleNode* tmp = FindPosition(pos-1);
   doubleNode* newNode = new doubleNode();
   newNode->prev = tmp;
   newNode->next = tmp->next;
   newNode->item = item;
   tmp->next = newNode;
   newNode->next->prev = newNode;
   length++;
}


void List2::Delete(int pos)
{
   if(length == 1)
   {
      length = 0;
      return;
   }
   
   if(pos == length-1)
   {
      doubleNode* tmp = tail;
      
      tail = tail->prev;

      tail->next = NULL;

      delete tmp;
      
      length--;
      
      return;
   }
   
   if(pos == 0)
   {
      doubleNode* tmp = head;
   
      head = head->next;

      head->prev = NULL;

      delete tmp;

      length--;

      return;
   }

   doubleNode* tmp = FindPosition(pos);
   
   tmp->next->prev = tmp->prev;

   tmp->prev->next = tmp->next;

   delete tmp;
   
   length--;
}


void List2::PrintForward()
{
   doubleNode* tmp = head;

   while(tmp->next != NULL)
   {
      std::cout << tmp->item << ", ";
      tmp = tmp->next;
   }

   std::cout << tmp->item << std::endl;

}



doubleNode* List2::FindPosition(int pos)
{
   
   doubleNode* tmp = head;
   for(int i = 0; i < pos; i++)
   {
      tmp = tmp->next;

   }
   return tmp;

}


