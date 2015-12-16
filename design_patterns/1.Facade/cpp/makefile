#makefile create main
main: main.o Facade.o
	g++ -o main Facade.o main.o -lstdc++
Facade.o: Facade.cpp
	g++ -Wall -c Facade.cpp -o Facade.o
main.o: main.cpp
	g++ -Wall -c main.cpp -o main.o
clean:
	rm -rf Facade.o main.o