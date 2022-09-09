#include<iostream>

// 	istream to read the data.
//	ostream to write the data.

using namespace std;

//	>> extraction operator
//	<< insertion operator

struct Student{
	
	string name;
	int age;
	float height;
	
	void get_details(){
		cout<<"Enter your name : ";
		cin>> name;
		
		cout<<"Enter your age: ";
		cin>> age;
		
		cout<<"Enter your height: ";
		cin>> height;
	}
	
	void show_details(){
		cout<<"Name: "<<name<<endl;
		cout<<"Age: "<<age<<endl;
		cout<<"Height: "<<height<<endl;
	}
};


istream& operator>>(istream& input_st, Student& st){
	cout<<"Name\tAge\tHeight"<<endl;
	input_st>>st.name>>st.age>>st.height;
}

ostream& operator<<(ostream& output_st, Student& st){
	cout<<"Name\t"<<st.name<<endl;
	cout<<"Age:\t"<<st.age<<endl;
	cout<<"Height:\t"<<st.height<<endl;	
	
}


int main(){
	
	Student st,st1;
	
	cin>>st;
	cout<<st;
	
	
}
