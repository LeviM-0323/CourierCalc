/*
 * Author: Levi McLean
 * Created: March 12th, 2025
 * Version: 2.0
 * Description: Logic for initializing a vehicle object and calculating various statistics
 */

#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include <String>

using namespace std;

class Vehicle {
private:
	int tankSize, year;
	double feulEco; // In L/100km
	string make, model, commonName;

public:
	//Constructors
	//No arguments
	Vehicle() {
		tankSize = 0;
		year = 0;
		feulEco = 0.0;
		make = "N/A";
		model = "N/A";
		commonName = "Unitialized";
	}

	//6 arguments (max)
	Vehicle(int ts, int y, double fe, string ma, string mo, string cn) {
		tankSize = ts;
		year = y;
		feulEco = fe;
		make = ma;
		model = mo;
		commonName = cn;
	}

	//Tank Size
	int getTankSize() const {
		return tankSize;
	}
	void setTankSize(int ts) {
		tankSize = ts;
	}

	//Year
	int getYear() const {
		return year;
	}
	void setYear(int y) {
		year = y;
	}

	//Feul economy
	double getFeulEco() const {
		return feulEco;
	}
	void setFeulEco(double fe) {
		feulEco = fe;
	}

	//Make
	string getMake() const {
		return make;
	}
	void setMake(string m) {
		make = m;
	}

	//Model
	string getModel() const {
		return model;
	}
	void setModel(string m) {
		model = m;
	}

	//Common Name
	string getCommonName() const {
		return commonName;
	}
	void setCommonName(string cn) {
		commonName = cn;
	}

	friend ostream& operator<<(ostream& os, const Vehicle& v) {
		os << "Common name: " << v.commonName << endl;
		os << v.year << " " << v.make << " " << v.model << endl;
		os << "Tank Size: " << v.tankSize << "L" << endl;
		os << "Fuel Economy: " << v.feulEco << "L/100km" << endl;
		return os;
	}
};
#endif // VEHICLE_HPP