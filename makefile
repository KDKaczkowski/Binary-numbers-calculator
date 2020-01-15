makefile: a.out
	./a.out
a.out: main.o zbior.o liczba.o
	g++ main.o zbior.o liczba.o
main.o: main.cpp liczbazbior.h
	g++ -c -Wall -pedantic main.cpp
zbior.o: liczbazbior.h zbior.cpp
	g++ -c -Wall -pedantic zbior.cpp
liczba.o: liczbazbior.h liczba.cpp
	g++ -c -Wall -pedantic liczba.cpp