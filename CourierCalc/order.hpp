/*
 * Author: Levi McLean
 * Created: March 11th, 2025
 * Version: 2.0
 * Description: Logic for initializing an order object
 */

#ifndef ORDER_HPP
#define ORDER_HPP

#include <iostream>

class Order {
private:
	double distance;
	double payment;

public:
	//Constructors
	//No arguments
	Order() {
		distance = 0.0;
		payment = 0.0;
	}

	//Two arguments (max)
	Order(double d, double p) {
		distance = d;
		payment = p;
	}

	//distance
	double getDistance() const {
		return distance;
	}
	void setDistance(double d) {
		distance = d;
	}

	//payment
	double getPayment() const {
		return payment;
	}
	void setPayment(double p) {
		payment = p;
	}
};

#endif // ORDER_HPP