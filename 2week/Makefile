CXX = g++

test : main.o print.o student_id.o
	g++ -o test main.o print.o student_id.o

main.o : main.cpp
	g++ -c -o main.o main.cpp

print.o : print.cpp
	g++ -c -o print.o print.cpp

student_id.o : student_id.cpp
	g++ -c -o student_id.o student_id.cpp

clean :
	rm *.o test
