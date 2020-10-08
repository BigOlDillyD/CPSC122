#pragma once


class TransCypher
{


   public:
      TransCypher(char*, char*, int);
       
      void key_gen(char*);

      void transformFile();

      char transform(char, int[26][2]);
      
      void readKeyFromFile(int[26][2], char*, int);
     
   private:
      
      int key[26][2];
      
      int mode;

      char* inputFileName;
      
      char* outputFileName;

      void selectionSort(int[26][2]);

      void swap(int[26][2], int, int);

      int findSmallest(int[26][2], int);

      void arrayToFile(int[26], char*);
     
};






