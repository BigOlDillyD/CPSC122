#include <iostream>
using namespace std;

#include "calc2.h"
#include <cstring>
#include <cstdlib>




Calc::Calc(int argcIn, char* argvIn[])
{
   inFix = new char[strlen(argvIn[1])];
   strcpy(inFix, argvIn[1]);
   stk = new Stack(); 
   MakeTokenHash();
   if(!CheckTokens() && !CheckParens())
   {
      std::cout << "Input Error" << std::endl;
      exit(EXIT_FAILURE);
   }
   values = new int[26];  

   for(int i = 2; i < argcIn; i++)
      values[i-2] = atoi(argvIn[i]);

 
   postFix = new char(strlen(inFix)); 
   InFixToPostFix();
}

Calc::~Calc()
{

   delete[] inFix;
   delete[] values;
   delete[] stk;
   delete[] postFix;
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
 
   if(stkLen == 0)
      return true;
   return false;
}

void Calc::InFixToPostFix()
{

   delete stk;
   stk = new Stack();

   int c = 0;
   int stkLen = 0;
   for(int i = 0; i < strlen(inFix); i++)
   {
      if(IsOperand(inFix[i]))
      {
         postFix[c] = inFix[i]; c++;      
      }
      else if(inFix[i] == '(')
      {
         stk->Push('('); stkLen++; 
      }
      else if(inFix[i] == ')')
      {
         while(stkLen != 0 && (char)stk->Peek() != '(')
         {
            postFix[c] = (char)stk->Peek(); stk->Pop(); c++; stkLen--;


         }
         if(stkLen != 0)
         {
            stk->Pop(); stkLen--;
         }
      }
      else
      {

         Precedence(inFix[i], stkLen, c);
      }
   }

   while(stkLen != 0)
   {

      postFix[c] = stk->Peek(); c++; stk->Pop(); stkLen--;
   }

}




bool Calc::IsOperand(char c)
{
   for(int i = 65; i <= 90; i++)
   {


      if(c == (char)i)
         return true;
   }
   
   return false;


}

void Calc::Precedence(char op, int &stkLen, int &c)
{


   int value = PrecVal(op);

   while(stkLen != 0 && value <= PrecVal((char)stk->Peek()))
   {

      postFix[c] = (char)stk->Peek();
      c++; stk->Pop(); stkLen--;
   } 
   
   stk->Push(op);
   stkLen++; 

}

int Calc::PrecVal(char ch)
{
   switch(ch)
   {
   case '+':
   case '-':
      return 0;

   case '/':
   case '*':
      return 1;

   }
   
   return -1;

}



int Calc::Evaluate()
{

   delete stk;
   stk = new Stack();
   int total = 0;
   int stkLen = 0;
   int c = 0;
   for(int i = 0; i < strlen(postFix); i++)
   {
      if(IsOperand(postFix[i]))
      {
         stk->Push(values[c]); stkLen++;c++;
      }
      else if(stkLen >= 2)
      {

         
         int num = stk->Peek(); stk->Pop(); stkLen--;
         int num2 = stk->Peek(); stk->Pop(); stkLen--;

         switch(postFix[i])
         {

            case '+':
               total+=(num2+num); 
               break;
            case '-':
               total+=(num2-num);
               break;
            case '/':
               total+=(num2/num);
               break;      
            case '*':
               total+=(num2*num);
               break;
         }
      }
      else
      {
         int num = stk->Peek(); stk->Pop();stkLen--;
   

         switch(postFix[i])
         {

            case '+':
               total+=num;
               break;
            case '-':
               total-=num;
               break;
            case '/':
               total/=num;
               break;      
            case '*':
               total*=num;
               break;
         }

      }

   }

   return total;
}

void Calc::DisplayInFix()
{
   std::cout << inFix << std::endl;
}

void Calc::DisplayPostFix()
{

   std::cout << postFix << std::endl;

}

