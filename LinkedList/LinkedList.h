#ifndef _LinkedList_h_
#define _LinkedList_h_

#include "node.h"

template<class T>
class LinkedList
{

   public:

      LinkedList()
      {
         this->length = 0;
   
         firstNode = new node<T>();

      }
      
      LinkedList(const LinkedList<T> &other)
      {
//         other.getLength();         


      }

      ~LinkedList()
      {
         while(length > 1)
            remove(length-1); 
        
         delete[] firstNode;

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
            set(0,data);
            length++;
            return;
         }
       
         node<T>* currentNode = getNode(length-1);
     
         currentNode->next = new node<T>();
      
         currentNode = currentNode->next;
      
         currentNode->data = data;
         
         length++;      
      }
     

      T get(int index) const
      {
         
         node<T>* currentNode = getNode(index);
         
       
         return currentNode->data;
      
      }
      


      void remove(int index)
      {
         std::cout << "Index: " << index << std::endl;
         node<T>* toRemove = getNode(index);
         node<T>* before = getNode(index-1);
         std::cout << "Check 1" << std::endl; 
         before->next = toRemove->next;
         std::cout << "Check 3" << std::endl;
         delete[] toRemove;
         std::cout << "Check 4" << std::endl;

         length--;
      }
 
      int getLength() const
      {

         return length;

      }
     
       


   private:
      node<T>* getNode(int index) const
      {
         node<T>* currentNode = firstNode;
               
         int i = 0;
            
         while(i != index)
         {
            currentNode = currentNode->next;
            i++;
            
         }
         return currentNode;
      }


      node<T>* firstNode;
      int length;
};

#endif
