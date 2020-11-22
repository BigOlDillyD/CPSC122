#include "calc.h"
#include <cstdlib>
#include <iostream>
#include <string.h>
Calc::Calc(int argcIn, char* argvIn[])
{
   inFix = argvIn[1];
   
   CreateHash();
 
   if(!CheckTokens())
   {

      std::cout << "Token error" << std::endl;
      exit(EXIT_FAILURE); 
   }

   if(!CheckParens())
   {
      
      std::cout << "Error with parens" << std::endl;
      exit(EXIT_FAILURE);
   }

}


Calc::~Calc()
{

}

void Calc::CreateHash()
{

   hashTable[0] = ')';
   hashTable[1] = '(';
   hashTable[2] = '+';
   hashTable[3] = '-';
   hashTable[4] = '*';
   hashTable[5] = '/';
   
   char ch = 'A';
   
   for(int i = 6; i < 32; i++)
   {
      hashTable[i] = ch;
      ch++;
   }
  


}
bool Calc::CheckParens()
{
   int parens = 0;

   for(int i = 0; i < strlen(inFix); i++)
   {
      if(inFix[i] == ')')
         parens--;

      if(inFix[i] == '(')
         parens++;
      if(parens == -1)
         return false;      
   }

   return parens == 0;
}


bool Calc::CheckTokens()
{
   for(int i = 0; i < strlen(inFix); i++)
   {
      if(!CheckChar(inFix[i]))
         return false; 

   }
   return true;
}


bool Calc::CheckChar(char ch)
{
   for(int i = 0; i < 32; i++)
   {
      if(ch == hashTable[i])
         return true;

   }
   
   return false;
}




void Calc::DisplayInFix()
{
   std::cout << inFix << std::endl;


}
