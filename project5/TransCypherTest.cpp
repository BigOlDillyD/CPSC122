#include <iostream>
#include "TransCypher.h"




int main(int argc, char* argv[])
{
   TransCypher cypher(argv[1], argv[2], argv[3], atoi(argv[4])); 
   
   cypher.key_gen();

   cypher.readKeyFromFile();

   cypher.transformFile();   
   

}
