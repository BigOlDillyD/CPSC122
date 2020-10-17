#include "TransCypher.h"
#include <cstring>

/*
Pre:

All inputs are valid, mode is an in in range 0 - 1.

Post:
Object is constructed and key is read from file.
*/
TransCypher::TransCypher(char* inputFileName, char* outputFileName, char* keyFileName, int mode)
{
   this->mode = mode;
   this->inputFileName = inputFileName;
   this->outputFileName = outputFileName;
   this->keyFileName = keyFileName;

   readKeyFromFile();
}


/*
Pre:

keyFileName is valid

Post:

Key is generated and written to file.

*/

TransCypher::TransCypher(char* keyFileName)
{
   this->keyFileName = keyFileName;
   key_gen();
   keyToFile();

}



/*

Post:

Key is generated,

*/

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


/*
Pre: None

Post:

File is transformed using a key and written to a file

*/

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



/*
Pre: ch is a valid char and is alpha

Post: transformed char is returned

*/

char TransCypher::transform(char ch)
{
   ch = toupper(ch);
   int iCH = ch - 'A';
   return (char)(key[iCH] + 'A');


}




/*
Pre: none

Post: key is read from file and saved in key

*/

void TransCypher::readKeyFromFile()
{
   std::ifstream fin;
   fin.open(keyFileName);
   int a;
   int count = 0;

   if(mode == 0)
   {
      while(count < 26 && fin >> a)
      {
         key[count] = a;
         count++;
      }
   }
   else
   {
      while(count < 52 && fin >> a)
      {
         if(count >= 26)
            key[count-26] = a;
      
         count++;
      }


   }

   
}

/*
Pre: none

Post: Key is sorted

*/
void TransCypher::sort()
{

   int tmp[26];
   for(int i = 0; i < 26; i++)
      tmp[key[i]] = i;

   std::memcpy(key, tmp, sizeof(key));
 
}
/*
Pre: none

Post: key is written to file. 

*/
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



