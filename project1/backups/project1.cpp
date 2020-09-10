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





int main(){

	std::cout << "How many prime numbers do you want to generate?" << std::endl;
	
	int count;
	
	std::cin >> count;
	
	std::cout << "How many columns do you want?" << std::endl;
	
	int columns;
	
	std::cin >> columns;
	
	std::ofstream outputFile;
	outputFile.open("output.txt");
  	
  	printPrimeNums(count,columns, outputFile);
	
	outputFile.close();


	return 0; 
}
