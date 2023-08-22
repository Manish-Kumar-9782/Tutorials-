#include<iostream>
#include<string>
#include<vector>
#include "mytypes.h";

using namespace std;



class Mobile {

private:
	vector<PhoneNumber> phoneNumbers; 
	vector<CallLog> callHistory;
	vector<Message> messages;
	vector<PhoneNumber> blockedNumber;

public:
	void sendMessage(PhoneNumber to) {
		cout << "sending message to " << to.toString()<<endl ;
	}

	vector<PhoneNumber> getNumbers() {
		return phoneNumbers;
	}

	void addPhoneNumber(PhoneNumber number) {
		this->phoneNumbers.push_back(number);
	}

	virtual void call()=0;  // this method is called pure virtual method and also abstract method.

	virtual void addContact() =0;

	//virtual void blockNumber() = 0;
};


class SamsungMobile : public Mobile {
	
private:

	void displayPhoneNumbers() {
		vector<PhoneNumber> numbers = this->getNumbers();
		int count = 0;
		for (PhoneNumber n : numbers) {
			cout << count << ": " << n.toString() << endl;
		}
	}

public:
	void call() {
		cout << "Select Phone Number: "<<endl;
		cout << "----------------------------" << endl;
		this->displayPhoneNumbers();
	}

	void addContact() {
		string code;
		string number;
		cout << "Enter Phone Number: ";
		cin >> code >> number;

		PhoneNumber _number = { number, code };
		this->addPhoneNumber(_number);
	}
};

int main() {


	// Mobile mobile;

	SamsungMobile galaxy;

	galaxy.addContact();

	galaxy.call();

	//mobile.sendMessage(number);

	return 0;
}



