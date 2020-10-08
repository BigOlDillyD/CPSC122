#ifndef _TransCypher_h_
#define _TransCypher_h_

#include <ctime>
#include <fstream>

class TransCypher
{


   public:
      TransCypher(char*, char*, char*, int);
       
      void key_gen();

      void transformFile();

      char transform(char);
      
      void readKeyFromFile();
     
   private:
      
      int key[26][2];
      
      int mode;

      char* keyFileName;

      char* inputFileName;
      
      char* outputFileName;

      void selectionSort(int[26][2]);

      void swap(int[26][2], int, int);

      int findSmallest(int[26][2], int);

      void arrayToFile();
     
};



#endif


