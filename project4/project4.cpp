#include <iostream>

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


void genArray(int arr[26][2])
{
   for(int i = 0; i < 26; i++)
   {
      arr[i][0] = 26 - i;
      arr[i][1] = i;
   }
}




int main(int argc, char* argv[])
{

   int arr[26][2];
   genArray(arr);
 
   
   for(int i = 0; i < 26; i++)
   {
      std::cout << arr[i][0] << " " << arr[i][1] << std::endl;
   }

   std::cout << "===========================" << std::endl;
   selectionSort(arr);
   
 
   
   for(int i = 0; i < 26; i++)
   {
      std::cout << arr[i][0] << " " << arr[i][1] << std::endl;
   }


   return 0;
}
