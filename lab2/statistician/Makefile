output: main.o statistician.o
	g++ -std=c++0x -Wall main.o statistician.o -o output

main.o: main.cpp
	g++ -c main.cpp

statistician.o: statistician.cpp statistician.h
	g++ -c statistician.cpp

clean:
	rm *.o output
