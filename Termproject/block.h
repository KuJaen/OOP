#pragma once

#ifndef BLOCK_H
#define BLOCK_H

#include "color_block.h"


class block {
public:
	block(char color, int x, int y);
	char get_color();
	int get_x();
	int get_y();
	//void set_group(color_block *group);
	//color_block *get_group();
	void set_location(int x, int y);
	//bool can_left();
	//bool can_right();
	bool get_downable();
	void set_downable(bool able);
	void right();
	void left();
	void down();
	//void down_all();
	//bool can_merge(block *b);
	//bool can_explosion(block *b);
	//void merge(block *b);
	//void find_merge();
	void set_color(char color);
	int* getGroup();
	void addGroup();
	void setGroup(int* group);
	void reset();

private:
	char color;
	int x, y;
	bool downable;
	int* group;
	//color_block *group;
};

#endif // BLOCK_H