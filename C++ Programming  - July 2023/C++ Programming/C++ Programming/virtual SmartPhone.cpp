#include<iostream>
#include<string>

using namespace std;

class SmartPhone {

public:

	virtual void call() {
		cout << "Phone calling..." << endl;
	}
};


class SamsungPhone : public SmartPhone {

public:
	virtual void call() {
		cout << "Samsung Phone calling..."<<endl;
	}

};

class OppoPhone : public SmartPhone {
public:
	virtual void call() {
		cout << "Oppo Phone calling..." << endl;
	}
};

class Iphone : public SmartPhone {
public:
	virtual void call() {
		cout << "IPhone Phone calling..."<<endl;
	}
};

int main() {

	SmartPhone* phone = new SmartPhone();

	SmartPhone* samsung = new SamsungPhone();

	SmartPhone* oppo = new OppoPhone();

	SmartPhone* iphone = new Iphone();


	phone->call();
	samsung->call();
	oppo->call();
	iphone->call();



	return 0;
}