#pragma once

#ifndef BIG_BLOCK_H
#define BIG_BLOCK_H

#include "block.h"
using namespace std;

class big_block {
public:
	~big_block();
	void rotate();
	//bool can_rotate();
	//bool can_left();
	//bool can_right();
	//bool can_down();
	void left();
	void right();
	void down();
	//bool down_all();
	bool move(char input);
	int get_x();
	int get_y();
	bool is_block(int x, int y);
	block* get_block(int x, int y);

private:
	int x = 1;
	int y = 2;

protected:
	block* block_box[3][3];
};

#endif // BIG_BLOCK_H
