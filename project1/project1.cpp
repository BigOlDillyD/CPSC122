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





bool IsPrime(int num){

	

	if(num <= 1) return false;
	
	for(int i = 2; i <= (num/2); i++){
	
		if(num % i == 0){	
			return false;
			
		}

	
	}
	
	return true;

}




int* GeneratePrimeNumbers(int count){ 
	
	//Creates int array of size count on the heap
	int *primeNums = new int[count];
	
	//Seeds random number generator
	srand(time(0));
	

	int num = 0;
	
	
	//Generates prime numbers
	for(int i = 0; i < count; i++){
		
		bool found = false;

		//Generates a random number, then checks if said number is prime.
		//If that number is prime, it is added to the primeNums array
		//the boolean "found" is then set to true so the loop can end.
		while(!found){

			num = rand()%100;
			if(IsPrime(num)){
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
	
	
	//Memory allocated on heap is destroyed
	delete[] primeNums;


}
	



int* GetInput()
{
	int *input = new int[2];

	std::cout << "How many prime numbers would you like to generate" << std::endl;
	
	while(std::cin >> input[0], std::cin.fail())
	{
		std::cout << "Input Error" << std::endl;

		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}	
	
	
	std::cout << "How many columns would you like?" << std::endl;
	
	while(std::cin >> input[1], std::cin.fail())
	{
		std::cout << "Input Error" << std::endl;

		std::cin.clear();
		std::cin.ignore(10000, '\n');

	}	

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
