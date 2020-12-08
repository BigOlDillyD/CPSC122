#MakeFile

make : test.o calc2.o stack2.o list.o
	g++ -o project10 test.o calc2.o stack2.o list.o
test.o : test.cpp
	g++ -c test.cpp
calc2.o : calc2.cpp calc2.h
	g++ -c calc2.cpp
stack2.o : stack2.cpp stack2.h
	g++ -c stack2.cpp
list.o : list.cpp list.h
	g++ -c list.cpp
clean : 
	rm -f *.o
run : 
	./project10 "(A+B)" 77 66
