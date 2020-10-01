#include <iostream>
#include <ctime>
#include <fstream>
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



void arrayToFile(int key[26], char* fileName)
{
   std::ofstream fout;
   fout.open(fileName);

   for(int i = 0; i < 26; i++)
      fout << key[i] << std::endl; 
   fout.close();

}



void key_gen(int key[26], char* fileName)
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
   arrayToFile(key, fileName);
}


int main(int argc, char* argv[])
{
   
   
   int key[26];

   key_gen(key, argv[1]);


   for(int i = 0; i <26; i++)
   {
      std::cout << key[i] << std::endl;
   }





   return 0;
}
