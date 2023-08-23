#include<iostream>
#include<string>

using namespace std;

class Automobile {

public:
	void start() {
		cout << "automobile starting...."<<endl;
	}

	virtual void smartStart() {
		cout << "auto mode... automobile starting...." << endl;
	}
};

class Car:public Automobile {
public:
	void start() {
		cout << "Car starting with bhrram bhrram...."<<endl;
	}

	virtual void smartStart() {
		cout << "auto mode... Car starting with bhrram bhrram...." << endl;
	}
};

class AudiCar :public Car{
public:
	void start() {
		cout << "Audi car starting ghrrrr ghrrrrr...."<<endl;
	}

	virtual void smartStart() {
		cout << "auto mode... Audi car starting ghrrrr ghrrrrr...." << endl;
	}
};


int main() {


	Automobile *mobile = new Automobile();
	Car *car = new Car();
	AudiCar *audi = new AudiCar();

	mobile->start();
	car->start();
	audi->start();

	cout << "=============================" << endl;
	Automobile* mobile1 = new Automobile();
	Automobile* car1 = new Car();
	Automobile* audi1 = new AudiCar();

	mobile1->start();
	car1->start();
	audi1->start();

	cout << "=============================" << endl;

	mobile1->smartStart();
	car1->smartStart();
	audi1->smartStart();

	return 0;
}