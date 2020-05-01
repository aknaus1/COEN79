output: keyed_bag_tester.o keyed_bag.o
	g++ -std=c++0x -Wall keyed_bag_tester.o keyed_bag.o -o output

keyed_bag_tester.o: keyed_bag_tester.cpp
	g++ -c keyed_bag_tester.cpp

keyed_bag.o: keyed_bag.cpp keyed_bag.h
	g++ -c keyed_bag.cpp

clean:
	rm *.o output
