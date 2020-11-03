/*
Class: CPSC 122-01
Paul De Palma
GU Username: nmautz
Submitted By: Nathan Maurz
File Name: project7.cpp
Implimentation file for a simple linked list  
To Build: g++ project7Tst.cpp project7.cpp 
To Execute: ./a.out
*/




#include "project7.h"
#include <iostream>

List1::List1()
{

   length = 0;
   
   head = new node();
   
   head->next = NULL;

   tail = head;

}


List1::~List1()
{

   while(head->next != NULL)
   {
      node* tmp = head->next;
      delete head;
      head = tmp;
   }
   delete head;
}


bool List1::IsEmpty() const
{

   if(length == 0)
      return true;
   return false;
   

}

void List1::PutItemH(const itemType newItem)
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

itemType List1::GetItemH() const
{
   return head->item;
}

void List1::DeleteItemH()
{
   if(length == 1)
   {
      length = 0;
   }   

   node* tmp = head;

   head = head->next;

   delete tmp;
}



void List1::PutItemT(const itemType newItem)
{

   node* tmp = new node();

   tail->next = tmp;

   tmp = tail;

   tail = tmp->next;

   tail->item = newItem;

   length++;
}


itemType List1::GetItemT() const
{

   return tail->item;

}


void List1::DeleteItemT()
{

   if(length == 1)
   {
      length = 1;
   }


   delete tail;

   length--;

   tail = GetNode(length-1);

   tail->next = NULL;


}



int List1::FindItem(const itemType item) const
{

   node* tmp = head;
   for(int i = 0; i < length; i++)
   {
      if(tmp->item == item)
         return i;
      tmp = tmp->next;

   }

   return -1;
}


void List1::Print() const
{
   node* tmp = head;
   while(tmp->next != NULL)
   {  
      std::cout << tmp->item << ", ";
      tmp = tmp->next;
   }

   std::cout << tmp->item << std::endl;
}

int List1::GetLength() const
{
   return length;
}


node* List1::GetNode(int index) const
{
   node* currentNode = head;

   int i = 0;

   while( i != index)
   {
      currentNode = currentNode->next;
      i++;
   }
   return currentNode;
}


void List1::DeleteItem(const itemType target)
{

   node* tmp = head;

   for(int i = 0; i < length; i++)
   {
      if(tmp->item == target)
      {
         tmp = tmp->next;
         DeleteNode(i);       

      }else
      {
         tmp = tmp->next;
      }

   }
}

void List1::DeleteNode(const int pos)
{
   if(length == 1 || pos == 0)
   {
      DeleteItemH();
      return;
   }
   
   node* toRemove = GetNode(pos);
   node* before = GetNode(pos-1);

   before->next = toRemove->next;

   delete toRemove;

   length--;



}




