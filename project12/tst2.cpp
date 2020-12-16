#include <iostream>
#include "queue3.cpp"

int main(int argc, char** argv)
{
PQueue<char*>* pque = new PQueue<char*>;
pque->Enqueue(3,argv[4]);
pque->Enqueue(2,argv[2]);
pque->Enqueue(4,argv[3]);
pque->Print();

delete pque;



}
