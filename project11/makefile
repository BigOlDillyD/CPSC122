#makefile

make: listTst.o list.o 
	g++ -o project11 listTst.o list.o
list.o: list.cpp list.h 
	g++ -c list.cpp
listTst.o: listTst.cpp
	g++ -c listTst.cpp	
clean:
	rm -f *.o
