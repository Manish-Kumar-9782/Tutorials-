// Now in this section we will make a to read and write temperature data to or from the file.
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>

using namespace std;

/*
    Now In this program we make a structured data in which we have data like this

    { year 1990 }
    {year 1991 { month jun }}
    { year 1992 { month jan ( 1 0 61.5) } {month feb (1 1 64) (2 2 65.2) } }
    {year 2000
    { month feb (1 1 68 ) (2 3 66.66 ) ( 1 0 67.2)}
    {month dec (15 15 –9.2 ) (15 14 –8.8) (14 0 –2) }
    }


    -> Now to make a sturctured data formatting we need to defien our data type so we can handle all kind of error and mistake.

    -> Day type: to handle day values.
    -> Reading type: to handle that reading must be in range.
    -> Month type: to handle that our input matched to month values.
    -> Year type: to handle that our year input is valid.
*/

const Tnull = -7777; // a temperature which is below absolute zero degree .
const Mnull = -1;
constexpr int impossible_min = -200;
constexpr int impossible_max = 200;
// Now first of all we will make a Day type data.

struct Day{
    // A day contain 24 hour so we will make a vector of 24 values with rnull
    vector<double> hour{vector<double>(24,Tnull)};
};
// Now we have a Day type which contain 24 values initialized with Tnull.


// 2. after Definig the Day type we need to make Month

struct Month{
    // Since month contains the max 31 day in a row so we will make a vector of Day.
    int Month {Mnull};  // Mnull = 1;
    vector<Day> day{32}; // We are leaving 0 and will strat our counting form 1.
    // Now we have 31 hays in a row of month.
}

// 3. After defining the Month we need to define the Year.

struct Year{
    int year;
    vector<Month> month{12}; // month index starts from 1.
    // Now we have 12 month in a row of Year. 
}

// after this we need to make a Reading type data.

struct Reading{
    // This Reading contain three things Day, hour, Temp.
    int day;
    int hour;
    double temp;
    // Reading is the inner most (lowest) part in the hierarchy of in this strured data 
};

// month_to_int funciton: to convert the string values into the month number.
int month_to_int(const string& s){
    vector<string> months{"None","jan", "feb", "mar", "apr", "may", 
                    "jun", "jul", "aug", "sep", "oct", "nov", "dec"}

    for(int i=1; i<=months.size(); i++)        
        if(months[i] == s) return i;
        
}

// Now we will make a private function to check the validity of the reading
bool is_valid(const Reading& r){
    // this function will test that our hour and temprature values are valid.
    if(r.hour<0 || r.hour>23) return false;
    if(r.day<1 || r.day>31) return false;
    if(r.temp< impossible_min || r.temp> impossible_max) return false;

}

void end_of_loop(istream& ist, const char ch, const string error){
    // Now we will make this end of loop if stream fail

    if(ist.fail()){

        ist.clear();
        char ch;

        if(ist>>ch && ch == '}') return;
        cerr<<error<<endl;
         
    }
}
// Now we make a operator >> to read the temp data.

istream& operator>>(istream& ist, Reading& r){


    // Now we will read the Reading with by using the >> operator
    // format: (day hour temp)

    char ch;  // to hold the character form the istream

    if(ist>>ch && ch != "("){
        // if this condition is satisfied then it could be a reading.
        // Now if both condition are statisfied then it means that we have wrong format or we are fail to get a bit.
        ist.unget();
        /*
        ist.unget: Attempts to decrease the current location in the stream by one character, 
        making the last character extracted from the stream once again available to be extracted by input operations.
        */ 

       // since there is a problem either in format or reading the stream so we need to clear it.
       ist.clear(ios_base::failbit);
       /* ios_base::failbit:- 
       The last input operation failed because of an error related to the internal logic of the operation itself.*/
        // Now after unget and clearing the stream we need to return it.

        return ist;
       
    }

    // Now if above condition is not satisfied then it means that our stream have inital format so now we need to get the other values.
    char ch2;
    int d;
    int h;
    int t;

    // now we will read the all above four values at once
    ist>>d>>h>>t>>ch2;   // Note here we don't check the validity of the Readings.

    // Now we need to check that if ch2 contains the end of the formating if not then we will throw the bad formatting.
    if(!ist || ch2 != ')') cerr<<"Bad reading\n";
    r.day = d;
    r.hour = h;
    r.temp = t;

    return ist;
    
}

istream& operator>>(istream& ist, Month& m){
    // In this we will make the operator to read the month values with the help of the istream;

    // format: {month feb}

    // Now first of all we wil check the format inital 
    char ch;
    if(ist>>ch && ch != '{' ){
        // if we don't get the either initial format character or fail to get any character
        ist.unget();
        ist.clear(ios_base::failbit);
        return ist;
    }

    // NOw if every thing is good then we will do the furthur thing.
    string month_tag; // in our case month tag is month with will define that this is month scope.
    string month_name; // name of the month.
    // Now we will read both values.
    ist>>month_tag>>month_name;
    // Now we will check that our month tag is good or not
    if(!ist || month_tag != 'month') cerr<<"Invalid tag of month\n";

    // now if all things are good then we need to assign the value.
    m.Month = month_to_int(month_name);

    int duplicates = 0; // To count the duplicate reading
    int invalids = 0; // To count the invalids reading.

    for(Reading r; ist>>r){
        // Now we will read all the reading availble in the current month.

        if(is_valid(r)){
            if(m.day[r.day].hour[r.hour] != Tnull)
                duplicates++;
            m.day[r.day].hour[r.hour] = r.temp;
        }
        else invalids++;
    }

    if(invalids) cerr<<"Error: Invalid Reading found in "<<r.day<<" of "<<m.Month;
    if(duplicates) cerr<<"Error: Duplicated Reading found in "<<r.day<<" of "<<m.Month;

    // Now we need to terminate the loop of streaming by using terminator character.
    // to termate this current loop of streaming we will use end_of_loop() function.
}