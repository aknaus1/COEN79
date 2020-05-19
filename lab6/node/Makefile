node: node_test.o node.o
	g++ -std=c++0x -Wall node_test.o node.o -o node

node_test.o: node_test.cpp
	g++ -c node_test.cpp

node.o: node.cpp node.h
	g++ -c node.cpp

clean:
	rm *.o node
