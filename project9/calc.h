/*
Class: CPSC 122-0X
Paul De Palma
GU Username: nmautz
Submitted By: Nathan Mautz
GU Username: nmautz
File Name: calc.h
To Execute: ./calc "(A+B)" 27 32
*/

#ifndef CALC
#define CALC

#include "stack2.h"

class Calc 
{ 
  public: 
  /* 
  pre: none 
  post:
       Design/Code/Test in this order: 
       1. inFix points to newly allocated memory holding infix expression
       2. CheckTokens() has been invoked.  If it returns false, display a 
          message and exit the program.  
       3. CheckParens() has been invoked.  If it returns false, display a 
          message and exit the program.  

  */
  Calc(int argcIn, char* argvIn[]);

  ~Calc();

  /*
  pre: instance of Calc exists. 
  post: infix expression displayed
 */
  void DisplayInFix();

  /*
   pre:  instance of calculator exists and all input tokens are legal
   post: Using the stack technique discussed in class, returns true 
         if parentheses are balanced, false otherwise
  */
  bool CheckParens();

 private:
  /*
  pre:  invoked from constructor 
  post: returns true if all characters in the infix expression are legal,
        false otherwise.   Legal characters are ')', '(', '+','-','*','/',
        'A' ... 'Z'   
  */
  bool CheckTokens(); 
  void CreateHash();
  bool CheckChar(char ch);
  char*  inFix;     //null-terminated string that holds infix expression 
  int*   values;    //pointer to an array holding expression values
  char hashTable[32]; 
  Stack* stk;
};
#endif 
