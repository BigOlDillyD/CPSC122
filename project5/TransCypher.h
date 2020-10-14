#ifndef _TransCypher_h_
#define _TransCypher_h_

#include <ctime>
#include <fstream>

class TransCypher
{


   public:
      TransCypher(char*, char*, char*, int);

      TransCypher(char*);
 
      void transformFile();

    
   private:
      
      int key[26];
      
      int mode;

      char transform(char);

      char* keyFileName;

      char* inputFileName;
      
      char* outputFileName;

      void sort();
     
      void key_gen();

      void readKeyFromFile();    

      void swap(int[26][2], int, int);

      int findSmallest(int[26][2], int);

      void keyToFile();
     
};



#endif


