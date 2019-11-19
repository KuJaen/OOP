.SUFFIXES: .cpp .o

test: Complex.o Float.o Integer.o test.o

	g++ -o test Complex.o Float.o Integer.o test.o

CXX = g++

Integer.o : Integer.cpp
	g++ -c -o Integer.o Integer.cpp
Float.o : Float.cpp
	g++ -c -o Float.o Float.cpp
Complex.o : Complex.cpp
	g++ -c -o Complex.o Complex.cpp
test.o : test.cpp
	g++ -c -o test.o test.cpp

clean :
	rm *.o test

