#ifndef _DoubleLL_h_
#define _DoubleLL_h_

template <typename T>
struct dNode
{
   
   dNode<T>* prev;
   T data;
   dNode<T>* next;


};


template <typename T>
class DoubleLL
{

   public:
      DoubleLL()
      {
         head = new dNode<T>();

         tail = new dNode<T>();

         head->prev = NULL;

         tail->next = NULL;          
      } 


   private:
      dNode<T>* head;
      dNode<T>* tail;
      








};




















#endif
