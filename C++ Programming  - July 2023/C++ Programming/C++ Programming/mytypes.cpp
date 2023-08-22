#include<iostream>
#include<string>
#include "mytypes.h"

using namespace std;

string PhoneNumber::toString() {
	return this->code + "-" + this->number;
}