#include "vehicle.h"
#ifndef SMART_PTR_CAR_H
#define SMART_PTR_CAR_H

class car : public vehicle {
public:
	car();
	car(int wheel_number, int max_speed);
	car(int wheel_number, int max_speed, char* car_name);
	car(int wheel_number, int max_speed, char* car_name, bool has_name);

	char* get_car_name();
	const char* get_class_name();

	void set_car_name(char* car_name);

private:
	char* car_name;
};
#endif
