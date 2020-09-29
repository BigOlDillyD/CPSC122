#include <iostream>

void swap(int arr[6][2], int a, int b)
{
   int tmp[2];
   
   tmp[0] = arr[a][0];
   tmp[1] = arr[a][1];

   arr[a][0] = arr[b][0];
   arr[a][1] = arr[b][1];

   arr[b][0] = tmp[0];
   arr[b][1] = tmp[1];

}


int findSmallest(int arr[6][2], int start)
{
   int smallest = start;
   
   for(int i = start + 1; i < 6; i++)
   {
      if(arr[i][0] < arr[smallest][0])
      {
         smallest = i;

      }

   }
   return smallest;
}





void genArray(int arr[6][2])
{
   for(int i = 0; i < 6; i++)
   {
      arr[i][0] = i;
      arr[i][1] = 6 - i;


   }




}




int main(int argc, char* argv[])
{

   int arr[6][2];
   genArray(arr);
   arr[4][0] = -3;
   int smallest = findSmallest(arr, 0);
   std::cout << smallest << std::endl;
   
   return 0;
}
