#include <cstdlib>
#include "TransCypher.h"


int main(int argc, char** argv)
{

   if(argc == 2)
   {
      TransCypher cypher(argv[1]);
   }

   else
   {
      TransCypher cypher(argv[1], argv[2], argv[3], atoi(argv[4]));
      cypher.transformFile();
   }

   return 0;

}
