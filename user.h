#pragma once
#include <string>
#include <iostream>
class user
{
protected:
	std::string name;
public:
	user(std::string name) {
		this->name = name;
	};
	void print_name(){
		std::cout << name << std::endl;
	};

};
