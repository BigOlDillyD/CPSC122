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


struct Input{

	int count;
	int columns;
	std::string fileName;



};



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
	
	int *primeNums = new int[count];
	
	srand(time(0));

	int num = 0;
	for(int i = 0; i < count; i++){
		
		bool found = false;
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



void printPrimeNums(Input input, std::ofstream& outputFile){
	
	
	
	int index = 0;
	int columnIndex = 0;

	int *primeNums = generatePrimeNumbers(input.count);
	
	while(index < input.count){
	
		if(columnIndex < input.columns){
		
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


Input getInput(){

	Input input;
	
	std::cout << "What would you like to call the output file?(Do not add a file extention)" << std::endl;
	
	
	std::cin >> input.fileName;
	
	while(std::cin.fail()){
	
		std::cout << "ERROR" << std::endl;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		
		std::cout << "What would you like to call the output file?(Do not add a file extention)" << std::endl;
	
	
		std::cin >> input.fileName;
	
	
	}

	std::cout << "How many prime numbers do you want to generate?" << std::endl;
	
		
	std::cin >> input.count;
	std::cin.clear();
	std::cin.ignore(256,'\n');

	while(std::cin.fail()){
	
		std::cout << "ERROR" << std::endl;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		
		std::cout << "How many prime numbers do you want to generate?" << std::endl;
	
		std::cin >> input.count;
	
	
	}
	
	std::cout << "How many columns do you want?" << std::endl;
	
	
	std::cin >> input.columns;
	
	while(std::cin.fail()){
	
		std::cout << "ERROR" << std::endl;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		
		std::cout << "How many columns do you want?" << std::endl;
	
	
		std::cin >> input.columns;
	
	
	}
	
	
	

	
	return input;



}


int main(){

	Input input = getInput();
	std::ofstream outputFile;
	outputFile.open(input.fileName + ".txt");
	
	
  	
  	printPrimeNums(input, outputFile);
  	
  
	
	outputFile.close();


	return 0; 
}
