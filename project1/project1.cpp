/*
Class: CPSC 122
Section: 01
Team Member 1: Nathan Mautz
Team Member 2: None
Submitted By: Nathan Mautz
GU Username: nmautz
File Name: project1.cpp
Program accepts 3 parameters, the number of primes to be generated, the number of columns, and the name of the output file

To Build: g++ project1.cpp -o project1
To Execute: ./project1

*/


#include <iostream>
#include <stdlib.h>  
#include <time.h> 
#include <fstream>


/*
Pre: Integer is passed as argument
Post: Program will return true if num is prime, and false if num is not prime.
*/
bool is_prime(int num){




   if(num <= 1) return false;
   
   for(int i = 2; i <= (num/2); i++){
   
      if(num % i == 0){ 
         return false;
         
      }

   
   }
   
   return true;

}

/*
Pre: count must be >=1
Post: Will return pointer to an array of prime numbers 
*/


int* GeneratePrimeNumbers(int count){ 
   
   int *primeNums = new int[count];
   
   srand(time(0));
   

   int num = 0;
   
   
   //Generates prime numbers
   for(int i = 0; i < count; i++){
      
      bool found = false;

      while(!found){

         num = rand()%100;
         if(is_prime(num)){
            found = true;
            primeNums[i] = num;
         }
      }

   }
   
   return primeNums;

}



void PrintPrimeNums(int count, int columns, std::ofstream& outputFile){
   
   
   
   int index = 0;
   int columnIndex = 0;

   int *primeNums = GeneratePrimeNumbers(count);
   
   while(index < count){
   
      if(columnIndex < columns){
         
         outputFile << primeNums[index] << "   ";
         index++;
         columnIndex++;
         
      
      }else{
      
         columnIndex = 0;
         outputFile << std::endl;
      
      }
   

   }
   
   delete[] primeNums;


}
   

/*
Pre: None
Post: Will return pointer to array of integers that hold the users input
*/
  
int* GetInput()
{
   int *input = new int[2];

   std::cout << "How many prime numbers would you like to generate" << std::endl;
   
   std::cin >> input[0];   
   
   
   std::cout << "How many columns would you like?" << std::endl;
   
   std::cin >> input[1];

   
   return input;

}


int main(int argc, char* argv[]){

   
   
   
   if(argc != 2){
      std::cout << "Incorrect count of arguments given: " << argc << std::endl;
      return 0;
   
   
   }
   
   int *input = GetInput();   
      
   std::ofstream outputFile;
   outputFile.open(argv[1]);
      

   PrintPrimeNums(input[0], input[1], outputFile);
   
   delete[] input;
   
   outputFile.close();


   return 0; 
}
