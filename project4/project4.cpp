#include <iostream>
#include <ctime>
#include <fstream>
/*
Class: CPSC 122
Section: 01
Team Member 1: Nathan Mautz
Team Member 2: None
Submitted By: Nathan Mautz
GU Username: nmautz
File Name: project4.cpp

Program will take 1 of 2 paths:

If 2 paramaters are passed it will generate a key and save it into a file.

However if 5 arguments are passed it will transform a given file using a given key and save it in a file.

To Build: g++ project4.cpp -o project4
To Execute: 
   ./project4 infile outfile keyfile mode
   OR
   ./project4 keyfile
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
Pre: ch is the character to be transformed, key is a 2D transformation array

Post: looks up the positional value of ch in the 0th col of key, and returns the 1st col of key
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
Pre: Key is filled with data, fileName is the name of the file for key to be stored in

Post: File with the name fileName is created that stores key
*/
void arrayToFile(int key[26], char* fileName)
{
   std::ofstream fout;
   fout.open(fileName);

   for(int i = 0; i < 26; i++)
      fout << key[i] << std::endl; 
   fout.close();

}
/*
Pre: FileName is the file name that the key should be saved in

Post: A key will be generated then saved in a file named fileName
*/
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



