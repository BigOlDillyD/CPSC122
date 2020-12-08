#include <iostream>
using namespace std;

#include "calc2.h"
#include <cstring>

Calc::Calc(int argcIn, char* argvIn[])
{
   inFix = new char[strlen(argvIn[1])];
   strcpy(inFix, argvIn[1]); 
   MakeTokenHash();
   if(!CheckTokens() || !CheckParens())
   {
      std::cout << "Input Error" << std::endl;
      exit(EXIT_FAILURE);
   }
   values = new int[26]; 
   stk = new Stack();
  }

Calc::~Calc()
{

   delete[] inFix;
   delete[] values;
   delete[] stk;

}


void Calc::MakeTokenHash()
{
     
   legalTokens = new char[32];
      int c = 0;
      for(int i = 39; i <=47; i++)
      {
         if(i != 46 && i != 44)
         {
            legalTokens[c] = (char)i;
            c++; 
         }

      }  
      for(int i = 65; i <=90; i++)
      {
         legalTokens[c] = (char)i;
         c++;
      }





}


bool Calc::CheckTokens()
{
   for(int i = 0; i < strlen(inFix); i++)
   {
      if(!CheckToken(inFix[i]))
         return false;

   }
      

   return true;

}

bool Calc::CheckToken(char c)
{
   
   for(int i = 0; i < 32; i++)
   {
      if(c == legalTokens[i])
         return true;

   }
   return false;
}

bool Calc::CheckParens()
{
   int stkLen = 0;
   
   for(int i = 0; i < strlen(inFix); i++)
   {
      if(inFix[i] == '(')
      {
         stk->Push('(');
         stkLen++;
      }
      
      if(inFix[i] == ')')
      {
         if(stkLen != 0)
         {
            if(stk->Peek() == '(')
            {
               stk->Pop();
               stkLen--;
            }
         }else
         {
            return false;

         }
      }
   }
 

   return true;
}

void Calc::InFixToPostFix()
{}

int Calc::Evaluate()
{
 return 0;
}

void Calc::DisplayInFix()
{
   std::cout << inFix << std::endl;
}

void Calc::DisplayPostFix()
{}
