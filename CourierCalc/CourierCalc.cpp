/*
 * Author: Levi McLean
 * Created: March 11th, 2025
 * Version: 2.0
 * Description: Main run logic for CourierCalc app
 */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <ctime>
#include "day.hpp"
#include "order.hpp"
#include "vehicle.hpp"

using namespace std;

//Array of weekdays
const char* weekdays[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

//Test making a vector of days
vector<Day> daysWorked;
vector<Vehicle> vehicleList;

//Int for option selection
int option;

//Double for hourly wage
double hourlyWage;

//View Days
void viewDays(vector<Day>& dw) {
	//Reset totalPay and totalHours
	double totalPay = 0.0;
	double totalHours = 0.0;

	//Iterate through vector of days
	for (int i = 0; i < dw.size(); i++) {
		time_t startTime = dw[i].getStartTime();
		tm* ltm = localtime(&startTime);

		cout << "Day #" << i << " (" << weekdays[ltm->tm_wday] << ")" << " start time: " << dw[i].getStartTime() << endl;
		cout << "Day #" << i << " (" << weekdays[ltm->tm_wday] << ")" << " end time: " << dw[i].getEndTime() << endl;
		cout << "Day #" << i << " (" << weekdays[ltm->tm_wday] << ")" << " total hours: " << dw[i].getTotalHours() << endl;
		cout << "Day #" << i << " (" << weekdays[ltm->tm_wday] << ")" << " num orders: " << dw[i].getNumOrders() << endl;

		//Iterate through vector of orders inside vector of days
		vector<Order> orders = dw[i].getOrders();
		for (int j = 0; j < orders.size(); j++) {
			cout << "Order #" << j << " distance: " << orders[j].getDistance() << " KMs, ";
			cout << "payment : $" << orders[j].getPayment() << endl;
		}

		cout << endl;
	}

	//Calculate total pay for week
	for (int i = 0; i < dw.size(); i++) {
		totalPay += dw[i].calcTotalPayment();
	}
	cout << "Total weekly payment: $" << totalPay << endl;

	//Calculate total hours for the week
	for (int i = 0; i < dw.size(); i++) {
		totalHours += dw[i].getTotalHours();
	}
	cout << "Total hours this week: " << totalHours << " hours." << endl;

	//Calculate hourly wage for the week
	hourlyWage = totalPay / totalHours;
	cout << "Hourly Wage: $" << hourlyWage << " / hour." << endl;
};

void addDay(vector<Day>& dw) {
	//Make new day object
	Day newDay;
	int st, et, no;

	//Get start time, end time and num orders
	cout << "New day start time: ";
	cin >> st;
	newDay.setStartTime(st);
	cout << "New day end time: ";
	cin >> et;
	newDay.setEndTime(et);
	cout << "New day num orders: ";
	cin >> no;
	newDay.setNumOrder(no);

	//Create each order for new day
	for (int i = 1; i < no + 1; i++) {
		Order newOrder;
		double d, p;
		cout << "Order #" << i << " distance: ";
		cin >> d;
		newOrder.setDistance(d);
		cout << "Order #" << i << " payment: ";
		cin >> p;
		newOrder.setPayment(p);
		newDay.addOrder(newOrder);
	}

	//Push new day to list of days
	dw.push_back(newDay);
}

void addVehicle(vector<Vehicle>& vl) {
	string make, model, commonName;
	int year, tankSize;
	double fuelEco;

	//Create test vehicle object
	Vehicle newVehicle;
	cout << "Enter vehicle make: ";
	cin >> make;
	newVehicle.setMake(make);
	cout << "Enter vehicle model: ";
	cin >> model;
	newVehicle.setModel(model);
	cout << "Enter vehicle year: ";
	cin >> year;
	newVehicle.setYear(year);
	cout << "Enter vehicle tank size (L): ";
	cin >> tankSize;
	newVehicle.setTankSize(tankSize);
	cout << "Enter fuel economy (L/100km): ";
	cin >> fuelEco;
	newVehicle.setFeulEco(fuelEco);
	cout << "Enter common name (eg. 'My Car'): ";
	cin.ignore();
	getline(cin, commonName);
	newVehicle.setCommonName(commonName);
	cout << endl;

	//Push new vehicle to vector
	vl.push_back(newVehicle);

	//Print info about vehicle
	cout << "New vehicle details: " << endl;
	cout << newVehicle;
}

void viewCars(vector<Vehicle>& vl) {
	for (int i = 0; i < vl.size(); i++) {
		cout << vl.at(i);
	}
}

void gasCost(vector<Vehicle>& vl) {
	int mainVehicle;
	double gasCost = 0.0;
	double totalDistance = 0.0;
	double costPerLitre = 1.543; //Temporary value for now, potential API use later or manual input
	if (vl.empty()) {
		cout << "No vehicle detected in list, please add one now" << endl;
		addVehicle(vl);
	}
	else {
		for (int i = 0; i < vl.size(); i++) {
			cout << "Vehicle #" << i << endl;
			cout << vl.at(i) << endl;
		}

		cout << "Please select which vehicle was used this week: ";
		cin >> mainVehicle;
		cout << endl;

		if (mainVehicle < 0 || mainVehicle >= vl.size()) {
			cout << "Invalid vehicle selection." << endl;
		}
		Vehicle selectedVehicle = vl.at(mainVehicle);
		cout << "Selected Vechicle: " << endl;
		cout << selectedVehicle;

		for (const Day& day : daysWorked) {
			for (const Order& order : day.getOrders()) {
				totalDistance += order.getDistance();
			}
		}

		double fuelConsumed = totalDistance / 100.0 * selectedVehicle.getFeulEco();
		gasCost = fuelConsumed * costPerLitre;
		cout << "Total distance traveled: " << totalDistance << " KMs." << endl;
		cout << "Weekly gas cost (AT TODAYS GAS PRICES ONLY): $" << gasCost << endl;
	}
}

int main() {
	system("cls");
	cout << "Welcome to CourierCalc!" << endl;

	//Get the current date
	time_t now = time(0);
	tm* ltm = localtime(&now);
	
	//Print Current date
	cout << "Date: " << 1900 + ltm->tm_year << "/" << 1 + ltm->tm_mon << "/" << ltm->tm_mday << endl;

	cout << "Created by Levi McLean" << endl;

	while (true) {
		cout << endl;

		//Main Menu
		cout << "1. Add day" << endl;
		cout << "2. View days" << endl;
		cout << "3. Add car" << endl;
		cout << "4. View cars" << endl;
		cout << "5. Calculate weekly gas cost" << endl;
		cout << "0. Save and Exit" << endl;
		cout << "Please select an option: ";
		cin >> option;

		switch (option) {
		case 1:
			system("cls");
			addDay(daysWorked);
			break;
		case 2:
			system("cls");
			viewDays(daysWorked);
			break;
		case 3:
			system("cls");
			addVehicle(vehicleList);
			break;
		case 4:
			system("cls");
			viewCars(vehicleList);
		case 5:
			system("cls");
			gasCost(vehicleList);
			break;
		case 0:
			cout << "Saving (not really) and Exiting..." << endl;
			return 0;
		default:
			cout << "Invalid Selection... Please try again." << endl;
			break;
		}
	}
	return 0;
}