#include <iostream>
using namespace std;
#include <cstdlib>
#include "list.h"
#define print(x) std::cout << x << std::endl;

int main(int argc, char** argv)
{
 List* lst1 = new List;
 for (int i = 0; i < atoi(argv[1]); i++)
  lst1->PutItemH(i);

 lst1->Print();

 lst1->PrintR();

 delete lst1; 
 return 0;
}
