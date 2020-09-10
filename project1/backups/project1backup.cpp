#include <iostream>
#include <stdlib.h>  
#include <time.h> 
#include <fstream>



bool isPrime(int num){

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
	
	
	
	delete[] primeNums;


}


int* getInput(){

	int *input = new int[2];

	std::cout << "How many prime numbers do you want to generate?" << std::endl;
	
	std::cin >> input[0];
	
	std::cout << "How many columns do you want?" << std::endl;
	
	
	std::cin >> input[1];
	
	return input;



}


int main(){

	
	
	std::ofstream outputFile;
	outputFile.open("output.txt");
	
	int *input = getInput();
  	
  	printPrimeNums(input[0],input[1], outputFile);
  	
  	delete[] input;
	
	outputFile.close();


	return 0; 
}
