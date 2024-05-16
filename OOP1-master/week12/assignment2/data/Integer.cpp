#include "Integer.h"


Integer::Integer(int value){
	_val = value;
}

int Integer::val(){
	return _val;
}

void Integer::set_val(const int& value){
	_val = value;
}

json_object* Integer::parse(const char* st, int length){
	
	int  count=0;
	while(st[_index] >= '0' && st[_index] <= '9') count++;
	std::string str = std::string(st);
	return new Integer(std::stoi(str.substr(_index, count)));	
}

json_object::_type Integer::type(){
	return INT;
}

std::string Integer::to_string(){
	return std::to_string(_val);
}
