#include <iostream>
using namespace
using namespace std
class Vehicle {
	private:
		bool has_name;
		int wheel_number;
		int max_speed;
	public:

		int get_wheel_number();
		int get_max_speed();
		bool get_has_name();
		const char* get_class_name();
		void set_wheel_number(int wheelnumber);
		void set_max_speed(int maxspeed);
		void set_has_name(bool hasname);
	
}
