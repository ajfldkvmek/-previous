#include "String.h"

String::String(const std::string& str){
	_val = str;
}

std::string String::val(){
	return _val;
}

void String::set_val(const std::string& str){
	this->_val = str;
}

json_object* String::parse(const char* st, int length, char base){
	int& a = json_object::_index;
	std::string temp = "";
	
	for(;a < length;a++) {
		if(st[a] == '\'') return new String(temp);
		else temp+=st[a];		
	}
	
	return NULL;
}

json_object::_type String::type(){
	return STRING;
}

std::string String::to_string(){
	return '\'' + this->_val + '\'';
}
