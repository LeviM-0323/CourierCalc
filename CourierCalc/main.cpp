/*
* main.cpp
* This file contains the main run logic for CourierCalc.
* Created Febuary 22, 2025
* Author: Levi McLean
*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <String>
#include <vector>
#include "day.hpp"
#include "order.hpp"

using namespace std;
vector<Day> daysWorked;

void printMenu() {
	cout << "1. Add day to days worked" << endl;
	cout << "2. View days worked" << endl;
	cout << "3. Calculate Average hourly wage" << endl;
	cout << "4. Calculate gas costs" << endl;
	cout << "5. View Statistics" << endl;
	cout << "6. Clear Screen" << endl;
	cout << "0. Exit" << endl;
	cout << "Please select an option: ";
}

void addDay() {
	Day newDay;
	int numOrders;
	int startTime;
	int endTime;

	cout << "Please enter start time in 24 hour notation: ";
	cin >> startTime;
	newDay.setStartTime(startTime);

	cout << "Please enter end time in 24 hour notation: ";
	cin >> endTime;
	newDay.setEndTime(endTime);

	cout << "Please enter the number of orders recieved: ";
	cin >> numOrders;
	newDay.setNumOrders(numOrders);
	cout << endl;

	for (int i = 1; i <= numOrders; i++) {
		Order newOrder;
		double payment;
		double distance;
		cout << "Enter payment for order number " << i << ": ";
		cin >> payment;
		newOrder.setPayment(payment);
		cout << "Enter distance for order number " << i << ": ";
		cin >> distance;
		newOrder.setDistance(distance);
		newDay.addOrder(newOrder);
		cout << endl;
	}
	daysWorked.push_back(newDay);
	system("cls");
}

void viewDays() {
	system("cls");
	for (int i = 0; i < daysWorked.size(); i++) {
		cout << "Date: " << daysWorked[i].getDay() << "/" << daysWorked[i].getMonth() << "/" << daysWorked[i].getYear() << endl;
		cout << "Start Time (24hr): " << daysWorked[i].getStartTime() << endl;
		cout << "End Time (24hr): " << daysWorked[i].getEndTime() << endl;
		cout << "Total Duration: " << daysWorked[i].getTotalHours() << " hours." << endl;
		cout << "Total Kilomters: " << daysWorked[i].getTotalKms() << " KMs." <<  endl;
		cout << "Total Earnings: $" << daysWorked[i].getTotalEarnings() << "." << endl;
		cout << endl;
	}
}

int main() {
	time_t timestamp = time(nullptr);
	int option;
	tm now;
	localtime_s(&now, &timestamp);
	cout << "Welcome to CourierCalc!" << endl;
	cout << "This is a tool to help you calculate various statistics for your SkipTheDishes Couier work" << endl;
	cout << "Todays date (DD/MM/YYYY) is: " << now.tm_mday << "/" << (now.tm_mon + 1) << "/" << (now.tm_year + 1900) << endl << endl ;
	printMenu();
	cin >> option;
	cout << endl;
	while (option != 0) {
		switch (option) {
			case 0:
				cout << "Saving and Exiting..." << endl;
				break;
			case 1:
				addDay();
				break;
			case 2:
				viewDays();
				break;
			case 3:
				//calcAvgWage();
				break;
			case 4:
				//calcGasCosts();
				break;
			case 5:
				//viewStats()
				break;
			case 6:
				system("cls");
				break;
			default:
				cout << "Invalid option, please try again" << endl << endl;
				break;
			}
		printMenu();
		cin >> option;
	}
	return 0;
}