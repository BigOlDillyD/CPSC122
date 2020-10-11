#ifndef _Queue_h_
#define _Queue_h_

#include "node.h"

template<class T>
class Queue
{

   public:

      Queue()
      {
         this->length = 0;

      }
      
      Queue(const Queue<T>& other)
      {
         head = new node<T>();

         for(int i = 0; i < other.getLength(); i++)
            add(other.get(i));

         tail = getNode(length-1);
      }

      ~Queue()
      {
         while(length > 1)
            remove(length-1); 
        
         delete[] head;

      }


      void set(int index, T data)
      {
         node<T>* currentNode = getNode(index); 
   
         currentNode->data = data;
      }

      void add(T data)
      {  

         if(length == 0)
         {
            head = new node<T>();
            set(0,data);
            length++;
            tail = head;
            return;
         }
       
     
         tail->next = new node<T>();
      
         tail = tail->next;
      
         tail->data = data;
         
         length++;      
      }
     

      T get(int index) const
      {
         
         node<T>* currentNode = getNode(index);
         
       
         return currentNode->data;
      
      }
      


      void remove(int index)
      {
         
         if(index == 0){
            node<T>* tmp = head;

            head = head->next;

            delete[] tmp;
            length--;
            return;

         }
         
         node<T>* toRemove = getNode(index);
         node<T>* before = getNode(index-1);

         before->next = toRemove->next;

         delete[] toRemove;


         length--;
      }
 
      int getLength() const
      {

         return length;

      }
     
       


   private:
      node<T>* getNode(int index) const
      {
         node<T>* currentNode = head;
               
         int i = 0;
            
         while(i != index)
         {
            currentNode = currentNode->next;
            i++;
            
         }
         return currentNode;
      }


      node<T>* head;
      node<T>* tail;
      int length;
};

#endif
