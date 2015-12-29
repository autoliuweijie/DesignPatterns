#makefile create main
main: main.o
	g++ -o main main.o -lstdc++
main.o: main.cpp
	g++ -Wall -c main.cpp -o main.o
clean:
	rm -rf main.o