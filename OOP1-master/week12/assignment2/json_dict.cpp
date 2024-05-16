#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"

void json_dict::put(json_object* key, json_object* val){
	v.push_back({key, val});
}

int json_dict::find(json_object* key){
	std::string str = key->to_string();
	
	for(int i = 0; i < v.size(); i++) {
		if(v[i].first->to_string() == str) return i;
		else return -1;
	}
}

json_dict::json_dict(){}

json_object* json_dict::parse(const char* str, int length){
	
	int num = 0;
	int& index = json_object::_index;
	json_dict *temp_dict = new json_dict();
	json_object *key, *val;
	bool boo = true;
	
	while(index < length){
		
		if(str[index] == '\'') {
			index++;
			if(boo) key = String::parse(str, length, '\'');
			else val = String::parse(str, length, '\'');
		}
		
		else if(str[index] == ':') boo = false;
		
		else if(str[index] == ',') {
			num = temp_dict->find(key);
			if(num != -1) temp_dict->v[num].second = val;
			else temp_dict->put(key, val);
			boo = true;
		}
		
		else if(str[index] == '['){
			index++;
			val = json_list::parse(str, length);
		}
		
		else if(str[index] == '{'){
			index++;
			val = json_dict::parse(str, length);
		}
		
		else if(str[index] == '}'){
			num = temp_dict->find(key);
			if(num != -1) temp_dict->v[num].second = val;
			else temp_dict->put(key, val);
			return temp_dict;
		}
		
		else {
			if(boo) key = Integer::parse(str, length);
			else val = Integer::parse(str, length);
			index--;
		}
		index++;
	}
	
	return temp_dict;
}

json_object* json_dict::operator[](json_object* key) const {
	
	if(key->type() == json_object::INT) return operator[](atoi(key->to_string().c_str()));
	else if(key->type() == json_object::STRING) return operator[](key->to_string());
}

json_object* json_dict::operator[](const std::string& key) const{
	std::string _key = '\'' + key + '\'';
	for(std::pair<json_object*, json_object*> _temp: v){
		if(_temp.first->to_string() == _key) return _temp.second;
	}
}

json_object* json_dict::operator[](int key)const {
	for(std::pair<json_object*, json_object*> _temp : v) {
		int _key = atoi(_temp.first->to_string().c_str());
		if(_key == key) return _temp.second;
	}
}

json_object::_type json_dict::type(){
	return DICT;
}

std::string json_dict::to_string(){
	
	if(v.size() == 0) return "{}";
	std::string string = "{";
	
	for(int i = 0; i < v.size(); i++) {
		string += v[i].first->to_string() + ": " + v[i].second->to_string();
		string += ", ";
	}
	
	string += v[v.size() -1].first->to_string() + ": "+ v[v.size() - 1].second->to_string() + '}';
	return string;
}
