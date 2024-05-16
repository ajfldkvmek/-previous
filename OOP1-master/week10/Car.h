#include "Vechile.h"

Class Car : public Vehicle {

	private:
		char *car_name;
	public:
		Car();
		Car(int wheelname, int maxspeed);
		Car(int wheelname, int maxspeed, int char* carname);
		Car(int wheelname, int maxspeed, int char* carname, bool hasnaem);
		char*get_car_name();
		const char* get_class_name();
		void set_car_name(char *carname);
}

