#include <iostream>
#include <vector>
#include <string>
#include "enums.h"
#include "user.h"
std::vector <std::string> usernames{ "bob65","fred12", "george18" };
std::vector <std::string> password{ "bob65","fred12", "george18"};
std::vector <user*> users{ new user("bob") };


void menu(int a) {
	switch (a) {
	case a = 1:
		
	case a = 2:

	case a = 3:
	
	}
}

void enter_account() {
	std::cout << "What would you like to do? Please enter one onf the following options." << std::endl;
	std::cout << "1. Edit Expenses" << std::endl;
	std::cout << "2. Edit Income" << std::endl;
	std::cout << "3. Log Out" << std::endl;
	int a;
	std::cin >> a;
	menu(a);

}

void login() {
	std::cout << "To log in please enter your USER NAME: ";
	std::string username, password;
	std::getline(std::cin, username);
	std::cout << "Please enter your password: " << std::endl;
	std::getline(std::cin, password);
	enter_account();
}

void welcome() {
	std::cout << "Welcome to our college idiot financial program." << std::endl;
	login();
}

int main() {
	welcome();



	return 0;
}