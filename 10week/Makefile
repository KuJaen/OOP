CXX = g++
test: vehicle.o car.o bike.o main.o
	g++ -o test vehicle.o car.o bike.o main.o

vehicle.o : vehicle.cpp
	g++ -c -o vehicle.o vehicle.cpp

car.o : car.cpp
	g++ -c -o car.o car.cpp

bike.o : bike.cpp
	g++ -c -o bike.o bike.cpp

main.o : main.cpp
	g++ -c -o main.o main.cpp

clean:
	rm *.o test
