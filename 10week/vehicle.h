#include <iostream>
#ifndef SMART_PTR_VEHICLE_H
#define SMART_PTR_VEHICLE_H

class vehicle {
public:
	vehicle();
	vehicle(int wheel_number, int max_speed);
	vehicle(int wheel_number, int max_speed, bool has_name);

	int get_wheel_number();
	int get_max_speed();
	bool get_has_name();
	const char* get_class_name();

	void set_wheel_number(int wheel_number);
	void set_max_speed(int max_speed);
	void set_has_name(bool has_name);

private:
	bool has_name;
	int wheel_number;
	int max_speed;
};

#endif
