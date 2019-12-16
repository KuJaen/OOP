#pragma once
#ifndef ARRAY_2D_H
#define ARRAY_2D_H

#include "big_block.h"
#include "block.h"
#include "color_block.h"
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class array_2d {
public:
	array_2d();
	bool can_make(int type);
	block *get_block(int x, int y);
	void move(big_block* bb, char input);
	void print();
	void explosion();
	int get_score();
	void set_BlockLocation(big_block* bb, int pre_x, int pre_y);
	void delete_block(big_block* bb);
	void gravity();
	void NBom(int i, int j);

private:
	block *block_array[12][5];
	int score;
};

#endif // ARRAY_2D_H