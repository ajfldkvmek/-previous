#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"

int json_object::_index = 0;

json_object* json_object::parse(const std::string& str) {
	return parse(str.c_str(), str.length());
}

json_object* json_object::parse(const char* str, int length){
	json_object* temp = NULL;
	
	while(_index < length){
		
		if(str[_index] == '{'){
			_index++;
			temp = json_dict::parse(str, length);
		}
		
		else if(str[_index] == '[') {
			_index++;
			temp = json_list::parse(str, length);
		}
		
		else if(str[_index] == '\''){
			_index++;
			temp = String::parse(str, length, '\'');
		}
		
		else {
			if(str[_index] >= '0' && str[_index] <= '9') temp = Integer::parse(str, length);
		}
		
		_index++;
	}
	
	_index = 0;
	return temp;
}
