#pragma once
#include <iostream>
#include <string>
#include "enums.h"
class user
{
protected:
	std::string first_name, last_name;
public:
	user(std::string first_name, std::string last_name) {
		this->first_name = first_name;
		this->last_name = last_name;
	}
	void virtual print() = 0;
	bool virtual login(std::string inputed_password) = 0;
	std::string get_full_name() {
		return last_name + ", " + first_name;
	}
	std::string get_first_name() {
		return first_name;
	}
	std::string get_last_name() {
		return last_name;
	}

	void virtual view_all_finances() = 0;
};

