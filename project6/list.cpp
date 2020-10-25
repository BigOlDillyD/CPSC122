#include "list.h"
#include <iostream>

List::List()
{

   length = 0;
   
   head = new node();
   
   head->next = NULL;

}


List::~List()
{

   while(head->next != NULL)
   {
      node* tmp = head->next;
      delete head;
      head = tmp;
   }
   delete head;
}


bool List::IsEmpty() const
{

   if(length == 0)
      return true;
   return false;
   

}

void List::PutItemH(const itemType newItem)
{
   if(length == 0)
   {
      head->item = newItem;
      length++;
      return;
   }

   node* tmp = new node();
   
   tmp->next = head;
   
   tmp->item = newItem;
   
   head = tmp;

   length++;

}

itemType List::GetItemH() const
{
   return head->item;
}

void List::DeleteItemH()
{
   if(length == 1)
   {
      length = 0;
   }   

   node* tmp = head;

   head = head->next;

   delete tmp;
}

int List::Find(const itemType item) const
{

   node* tmp = head;
   for(int i = 0; i <= length; i++)
   {
      if(tmp->item == item)
         return i;
      i++;
      tmp = tmp->next;

   }

   return -1;
}


void List::Print() const
{
   node* tmp = head;
   while(tmp->next != NULL)
   {  
      std::cout << tmp->item << ", ";
      tmp = tmp->next;
   }

   std::cout << tmp->item << std::endl;
}




