/*
Class: CPSC 122
Section: 01
Team Member 1: Nathan Mautz
Team Member 2: None
Submitted By: Nathan Mautz
GU Username: nmautz
File Name: project3.cpp

Program will accept 4 parameter, a file used for input, a name for the output file, a mode(0 or 1), and a shift (1-25). The program will then either encrypt or decrypt the input file using the shift as the key, and put the transformed message in a file with a givin name

To Build: g++ project3.cpp -o project3
To Execute: ./project3 inputFile outputFile mode shift
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
/*
pre: ch is the character to be encoded
shift is an integer in the range [1,25]

Post: returns an encrypted character

*/
char encrypt(char ch, int shift)
{

   int ich = (int)ch;

   ich = ich - (int)'A';

   ich = (ich + shift)%26;

   ich += (int)'A';

   return ich;


}

/*
pre: ch is the character to be decoded
shift is an integer in the range [1,25]

Post: returns a decrypted character

*/

   
char decrypt(char ch, int shift)
{
   int ich = (int)ch;

   ich = ich - (int)'A';

   ich = (ich - shift+26)%26;

   ich += (int)'A';

   return ich;



}
/*
Pre: shift is an intager in the range [1,25]

Post: File "fout" will contain the encrypted file
*/
void encryptFile(std::ifstream& fin, std::ofstream& fout, int shift)
{
   while(fin.peek() != EOF)
   {
      char ch = fin.get();

      if(isalpha(ch))
      {
         fout << encrypt((char)toupper(ch),shift);
      
      }else
      {
         fout << ch;

      }  
      

   } 

   fout << std::endl;

}
/*
Pre: shift is an intager in the range [1,25]

Post: File "fout" will contain the decrypted file
*/
void decryptFile(std::ifstream& fin, std::ofstream& fout, int shift)
{

   while(fin.peek() != EOF)
   {
      char ch = fin.get();

      if(isalpha(ch))
      {
         fout << decrypt(ch, shift);   

      }else
      {
         fout << ch;

      }
   }
   fout << std::endl;
}

void checkInput(int argc, char* argv[])
{
   if(argc != 7)
   {
      std::cout << "Incorrect number of arguments" << std::endl;
      exit(EXIT_FAILURE);
   }
   if(atoi(argv[4]) < 0 || atoi(argv[4]) > 1)
   {
      std::cout << "Mode is either 0 or 1" << std::endl;
      exit(EXIT_FAILURE);
   }
   if(atoi(argv[5]) < 1 || atoi(argv[5]) > 25)
   {
      std::cout << "Alpha must be in range 1 - 25" << std::endl;
      exit(EXIT_FAILURE);
   }
   if(atoi(argv[6]) < 1 || atoi(argv[6]) > 25)
   {
      std::cout << "Beta must be in range 1 - 25" << std::endl;
      exit(EXIT_FAILURE);  
   }

}




int* readMultInvFile(char* fileName)
{
   int* multHash = new int[26];
   std::ifstream fin;
   fin.open(fileName);
   int i = 0;
   while(fin.peak() != EOF)
   {
      multHash[i] = fin.get


   }


   fin.close(); 
}


int main(int argc, char* argv[])
{
   checkInput(argc, argv);
   std::ifstream fin;
   std::ofstream fout;
   
   fin.open(argv[1]);
   fout.open(argv[2]);
   
   if(argv[3][0] == '0')
   {
      encryptFile(fin, fout, atoi(argv[4])); 

   }else if(argv[3][0] == '1')
   {
     decryptFile(fin, fout, atoi(argv[4])); 

   }


   fin.close();
   fout.close();
   return 0;

}
