#include <iostream>
#include "queue3.h"

template <typename T>
PQueue<T>::PQueue() : Queue<T>()
{
   //Constructor inherited queue
}


template <typename T>
void PQueue<T>::Enqueue(int pty, T newItem)
{



   if(List<T>::length == 0)
   {

      List<T>::head = new node<T>();
      List<T>::head->pty = pty;
      List<T>::head->next = NULL;
      List<T>::head->item = newItem;
      List<T>::length++;
   }else
   {

      node<T>* tmp = new node<T>();
      tmp->pty = pty;
      tmp->item = newItem;
     
      node<T>* before = PtrTo(pty);
      
      if(before == NULL)
      {
         tmp->next = List<T>::head;
         List<T>::head = tmp;
      }else
      {
 
         if(before->next != NULL)
         {

            tmp->next = before->next;
            before->next = tmp;
         }else
         {

            tmp->next = NULL;
            before->next = tmp;
         }
      
         List<T>::length++;   
      }

   } 
      


   
}
template <typename T>
void PQueue<T>::Print() const
{

   node<T>* tmp = List<T>::head;
   while(tmp->next != NULL)
   {
      std::cout << tmp->pty << " " << tmp->item << std::endl;
      tmp = tmp->next;
   }
   std::cout << tmp->pty << " " << tmp->item << std::endl;



}

template <typename T>
node<T>* PQueue<T>::PtrTo(int pty)
{
   node<T>* cur = List<T>::head;
   node<T>* closest = List<T>::head;
   
   if(pty < cur->pty)
   {

      return NULL;
   }

   while(cur->next != NULL)
   {
      if(cur->pty <= pty && cur->pty > closest->pty)
         closest =cur;

      cur = cur->next;


   }
   if(cur->pty <= pty && cur->pty > closest->pty)
      closest =cur;

   cur = cur->next;



   return closest;


}

