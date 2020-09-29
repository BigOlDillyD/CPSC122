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

   std::cout << arr[0][0] << " " << arr[0][1] << std::endl;
   std::cout << arr[1][0] << " " << arr[1][1] << std::endl;
   
   swap(arr, 0, 1);
   
   std::cout << arr[0][0] << " " << arr[0][1] << std::endl;
   std::cout << arr[1][0] << " " << arr[1][1] << std::endl;

   return 0;
}
