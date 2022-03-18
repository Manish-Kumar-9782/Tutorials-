#include<iostream>
using namespace std;

void error(const string& s){
	throw(s);
}

class Token{
	public:
		char kind;
		double value;
		
		Token(char ch){
			kind = ch;  // if we only pass the input char kind then we will only set kind
		} 
		
		Token(char ch, double val){
			// if our input is a numeric value then we will return the kind and value
			kind = ch; 
			value = val;
		}
};

Token get_token(){
	
	// Now we will return the token after getting the character.
	
	char ch;
	switch(ch){
		
		case '(': case ')': case '+': case '-': case '/': case '*':
			return Token(ch);
		
		case '.':
		case '0': case '1': case '2': case '3': case '4': case '5': 
		case '6': case '7': case '8': case '9': case '0': 
		
			 cin.putback(ch); // Now we will put back the istream character and we will put the whole value into double.
			 double val;
			 cin>>val;
			 // Now we will return the val and its kind to as token.
			 return Token('num', val);
		default:
			return("Bad token");
			 
	}
	return -1; // if something unexpected happens.
}

int main(){
	
	while(cin){
		
		Token t = get_token();
		cout<<"\nt.kind: "<<t.kind<<endl;
		
		
		
	}
	
	return 0;
}
