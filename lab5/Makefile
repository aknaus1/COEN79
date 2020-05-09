output: tester.o mystring.o
	g++ -std=c++0x -Wall tester.o mystring.o -o output

tester.o: tester.cpp
	g++ -c tester.cpp

mystring.o: mystring.cpp mystring.h
	g++ -c mystring.cpp

clean:
	rm *.o output
