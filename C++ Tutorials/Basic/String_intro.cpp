#include<iostream>

using namespace std;

// namespace for io operation flags ios::<flag>

void Length();
void Compare();
bool is_equal();
void SubStr();

int main(){
	
// 1. getting the length of the string.

	Length();
	
//	2. comparing two strings

	Compare();
	
//	3. is str1 equal to str2 

	cout<<"\nis equal: "<<is_equal()<<endl;
	
//	4. substring of a stirng.
	SubStr();

	return 0;
}


void Length(){
	string str = "Hello this is cpp class.!";
	
	int len = str.length();  // this keyword
	cout<<"String lenght: "<<len<<endl;
}

void Compare(){
	
	string str1, str2;
	
	str1 ="Hello";
	str2 = "hello";

	int r = str1.compare(str2);
	
	if(r == 0){
		cout<<"str1 is equal to str2";
	}
	else if(r < 0){
		cout<<"str1 is less than str2";
	}
	else if(r > 0){
		cout<<"str1 is greater than str2";
	}
}

bool is_equal(){
	string str1, str2;
	
	str1 ="Hello";
	str2 = "Hello";

	int r = str1.compare(str2);
	if (r==0)
		return true;
	
	return false;
}

void SubStr(){
	
	string str1 = "hello this is cpp-special clas!";
	
	int index = str1.find("cpp");
	
	cout<<"index of the 'cpp' : "<<index<<endl;
	string sub_str = str1.substr(index, 11);
	
	cout<<"substring in b/w 14-25:\t"<<sub_str<<endl;
	
	
	
}
