#include <iostream>
#include "project8.h"


int main()
{

   List2<int>* lst = new List2<int>;

   lst->Insert(7,0);
   lst->Insert(8,1);
   lst->Insert(9,1);

   lst->PrintForward();

   lst->Insert(2,2);
   lst->PrintForward();

   delete lst;
   return 0;
}

