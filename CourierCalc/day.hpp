/*
 * Author: Levi McLean
 * Created: March 11th, 2025
 * Version: 2.0
 * Description: Logic for initializing a day object and adding orders to days
 */

#include <iostream>
#include <vector>
#include "order.hpp"

using namespace std;

class Day {
private:
	int startTime;
	int endTime;
	int numOrders;

	double totalHours;
	double totalPayment;
	double hourlyWage;

	vector<Order> orders;

public:

	//Constructors
	//No arguments
	Day() {
		startTime = 0;
		endTime = 0;
		totalHours = endTime - startTime;
		numOrders = 0;
		totalPayment = 0.0;
		hourlyWage = 0.0;
	};

	//3 Arguments (max)
	Day(int st, int et, int no) {
		startTime = st;
		endTime = et;
		totalHours = endTime - startTime;
		numOrders = no;
		totalPayment = 0.0;
		hourlyWage = 0.0;
	}

	// Start Time
	int getStartTime() const {
		return startTime;
	}
	void setStartTime(int st) {
		startTime = st;
	}

	// End Time
	int getEndTime() const {
		return endTime;
	}
	void setEndTime(int et) {
		endTime = et;
	}

	// Total Hours
	double getTotalHours() const {
		return endTime - startTime;
	}

	// Num Orders
	int getNumOrders() const {
		return numOrders;
	}
	void setNumOrder(int no) {
		numOrders = no;
	}

	// Add order
	void addOrder(const Order& order) {
		orders.push_back(order);
	}

	//Get Orders
	vector<Order> getOrders() const {
		return orders;
	}

	//Calculate total payment for the day
	double calcTotalPayment() {
		totalPayment = 0.0;
		for (int i = 0; i < numOrders; i++) {
			totalPayment += orders[i].getPayment();
		}
		return totalPayment;
	}

	//Calculate hourly wage for the day
	double calcWage() {
		if (totalHours > 0) {
			hourlyWage = calcTotalPayment() / totalHours;
		}
		else {
			hourlyWage = 0.0;
		}
		return hourlyWage;
	}
};