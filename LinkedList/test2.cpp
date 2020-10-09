#include <iostream>
#include "LinkedList.h"
#include <cstdlib>


int main(int argc, char** argv)
{

   LinkedList<int> list;


   for(int i = 0; i < atoi(argv[1]); i++)
   {

      list.add(i);
   }
   
   list.remove(atoi(argv[2]));


   for(int i = 0; i < list.getLength(); i++)
      std::cout << list.get(i) << std::endl;


   return 0;
}
