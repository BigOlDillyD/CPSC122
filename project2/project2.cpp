#include <iostream>
#include <fstream>


char encrypt(char ch, int shift)
{

   int ich = (int)ch;

   ich = ich - (int)'A';

   ich = (ich + shift)%26;

   ich += (int)'A';

   return ich;


}

char decrypt(char ch, int shift)
{
   int ich = (int)ch;

   ich = ich - (int)'A';

   ich = (ich - shift+26)%26;

   ich += (int)'A';

   return ich;



}

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


     
   //std::cout << atoi(argv[4]) << std::endl;

   fin.close();
   fout.close();
   return 0;

}
