#include <iostream>
#include <ctime>
#include <fstream>




/*
Pre:

Post:
*/


void swap(int[26][2], int, int);

int findSmallest(int[26][2], int);

void selectionSort(int[26][2]);

void arrayToFile(int[26], char*);

void key_gen(char*);

void readKeyFromFile(int[26][2], char*, int);

char transform(char, int[26][2]);

void transformFile(char*, char*, int[26][2]);

int main(int argc, char* argv[])
{

   if(argc == 2)
   {
      key_gen(argv[1]);
      return 0;

   }

   int key[26][2];
   
   readKeyFromFile(key, argv[3], atoi(argv[4]));
  
   
   if(atoi(argv[4]) == 1)
      selectionSort(key);

   
   transformFile(argv[1],argv[2], key);
 
   return 0;
}


/*
Pre: input is the input file, output is the outputfile, key is filled with no duplicates and sorted.

Post: File is created with the transformed text
*/
void transformFile(char* input, char* output, int key[26][2])
{

   std::ifstream fin;
   std::ofstream fout;

   fin.open(input);
   fout.open(output);

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



/*
Pre: ch is the character to be transformed, key is filled with no duplicates and sorted.

Post: returns the transformed character.
*/
char transform(char ch, int key[26][2])
{
   ch = toupper(ch);
   int iCH = ch - 'A';
   
   

   return (char)(key[iCH][1]+'A');


}



/*
Pre: Key is the key, fileName is the name of the file to be read from, mode is an int 0 or 1

Post: Fills key with no duplicates, unsorted
*/
void readKeyFromFile(int key[26][2], char* fileName, int mode)
{
   for(int i = 0; i < 26; i++)
      key[i][mode] = i;


   std::ifstream fin;
   fin.open(fileName);

   for(int i = 0; i < 26; i++)
   {
      fin >> key[i][1-mode];
   } 
   
   fin.close();

}


/*
Pre: arr is a filled array, a is the index to be swapped, b is the other index to be swapped.

Post: Swapps contents at arr[a] with contents at arr[b], taking into account the 2D array
*/
void swap(int arr[26][2], int a, int b)
{
   int tmp[2];
   
   tmp[0] = arr[a][0];
   tmp[1] = arr[a][1];

   arr[a][0] = arr[b][0];
   arr[a][1] = arr[b][1];

   arr[b][0] = tmp[0];
   arr[b][1] = tmp[1];

}


/*
Pre: arr is a filled array, start is where the function should start searcing

Post: Returns the index of the smalles value in the array from start.
*/
int findSmallest(int arr[26][2], int start)
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

/*
Pre: arr is a filled array

Post: arr is sorted
*/
void selectionSort(int arr[26][2])
{

   int start = 0;
   
   while(start < 25)
   {
      int smallest = findSmallest(arr,start);
      if(smallest != start)
         swap(arr,smallest,start);

      start++;
   }
}

/*
Pre:

Post:
*/
void arrayToFile(int key[26], char* fileName)
{
   std::ofstream fout;
   fout.open(fileName);

   for(int i = 0; i < 26; i++)
      fout << key[i] << std::endl; 
   fout.close();

}

void key_gen(char* fileName)
{
   int key[26];
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
   arrayToFile(key, fileName);
}



