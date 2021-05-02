#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include "parent.h"
#include "user.h"
#include <fstream>
#include <sstream>
#include "enums.h"

std::map<std::string, user*> users = {};
std::string username;

void get_users(std::string);
void print_all();
void login();
void welcome();
void enter_account();

int main() {
	get_users("Users_info.csv");	
	welcome();
	

	print_all();
	return 0;
}

void print_all() {
	std::cout << "All users in the database: " << std::endl << std::endl;
	std::map<std::string, user*>::iterator it;

	for (it = users.begin(); it != users.end(); it++) {
		std::string key = it->first;
		user* value = it->second;
		value->print();
		delete value;
	}
	//std::users["akaiser000"]->print();
}
void get_users(std::string path) {
	std::cout << "LOADING USERS ..." << std::endl;
	std::ifstream stream;
	stream.open(path);

	//Skip the first line
	std::string line;
	std::getline(stream, line);

	//Read every line in the file
	while (std::getline(stream, line)) {
		std::stringstream ss(line);
		std::string substr;

		std::getline(ss, substr, ',');
		std::string uname = substr;

		std::getline(ss, substr, ',');
		std::string fname = substr;

		std::getline(ss, substr, ',');
		std::string lname = substr;

		std::getline(ss, substr, ',');
		std::string pword = substr;

		//Read the Year
		std::getline(ss, substr, ',');
		double atot = std::stod(substr);

		std::getline(ss, substr, ',');
		double ipm = std::stod(substr);

		std::getline(ss, substr, ',');
		double hepm = std::stod(substr);

		std::getline(ss, substr, ',');
		double aepm = std::stod(substr);

		std::getline(ss, substr, ',');
		double fepm = std::stod(substr);

		std::getline(ss, substr, ',');
		double fun_epm = std::stod(substr);

		users.insert({ uname, new parent(fname,lname,pword,atot, ipm,hepm,aepm,fepm,fun_epm) });
	}
	stream.close();
	std::cout << "ALL USERS LOADED!" << std::endl << std::endl;
}
void login() {
	std::cout << "To log in please enter your USERNAME: ";
	std::string password;
	std::getline(std::cin, username);
	if (users.count(username)) {
		std::cout << "Please enter your password: " << std::endl;
		std::getline(std::cin, password);
		if (users[username]->login(password)) {
			std::cout << "Welcome " << users[username]->get_full_name() << std::endl;
			enter_account();
		}
		else {
			std::cout << "INCORRECT PASSWORD" << std::endl << std::endl << std::endl;
			welcome();
		}
	}
	else {
		std::cout << "NO SUCH USER FOUND" << std::endl << std::endl << std::endl;
		welcome();
	}
}
void welcome() {
	std::cout << "Welcome to our college idiot financial program." << std::endl;
	login();
}

void enter_account() {
	std::cout << "What would you like to do? Please enter one onf the following options." << std::endl
		<< "1. View all finances" << std::endl
		<< "2. Edit Expenses" << std::endl
		<< "3. Edit Income" << std::endl
		<< "4. Log Out" << std::endl;
	std::string choice_str;
	std::getline(std::cin, choice_str);
	int choice = std::stoi(choice_str);
	if (choice == 1) {
		users[username]->view_all_finances();
	}
	else if (choice == 2) {

	}
	else if (choice == 3) {

	}
	else if (choice == 4) {

	}
	else {
		std::exit(13);
	}
}