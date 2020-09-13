#include <iostream>
#include <fstream>


char encrypt(char ch, int shift);

char decrypt(char ch, int shift);

void parseFile(std::ifstream& fin, std::ofstream& fout)
{
   while(fin.peek() != EOF)
   {
      char ch = fin.get();

      if(isalpha(ch))
      {
         fout << (char)toupper(ch);
      
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

   parseFile(fin, fout);   


   fin.close();
   fout.close();
   return 0;

}
