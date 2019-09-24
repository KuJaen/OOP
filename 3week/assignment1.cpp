#include <iostream>

void code(){}
int bss;

int main(){
	static const int rodata = 1;
	static int data = 1;
	int* heap = new int(1);
	int stack = 1; 

	std::cout << "code\t" << (void*) code << std::endl;
	std::cout << "rodata\t" << &rodata << std::endl;
	std::cout << "data\t" << &data << std::endl;
	std::cout << "BSS\t" << &bss << std::endl;
	std::cout << "Heap\t" << heap << std::endl;
	std::cout << "Stack\t" << &stack << std::endl;
	return 0;
}
