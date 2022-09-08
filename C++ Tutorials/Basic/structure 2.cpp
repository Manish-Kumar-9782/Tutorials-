#include <iostream>
#include <string>

using namespace std;

// In this section we don't have to use the typedef to make an alias name
// to short our structure data type.

// we can directly make variable by using the Student identifier.


int add(int a, int b){
	
		cout<<"adding integers function...\n\n";
    	return a+b;
	}
	
string add(string a, string b){
		cout<<"adding strings function...\n\n";
		return a+b;
	}



int main()
{

//    Student st, st2;
    

//    st.get_detail();
//	st2.get_detail();
//    cout << "Your details:" << endl;
//
//    st.show_details();
//    st2.show_details();
//    
    
    

	cout<<"adding integers:\t"<< add(10,20) << endl;
	cout<<"adding strings:\t"<< add("hello ", "Welcome")<<endl;
	

    return 0;
}
