#pragma once
#include<iostream>

using namespace std;

struct Time {
	int hour;
	int min;
	int sec;
	string format;
};

struct PhoneNumber {
	string number;
	string code;

	string toString();
};

struct CallLog {
	string caller;
	string reciever;
	Time callTime;
};

struct Message {
	string sender;
	string receiver;
	string message;
	Time messageTime;
};