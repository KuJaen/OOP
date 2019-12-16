#include "big_block.h"
#include <iostream>
#include <ctime>

// delete //
big_block::~big_block() {
	delete block_box;
}
// delete //

// rotate //
void big_block::rotate() {
	char temp = this->block_box[0][1]->get_color();

	this->block_box[0][1]->set_color(this->block_box[1][2]->get_color());
	this->block_box[1][2]->set_color(temp);

	temp = this->block_box[0][1]->get_color();
	this->block_box[0][1]->set_color(this->block_box[2][1]->get_color());
	this->block_box[2][1]->set_color(temp);

	temp = this->block_box[0][1]->get_color();
	this->block_box[0][1]->set_color(this->block_box[1][0]->get_color());
	this->block_box[1][0]->set_color(temp);
}
// rotate //

// move //
void big_block::left() {
	this->y = this->y - 1;
}
void big_block::right() {
	this->y = this->y + 1;
}
void big_block::down() {
	this->x = this->x + 1;
}

bool big_block::move(char input) {
	if (input == 'a') {
		this->left();

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				this->block_box[i][j]->left();
			}
		}
		return true;
	}
	else if (input == 'd') {
		this->right();

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				this->block_box[i][j]->right();
			}
		}
		return true;
	}
	else if (input == 's') {
		this->down();
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (this->block_box[i][j]->get_downable()) {
					this->block_box[i][j]->down();
				}
			}
		}
		
		return true;
	}
	else if (input == 'e') {
		this->rotate();
		return true;
	}
	return false;
}
// move //

// get x, y //
int big_block::get_x() {
	return this->x;
}
int big_block::get_y() {
	return this->y;
}
bool big_block::is_block(int x, int y) {
	if (this->block_box[x][y]->get_color() == ' ') {
		return false;
	}
	return true;
}
block* big_block::get_block(int x, int y) {
	return this->block_box[x][y];
}
// get x, y //