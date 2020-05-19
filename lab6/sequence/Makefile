sequence: seq_test.o sequence.o node.o
	g++ -std=c++0x -Wall seq_test.o sequence.o node.o -o sequence

seq_test.o: seq_test.cpp
	g++ -c seq_test.cpp

sequence.o: sequence.cpp
	g++ -c sequence.cpp

node.o: node.cpp
	g++ -c node.cpp

clean:
	rm *.o sequence
