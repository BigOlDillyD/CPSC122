#include <iostream>
#include <cstdlib>
#include "Queue.h"


int main(int argc, char** argv)
{

   Queue<int> list;

   list.add(5);

   list.add(500);

   list.add(5000);
   
   list.add(999);

   std::cout << list.get(0) << " "  << list.get(1) << " " << list.get(2) << " " << list.get(3) << std::endl;   
   
//   Queue<int> list2 = list;

   

   

  // list.remove(0);
  
  // std::cout << list.get(0) << " "  << list.get(1) << " " << list.get(2) << std::endl;
   
   return 0;
}
