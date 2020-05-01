output: intr_poly_tester.o poly.o
	g++ -std=c++0x -Wall intr_poly_tester.o poly.o -o output

intr_poly_tester.o: intr_poly_tester.cpp
	g++ -c intr_poly_tester.cpp

poly.o: poly.cpp polygif.cpp polygif.cpp poly.h
	g++ -c poly.cpp

clean:
	rm *.o output
