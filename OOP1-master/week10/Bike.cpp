#include "Bike.h"

Bike::Bike():Vehicle(){

}

Bike::Bike(int wheelnumber, int maxspeed):Vehicle(wheel_number, max_speed){
	cout << "wheel_number: " << wheelnumber << endl;
	cout << "max_speed: " << max_speed << endl;
}


Bike::Bike(int wheelnumber, int maxspeed, char*bikename):Vehicle(wheel_number, max_speed){
	
	Bike::set_bike_name(bikename);
	//Bike::set_bike_number(bikenumber);
	
	cout << "wheel_number: " << wheel_number << endl;
	cout << "max_speed: " << max_speed << endl;
	cout << "bike_name: " << get_bike_name() << endl;
}

Bike::Bike(int wheelnumber, int maxspeed, char*bikename, int bikenumber):Vehicle(wheel_number, max_speed){
	Bike::set_bike_name(bikename);
	Bike::set_bike_number(bikenumber);

	
}

Bike::Bike(int wheelnumber, int maxspeed, char*bikename, int bikenumber, bool hasname):Vehicle(wheel_number, max_speed, has_name){
	Bike::set_bike_name(bikename);
	Bike::set_bike_number(bikenumber);
}

void Bike::set_bike_name(char *bikename){
	Bike::*bike_name = *bikename;
}

void Bike::bike_number(int bikenumber){
	Bike::bike_number = bikenumber;
}

const char* Bike::get_bike_name(){
	return *Bike::bike_name;
}
int Bike::get_number(){
	return Bike::bike_number;
}

