#include<iostream>
#include<sstream>

// istream ostream  --> istream -> cin, ostream-> cout
// ifstream ofstream
// istringstream ostringstream

// changes in structure

/*
	We don't need to mention the typedef any more on the structure to make an alias name.
	
	typedef struct Student{
}stud;

	alternative:
		
		struct Student{
	};
*/

using namespace std;

struct Student{
	
	string name;
	int age;
	float height;
	
	void get_details(){
		cout<<"Name:\t"; // "\n" ostream flush.
		cin>>name;
		
		cout<<"Age: \t";
		cin>>age;
		
		cout<<"Height:\t";
		cin>>height;
		
	}
	
	void show_details(){
		cout<<"Name:\t"<<name<<endl;
		cout<<"Age:\t"<<age<<endl;
		cout<<"Height:\t"<<height<<endl;
	}
};


// cin istream

istream& operator>>(istream& input, Student& st){
	cout<<"Name\tAge\tHeight"<<endl;
	input>>st.name>>st.age>>st.height;
}

ostream& operator<<(ostream& output, Student&  st){
	cout<<"Name:\t"<<st.name<<endl;
	cout<<"Age:\t"<<st.age<<endl;
	cout<<"Height:\t"<<st.height<<endl;
}

int main(){
	
//	<< insertion operator
// 	>> extraction operator

	Student st, st1;
	
//	st.get_details();
//	cout<<"---------------------------------\n\n"<<endl;	
//	st.show_details();
//	
//	cout<<"---------------------------------\n\n"<<endl;	
//	
//	st1.get_details();
//	cout<<"---------------------------------\n\n"<<endl;	
//	st1.show_details();
//	
//	cin>>st;


	cin>>st;
	cout<<st;
	cout<<"---------------------------------\n\n"<<endl;	
	
	cin>>st1;
	cout<<st1;
	
	return 0;
}
