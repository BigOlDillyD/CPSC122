#include "TransCypher.h"
#include <cstring>

TransCypher::TransCypher(char* inputFileName, char* outputFileName, char* keyFileName, int mode)
{
   this->mode = mode;
   this->inputFileName = inputFileName;
   this->outputFileName = outputFileName;
   this->keyFileName = keyFileName;

   readKeyFromFile();
}

TransCypher::TransCypher(char* keyFileName)
{
   this->keyFileName = keyFileName;
   key_gen();
   keyToFile();

}

void TransCypher::key_gen()
{
   for(int i = 0; i < 26; i++)
      key[i] = -1;   

   std::srand(time(0));
   for(int i = 0; i < 26; i++)
   {
      bool found = false;
      
      while(!found)
      {
         int index = std::rand()%26;
         if(key[index] == -1)
         {
            key[index] = i;
            found = true; 
         } 

      }
   }
}

void TransCypher::transformFile()
{

   std::ifstream fin;
   std::ofstream fout;

   fin.open(inputFileName);
   fout.open(outputFileName);

   while(fin.peek() != EOF)
   {
      char ch = fin.get();

      if(isalpha(ch))
         ch = transform(ch);

      fout << ch;


   }


   fin.close();
   fout.close();
}

char TransCypher::transform(char ch)
{
   ch = toupper(ch);
   int iCH = ch - 'A';
   return (char)(key[iCH] + 'A');


}

void TransCypher::readKeyFromFile()
{
   
}

void TransCypher::swap(int arr[26][2], int a, int b)
{
   int tmp[2];
   
   tmp[0] = arr[a][0];
   tmp[1] = arr[a][1];

   arr[a][0] = arr[b][0];
   arr[a][1] = arr[b][1];

   arr[b][0] = tmp[0];
   arr[b][1] = tmp[1];

}

int TransCypher::findSmallest(int arr[26][2], int start)
{
   int smallest = start;
   
   for(int i = start + 1; i < 26; i++)
   {
      if(arr[i][0] < arr[smallest][0])
      {
         smallest = i;

      }

   }
   return smallest;
}

void TransCypher::sort()
{

   int tmp[26];
   for(int i = 0; i < 26; i++)
      tmp[key[i]] = i;

   std::memcpy(key, tmp, sizeof(key));
 
}

void TransCypher::keyToFile()
{
   std::ofstream fout;
   fout.open(keyFileName);

   for(int i = 0; i < 26; i++)
      fout << key[i] << " ";

   fout << std::endl; 
   fout.close();

   sort();

   fout.open(keyFileName, std::ios::app);
   
   for(int i = 0; i < 26; i++)
      fout << key[i] << " ";
   
   fout.close();


}



