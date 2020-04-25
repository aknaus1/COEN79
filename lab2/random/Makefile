output: main.o random.o
	g++ -std=c++0x -Wall main.o random.o -o output

main.o: main.cpp
	g++ -c main.cpp

random.o: random.cpp random.h
	g++ -c random.cpp

clean:
	rm *.o output
