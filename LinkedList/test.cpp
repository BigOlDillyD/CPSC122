#include <iostream>
#include <cstdlib>
#include "LinkedList.h"


int main(int argc, char** argv)
{

   LinkedList<int> list;

   list.set(0,5);

   list.add(500);

   list.add(5000);
   
   list.add(999);

   std::cout << list.get(0) << " "  << list.get(1) << " " << list.get(2) << " " << list.get(3) << std::endl;   
   
   list.remove(1);
  
   std::cout << list.get(0) << " "  << list.get(1) << " " << list.get(2) << std::endl;
   
   return 0;
}
