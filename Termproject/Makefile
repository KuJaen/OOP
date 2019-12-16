CXX = g++
test: array_2d.o big_block.o block.o cross_block.o fold_block.o tree_block.o main.o
	g++ -o test array_2d.o big_block.o block.o cross_block.o fold_block.o tree_block.o main.o

array_2d.o : array_2d.cpp
	g++ -c -o array_2d.o array_2d.cpp

big_block.o : big_block.cpp
	g++ -c -o big_block.o big_block.cpp

block.o : block.cpp
	g++ -c -o block.o block.cpp

cross_block.o : cross_block.cpp
	g++ -c -o cross_block.o cross_block.cpp

fold_block.o : fold_block.cpp
	g++ -c -o fold_block.o fold_block.cpp

tree_block.o : tree_block.cpp
	g++ -c -o tree_block.o tree_block.cpp

main.o : main.cpp
	g++ -c -o main.o main.cpp

clean:
	rm *.o test


