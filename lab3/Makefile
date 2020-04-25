output: main.o sequence1.o
	g++ -std=c++0x -Wall main.o sequence1.o -o output

main.o: main.cpp
	g++ -c main.cpp

sequence1.o: sequence1.cpp sequence1.h
	g++ -c sequence1.cpp

clean:
	rm *.o output
