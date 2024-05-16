#include "Car.h"
class Car:public  Vehicle {
	
	Car::Car():Vehicle{
	
	}

	Car::Car(int wheelnumber, int maxspeed):Vehicle(wheel_name, max_speed){
		Car::set_wheel_number(wheelnumber);
		Car::set_max_speed(maxspeed);
		Car::get_wheel_number(wheelnumber);
		Car::get_max_speed(maxspeed);	
	}

	Car::Car(int wheelnumber, int maxspeed, bool hasname):Vehicle(wheel_name, max_speed, has_name){
		Car::set_wheel_number(wheelnumber);
		Car::set_max_speed(maxspeed);
		Car::set_has_name(hasname);
		Car::get_wheel_number(wheelnumber);
		Car::get_max_speed(maxspeed);
		Car::get_has_name(hasname);
	}


	Car::Car(int wheelname, int maxspeed, char *carname, bool hasname):Vehicle(wheel_name, max_speed, hasname)
	
	char Car::*get_car_name(){
		return Car::car_name;
	}

	void Car::set_car_name(char* carname){
		Car::car_name = carname;
	}
}
