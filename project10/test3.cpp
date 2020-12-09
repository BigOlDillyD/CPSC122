#include <iostream>

void incx(int &x)
{
   x++;
}


int main(int argc, char** argv)
{

   int o = 0;
   incx(o);

   std::cout << o << std::endl;

   return 0;
}
