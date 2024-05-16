#include "Vechile.h"

Vehicle::Vehicle(){
	Veichile::has_name = false;
}

Vehicle::Vehicle(int wheelnumber, int maxspeed){
	Veichile::set_wheel_number(wheelnumber);
	Veichile::set_max_speed(maxspeed);
	Veichile::get_wheel_number(wheelnumber);
	Veichile::get_max_speed(maxspeed);
}

Vehicle::Vehicle(int wheelnumber, int maxspeed, bool hasname){
	Veichile::set_wheel_number(wheelnumber);
	Veichile::set_max_speed(maxspeed);
	Veichile::set_has_name(hasname);

	Veichile::get_wheel_number();
	Veichile::get_max_speed();
	Viehcile::get_has_name();
}

int Vehicle::get_max_speed(){
	return Veichile::max_speed;
}

void Vehicle::set_max_speed(int maxspeed){
	Veichle::max_speed = maxspeed;
}

int Vehicle::get_wheel_number(){
	return Veichile::wheel_number;
}

void Vehicle::set_wheel_number(int wheelnumber){
	Veichile::max_speed = wheelnumber;
}

bool Vehicle::get_has_name(){
	return Veichile::has_name;
}

void Vehicle::set_has_name(bool hasname){
	Vehicle::has_name = hasname;	
}

