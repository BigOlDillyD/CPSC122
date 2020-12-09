#include "calc2.h"


int main(int argc, char** argv)
{

   Calc* c = new Calc(argc, argv);

   c->DisplayInFix();

   c->DisplayPostFix();
}
