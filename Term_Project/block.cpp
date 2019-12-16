#include "block.h"

// 持失切 //
block::block(char color, int x, int y) {
	this->color = color;
	this->downable = true;
	this->x = x;
	this->y = y;
	this->group = new int(1);
}
// 持失切 //

// location //
void block::set_location(int x, int y) {
	this->x = x;
	this->y = y;
}

int block::get_x() {
	return this->x;
}
int block::get_y() {
	return this->y;
}
// location //

// color //
char block::get_color() {
	return this->color;
}
void block::set_color(char color) {
	this->color = color;
}
// color //

// downable //
bool block::get_downable()
{
	return downable;
}
void block::set_downable(bool able) {
	this->downable = able;
}
// downable //

// move //
void block::left() {
	this->y = this->y - 1;
}
void block::right() {
	this->y = this->y + 1;
}
void block::down() {
	this->x = this->x + 1;
}
// move //

// getGroup //
int* block::getGroup() {
	return this->group;
}
void block::addGroup() {
	*this->group = *this->group + 1;
}
void block::setGroup(int* group) {
	this->group = group;
}
void block::reset() {
	this->group = new int(1);
}
// getGroup //