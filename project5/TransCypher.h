#pragma once



class TransCypher
{


   public:
      TransCypher(char*, char*, int);
       
      void key_gen(char*);

      void transformFile()
      {

         std::ifstream fin;
         std::ofstream fout;

         fin.open(inputFileName);
         fout.open(outputFileName);

         while(fin.peek() != EOF)
         {
            char ch = fin.get();
            if(isalpha(ch))
            ch = transform(ch, key);
            fout << ch;
         }     
         fin.close();
         fout.close();
      }     

      void readKeyFromFile(int[26][2], char*, int);

     
   private:
      
      int key[26][2];
      
      int mode;

      char* inputFileName;
      
      char* outputFileName;

           
      char transform(char, int[26][2]);


      void selectionSort(int[26][2]);

      void swap(int[26][2], int, int);

      int findSmallest(int[26][2], int);

      void arrayToFile(int[26], char*);
     
      

     
};









