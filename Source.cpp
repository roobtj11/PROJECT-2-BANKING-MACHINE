#include <iostream>
#include <vector>
#include <string>
#include "enums.h"
#include "user.h"
#include "parent.h"
#include "child.h"

int current_user;
std::vector <std::string> usernames{ "bob65","fred12", "george18" };
std::vector <std::string> passwords{ "bob65","fred12", "george18"};
std::vector <user*> users = { 
	new parent("bob"),
	new parent("fred"),
	new child("george")
};

void expenses() {
	
}

void income() {

}

void menu(int a) {
	if(a = 1){
		expenses();
	} else if (a = 2) {
		income();
	} else if (a = 3) {
		current_user = 321654987;
		welcome();
	} else if (a > 3) {
		std::cout << "That is not a valid option, please enter a valid choice";
		enter_account();
	}
}

void enter_account() {
	std::cout << "What would you like to do? Please enter one onf the following options." << std::endl;
	std::cout << "1. Edit Expenses" << std::endl;
	std::cout << "2. Edit Income" << std::endl;
	std::cout << "3. Log Out" << std::endl;
	int choice;
	std::cin >> choice;
	menu(choice);

}

void login() {
	std::cout << "To log in please enter your USER NAME: ";
	std::string username, password;
	std::getline(std::cin, username);
	std::cout << "Please enter your password: " << std::endl;
	std::getline(std::cin, password);
	bool proceed = 0;
	for (int i = 0; i < users.size(); i++) {
		if (username == usernames[i]) {
			if (password == passwords[i]) {
				users[i]->print_name();
				current_user = i;
				enter_account();
				proceed = 1;
			}
		}
	}
	if (proceed == 0) {
		std::cout << "Enter a valid Username and Password!" << std::endl;
		std::exit(106);
	}
}

void welcome() {
	std::cout << "Welcome to our college idiot financial program." << std::endl;
	login();
}

int main() {
	welcome();

	return 0;
}