/*
Class: CPSC 122
Section: 01
Team Member 1: Nathan Mautz
Team Member 2: None
Submitted By: Nathan Mautz
GU Username: nmautz
File Name: project2.cpp

Program will accept 4 parameter, a file used for input, a name for the output file, a mode(0 or 1), and a shift (1-25). The program will then either encrypt or decrypt the input file using the shift as the key, and put the transformed message in a file with a givin name

To Build: g++ project2.cpp -o project2
To Execute: ./project2 inputFile outputFile mode shift
*/

#include <iostream>
#include <fstream>

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



int main(int argc, char* argv[])
{

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
