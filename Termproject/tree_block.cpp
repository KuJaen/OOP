#include "tree_block.h"
#include <iostream>
#include <ctime>

// 持失切 1=A 2=B 3=C//
tree_block::tree_block() {
	srand((unsigned int)time(0));

	int randBlock = (rand() % 10) + 1;
	if (randBlock <= 3) {
		this->block_box[0][1] = new block('A',0,2);
	}
	else if (randBlock <= 6) {
		this->block_box[0][1] = new block('B', 0, 2);
	}
	else if (randBlock <= 9) {
		this->block_box[0][1] = new block('C', 0, 2);
	}
	else if (randBlock <= 10) {
		this->block_box[0][1] = new block('N', 0, 2);
	}

	randBlock = (rand() % 10) + 1;
	if (randBlock <= 3) {
		this->block_box[1][1] = new block('A', 1, 2);
	}
	else if (randBlock <= 6) {
		this->block_box[1][1] = new block('B', 1, 2);
	}
	else if (randBlock <= 9) {
		this->block_box[1][1] = new block('C', 1, 2);
	}
	else if (randBlock <= 10) {
		this->block_box[1][1] = new block('N', 1, 2);
	}

	randBlock = (rand() % 10) + 1;
	if (randBlock <= 3) {
		this->block_box[2][1] = new block('A', 2, 2);
	}
	else if (randBlock <= 6) {
		this->block_box[2][1] = new block('B', 2, 2);
	}
	else if (randBlock <= 9) {
		this->block_box[2][1] = new block('C', 2, 2);
	}
	else if (randBlock <= 10) {
		this->block_box[2][1] = new block('C', 2, 2);
	}

	this->block_box[0][0] = new block(' ', 0, 1);
	this->block_box[0][2] = new block(' ', 0, 3);
	this->block_box[1][0] = new block(' ', 1, 1);
	this->block_box[1][2] = new block(' ', 1, 3);
	this->block_box[2][0] = new block(' ', 2, 1);
	this->block_box[2][2] = new block(' ', 2, 3);
}
// 持失切 //