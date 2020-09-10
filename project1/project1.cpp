/*
Class: CPSC 122
Section: 01
Team Member 1: Nathan Mautz
Team Member 2: None
Submitted By: Nathan Mautz
GU Username: nmautz
File Name: project1.cpp
*/


#include <iostream>
#include <stdlib.h>  
#include <time.h> 
#include <fstream>





bool isPrime(int num){

	

	if(num <= 1) return false;
	
	for(int i = 2; i < num; i++){
	
		if(num % i == 0){	
			return false;
			
		}

	
	}
	
	return true;

}




int* generatePrimeNumbers(int count){ 
	
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
			if(isPrime(num)){
				found = true;
				primeNums[i] = num;
			}
		}

	}
	
	return primeNums;

}



void printPrimeNums(int count, int columns, std::ofstream& outputFile){
	
	
	
	int index = 0;
	int columnIndex = 0;

	int *primeNums = generatePrimeNumbers(count);
	
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





int main(int argc, char* argv[]){

	
	
	
	if(argc != 4){
		std::cout << "Incorrect count of arguments given: " << argc << std::endl;
		return 0;
	
	
	}
	
	
	
	
	std::ofstream outputFile;
	outputFile.open(argv[3]);
	  	

  	printPrimeNums(std::stoi(argv[1]), std::stoi(argv[2]), outputFile);
  	
  
	
	outputFile.close();


	return 0; 
}
