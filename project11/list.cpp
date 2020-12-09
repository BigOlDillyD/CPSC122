#include <iostream>
using namespace std;

#include "list.h"


//Non-recursive functions. I have written them for you.
List::List()
{
 head = NULL;
}

void List::PutItemH(itemType item)
{
 node* tmp = new node;
 tmp->item = item;
 tmp->next = head;
 head = tmp;
 tmp = NULL;
}

itemType List::GetItemH() 
{
 return head->item; 
}

void List::DeleteItemH()
{
 node* cur = head;
 head = head->next;
 delete cur;
 cur == NULL;
}


//Write the following functions recursively or in such a way that they use
//recursive functions


int List::GetLength()
{
   node* cur = head;
   int length = 0;
   if(cur != NULL)
   {
      length++;
      length = GetLength(cur, length);
   }  
   return length;
}

int List::GetLength(node* cur, int& ct)
{
   if(cur->next != NULL)
   {
      cur = cur->next;
      ct++;
      GetLength(cur,ct);
   }
   return ct;
}

bool List::IsEmpty() 
{
   return head == NULL; 
}

void List::Print( )
{

   node* cur = head;
   if(!IsEmpty())
   {
      Print(cur);
   } 


}

void List::Print(node* cur) 
{
   if(cur->next != NULL)
   {
      std::cout << cur->item << ", ";
      cur = cur->next;
      Print(cur);
   }else
   {
      std::cout << cur->item << std::endl;
   }

}

void List::PrintR( )
{
}

void List::PrintR(node* cur) 
{
}

List::~List()
{
}
