#include <iostream>
using namespace std;

/*
	Program: String Comparasion: String compare()

	Suppose that we have str1 and str2 and we want to compare these two strings
	then we can use str1.compare(str2) to compare the values and will return a
	an integer:

	retured value:
		if 0: both string are equal.
		if not 0: it means both strings are not equal.
		if value < 0: it means, either the value of the first character is lower in
			the compared string or all the compared characters match but the compared
			string is shorter.
		if value > 0: it means, either the value of the first character is greater in
			the compared string or all the compared characters match but the compared
			string is longer.
*/

int main()
{

	string str1, str2;

	str1 = "hello";
	str2 = "Hello";

	int value = str1.compare(str2);

	if (value == 0)
	{
		cout << "Strings are equals";
	}
	else if (value < 0)
	{
		cout << "str1 is less than the str2";
	}
	else if (value > 0)
	{
		cout << "str1 is greater than the str2";
	}

	return 0;
}
