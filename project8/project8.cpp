#include "project8.h"
#include <iostream>

template <typename T>
List2<T>::List2()
{

   head = new doubleNode<T>();

   tail = head;

   head->prev = NULL;

   tail->next = NULL;

   length = 0;

}




template <typename T>
List2<T>::List2(List2<T>* lst)
{
   head = new doubleNode<T>();

   tail = head;

   head->prev = NULL;

   tail->next = NULL;

   length = 0;

   for(int i = 0; i < lst->length; i++)
   {
      doubleNode<T>* tmp = lst->FindPosition(i);
      Insert(tmp->item, i);      

   }   


   
}




template <typename T>
List2<T>::~List2()
{
  
   while(head->next != NULL)
   {
      doubleNode<T>* tmp = head->next;
      delete head;
      head = tmp;
   }
   delete head;
}

template <typename T>
void List2<T>::Insert(T item, int pos)
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
      tail->next = new doubleNode<T>();
      tail->next->prev = tail;
      tail = tail->next;
      tail->item = item;
      tail->next = NULL;
      length++;
      return;
   }

   if(pos == 0)
   {
      doubleNode<T>* tmp = new doubleNode<T>();
      tmp->next = head;
      tmp->item = item;
      tmp->prev = NULL;
      head->prev = tmp;
      head = tmp;
      length++;
      return;

   }

   doubleNode<T>* tmp = FindPosition(pos-1);
   doubleNode<T>* newNode = new doubleNode<T>();
   newNode->prev = tmp;
   newNode->next = tmp->next;
   newNode->item = item;
   tmp->next = newNode;
   newNode->next->prev = newNode;
   length++;
}

template <typename T>
void List2<T>::Delete(int pos)
{
   if(length == 1)
   {
      length = 0;
      return;
   }
   
   if(pos == length-1)
   {
      doubleNode<T>* tmp = tail;
      
      tail = tail->prev;

      tail->next = NULL;

      delete tmp;
      
      length--;
      
      return;
   }
   
   if(pos == 0)
   {
      doubleNode<T>* tmp = head;
   
      head = head->next;

      head->prev = NULL;

      delete tmp;

      length--;

      return;
   }

   doubleNode<T>* tmp = FindPosition(pos);
   
   tmp->next->prev = tmp->prev;

   tmp->prev->next = tmp->next;

   delete tmp;
   
   length--;
}

template <typename T>
void List2<T>::PrintForward()
{
   doubleNode<T>* tmp = head;

   while(tmp->next != NULL)
   {
      std::cout << tmp->item << ", ";
      tmp = tmp->next;
   }

   std::cout << tmp->item << std::endl;

}


template <typename T>
void List2<T>::PrintBackwards()
{

   doubleNode<T>* tmp = tail;
   while(tmp->prev != NULL)
   {
      std::cout << tmp->item << ", ";
      tmp = tmp->prev;
   }
   std::cout << tmp->item << std::endl;
}


template <typename T>
void List2<T>::Sort()
{
   bool finished = false;
   int swaps = 0;
   while(!finished)
   {
      for(int i = 0; i < length; i++)
      {
         doubleNode<T>* tmp1 = FindPosition(i);
         doubleNode<T>* tmp2;
         if(tmp1->next != NULL)
         {
            tmp2 = FindPosition(i+1);
            if(tmp1->item > tmp2->item)
            {
               T tmp = tmp2->item;
               tmp2->item = tmp1->item;
               tmp1->item = tmp;
               swaps++;
            }
         }


      }
      
      if(swaps == 0)
      {
         finished = true;
      }else
      {
         swaps = 0;
      }

   }


   

}



template <typename T>
doubleNode<T>* List2<T>::FindPosition(int pos)
{
   
   doubleNode<T>* tmp = head;
   for(int i = 0; i < pos; i++)
   {
      tmp = tmp->next;

   }
   return tmp;

}

template class List2<int>;
template class List2<float>;
template class List2<double>;
template class List2<char>;


