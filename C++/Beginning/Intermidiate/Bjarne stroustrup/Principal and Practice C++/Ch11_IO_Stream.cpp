// In this we will see how to make a program to read a file or read some data by using hte Streams.
#include<string>
#include<sstream>  // this liberary required to work with istringstream data.
#include<iostream>
#include<vector>   // to work with vectors.
#include <bits/stdc++.h>

using namespace std;

// we will use the string stream which is a part of the istream library
// Now we will use istringstream to read an string

/*Example 1: we will read some double values and convert them into real double values if 
             the instered values or note nureric values then we will throw an error*/

double str_to_double(const string s){
    // this function will return the double value if successed or throw an error.

    istringstream ifs {s};  // an istringstream object to read whole line or a string.
                            // ifs is initiated with string s
    double d; // a double type variable to hold the double value.

    ifs>>d; // Now our inserted string which is hold by the ifs input string stream object 
            // will pass the string if it converted value is double

    if(!ifs) cerr<<"double format error: "<<s; // if our input is not compatible to double value then we will get the error.
    return d; // if all things are good then we will get a double value.

}


/*Example 2: Read a whole line by using the getline function since we can't read the line by using the >> operator.
             In this we will get the a line and we will read this by using the getline and make a vector of words.*/

void get_words(){
    // Now first of all we need a string object which will hold the word.
    string Line;

    // now we will read the whole line from the user by using the istream object cin.
    getline(cin, Line); // this will read character by character and put them into the Line object.

    // Now we will make a string stream to create a buffer which will pass the words.
    stringstream ss {Line}; // Initializing the ss with the line now ss contains the whole line

    // Now we will make a vector of all the word (commands in some cases.)
    vector<string> words;

    for(string s; ss>>s;)  // ss stream will pass the word to s until it does not hit the eof.
        words.push_back(s); // we will put the each incoming word at the end of the vector.

    int i; 
    cout<<"Vector: <";
    for(i=0; i<words.size()-1; i++){
        cout<<words[i]<<",";
    }
    cout<<words[i]<<" ";
    cout<<">"<<endl;

//go there until you see a picture on the wall to your right remove the picture and open the door behind it. tak the bag from there

}

// Example 3: Punctuation Filter
/*
    In this we will make a class which will have some functionality to make this happen
*/

class Punct_Stream{

    private:
        istream& source;  // a reference variable to refer the istream object (character source)
        istringstream buffer; // we let buffer do our formatting
        string white; // characters considered 'whitespace'(basicaly it will contain all the whitespace character)
        bool sensitive; // is the stream case-sensitive

    public:

        /*
            1. Constructor take the istream to be used as a character source and gives it the local name source.
             -> By default Constructor will make case sensitive as true (true for lower case)
             -> 
        */
        Punct_Stream(istream& is): source{is}, sensitive{true}
        // we have initialized source and sensitive variables
        {}

        /*
            2. The basic idea is just  to read a line at a time from the istream, 
            convert "whitespace" character into spaces, and then use the istringstream to do formatiting.

            In addition to dealing the user-defined whitespace we need to make a add_white functionality 
            add custom whitespace characters.

            To deal with the cas-sensitive charcter or word we will have the case_sensitive functionality.          
        */

        void whitespace(const string& s){
            // this function takes a const string of white space which will contain 
            // the sequence of the whitespace character and it will passed to the white variable.
            white = s;
        }

        void add_white(char c){white += c;}  // later if we want to add more whitespace characters then we can add by using this.

        bool is_whitespace(char c){
            // Here we will check that character c is whitespace character or a normal character.
            for(char w : white) // since white is a sequence of whitespace charcter it will give each character.
                if(c==w) return true; 
            return false;  
        }

        void case_sensitive(bool b){sensitive = b;}

        bool is_case_sensitive(){return sensitive;}


        /*
            x. Input >> operator: we will define the inpur operator which will access the istream object and from there 
                we can read character by character or line by line.

            -> Our general strategy is to read a whole line from the istream into a string. 
                we then convert all of "our" whitespace characters to the space character (' ').

            -> After this we will put this converted line into the istringstream called buffer.
        */
        Punct_Stream& operator>>(string& s)
        {
             while (!(buffer>>s))  // get in while loop utile there is nothing in the buffer.
            // suppose that initially buffer is empty then we will enter in the loop.
            {
                // Now inside the loop first of all we will check the buffer status.
                if(buffer.bad() || !source.good() ) return *this;
                // if our buffer bad or there is something wrong with the source stream then 
                // we will return Punct_Stream object using this pointer.

                buffer.clear();  // before replenish (fill up aging ) the buffer we should get rid of the old content.

                // Now we need new line (string ) so we will go to the cin stream which is now refered as source.
                string line;
                getline(source, line);

                // after getting the line we have to do some filtering accoring to specified whitespace characters.
                for (char& ch : line){
                    // NOte: here we are referencing the each character by using the ch variable so we can modify the character.
                    if(is_whitespace(ch))
                        ch = ' ';
                    else if(!sensitive) // if case sensitive false
                        ch = tolower(ch);  
                }

                // Now after doing the filtering we will put the line into the buffer by using the str member function.
                buffer.str(line); 
            }
            // Here we will return the Punct_Stream object itself by using the this pointer.
            return *this;
            
        }

        operator bool(){
            // It returns true if the operation on the Punc_Stream is succeeded.
            // -> if our source is in good state and also buffer is in good state then we will return ture.
            return !(source.fail() || source.bad()) && buffer.good();
        }
};


int main(){

    // double val = str_to_double("Hello");
    // printf("\nInserted value: %.2lf", val);

    /* Testing the get word funciton.  */

    // get_words(); 

    /*=================================== TESTING THE Punct_Stream ================*/

    // Now first we will make a Punc_Stream object and pass a cin reference to it.
    Punct_Stream ps {cin};

    // Now need to mention the whitespace char
    ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~");
    // Now ps know that what character is whitespace.
    ps.case_sensitive(false);
    cout<<"Please Enter Line: ";
    vector<string> words;  // this vector will 

    for(string word; ps>>word;)
        words.push_back(word);  // get word form the buffer and then put it into the vector.

    sort(words.begin(), words.end());

    for(int i=0; i<words.size(); i++ ){
        if(i==0 || words[i] != words[i-1])
            cout<<words[i]<<'\n';
    } 
        
    // Since we have sorted this words vector.

    // LIne: There are only two kinds of languages: languages that people complain about, and languages taht people don't use.
}