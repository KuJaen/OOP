#include "bike.h"

bike::bike() {
	this->set_has_name(false);
}
bike::bike(int wheel_number, int max_speed) {
	this->set_wheel_number(wheel_number);
	this->set_max_speed(max_speed);
}
bike::bike(int wheel_number, int max_speed, char* bike_name) {
	this->set_wheel_number(wheel_number);
	this->set_max_speed(max_speed);
	this->bike_name = bike_name;
}
bike::bike(int wheel_number, int max_speed, char* bike_name, int bike_number) {
	this->set_wheel_number(wheel_number);
	this->set_max_speed(max_speed);
	this->bike_name = bike_name;
	this->bike_number = bike_number;
}
bike::bike(int wheel_number, int max_speed, char* bike_name, int bike_number, bool has_name) {
	this->set_wheel_number(wheel_number);
	this->set_max_speed(max_speed);
	this->bike_name = bike_name;
	this->bike_number = bike_number;
	this->set_has_name(has_name);
}

int bike::get_bike_number() {
	return this->bike_number;
}
char* bike::get_bike_name() {
	return this->bike_name;
}
const char* bike::get_class_name() {
	return "bike";
}

void bike::set_bike_name(char* bike_name) {
	this->bike_name = bike_name;
}
void bike::set_bike_number(int bike_number) {
	this->bike_number = bike_number;
}