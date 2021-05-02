#pragma once
#include "user.h"
#include "enums.h"
class parent : public user
{
private:
	std::string password;
	double account_total, income_pm, home_expenses_pm, auto_expenses_pm, food_expenses_pm, fun_expenses_pm;
public:
	parent(std::string first_name, std::string last_name, std::string password, double account_total, double income_pm, double home_expenses_pm, double auto_expenses_pm, double food_expenses_pm, double fun_expenses_pm) : user(first_name, last_name) {
		this->password = password;
		this->account_total = account_total;
		this->income_pm = income_pm;
		this->home_expenses_pm = home_expenses_pm;
		this->auto_expenses_pm = auto_expenses_pm;
		this->food_expenses_pm = food_expenses_pm;
		this->fun_expenses_pm = fun_expenses_pm;
	};

	void print() override {
		std::cout << first_name << ", " << last_name << ":" << std::endl;
		view_all_finances();
	};

	bool login(std::string inputed_password) {
		if (inputed_password == password) {return 1;}
		else { return 0; }
	}

	void view_all_finances() override {
		std::cout << "Account total:\t\t$" << account_total << std::endl
			<< "Monthly income:\t\t$" << income_pm << "/month" << std::endl
			<< "Monthly Home Expenses:\t$" << home_expenses_pm << "/month" << std::endl
			<< "Monthly Auto Expenses:\t$" << auto_expenses_pm << "/month" << std::endl
			<< "Monthly Food Expenses:\t$" << food_expenses_pm << "/month" << std::endl
			<< "Monthly Fun Expenses:\t$" << fun_expenses_pm << "/month" << std::endl
			<< "Monthly return:\t\t$" << income_pm - home_expenses_pm - auto_expenses_pm - food_expenses_pm - fun_expenses_pm << "/month" << std::endl
			<< std::endl;
	}
};