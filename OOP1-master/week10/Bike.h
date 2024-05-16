#include "Vechile.h"

Class Bike {

	private:
		char *bike_name;
		int bike_number;

	public:
		bike();
		bike(int wheelnumber, int maxspeed, char*bikename);
		bike(int wheelnumber, int maxspeed, char*bikename,int bikenumber);
		bike(int wheelnumber, int maxspeed, char*bikename, int bikenumber, bool hasname);
		
		int get_bike_number();
		char*get bike_name();
		const char*get_class_name();
		void set_bike_name(char *bikename);
		void set_bike_number(int bikenumber);
}
