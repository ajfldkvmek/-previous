#include "Vechile.cpp"
#include "Bike.cpp"
#include "Car.cpp"

int main(){
	
	Car car;
	Bike bike;
	Vechile vechile;

	vehicle::Vehicle(10, 30, false);
	car::Car(4, 10, "mycar", true);
	bike::Bike(2, 100, "mybibke", 123123, true);
}
