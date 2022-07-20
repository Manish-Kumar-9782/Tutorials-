// Now in this section we will make a to read and write temperature data to or from the file.
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>

using namespace std;



// Now first of all we need to make Reading data type which will containt he hour at which reading noted and the temperature.

struct Rd{
            int hour;
            double temp; 
        };

class Reading{
    
    private:
        int hour; // to contain the hour at which reading is taken
        double temp; // to contain the temperature reading.

        
        

    // Now we will make our constructor our default construrto will set values to 0;
    public:
        Reading(int hr, double tmp){
            bool valid;  
            // now we will validate our data
            valid = is_valid(hr, tmp);

            if(!valid){
                hour = 0;
                temp = 0;
                cerr<<"invalid value: "<<"("<<hr<<','<<tmp<<")\n\n";
            }    
            else{
                hour = hr;
                temp = tmp;
            }

        }

        Reading():hour{0}, temp{0}{}  // Default constructor

    // A member function to get the readings.
    Rd* get_Reading(){

        static Rd rd; // a variable of reading Rd;
        rd.hour = hour;
        rd.temp = temp;

        return &rd;
    }

    void set_Reading(int hr, double tmp){
        // this function will be used to reset the readings.
        bool valid;

        valid = is_valid(hr, tmp);

        if(!valid)
                cerr<<"Error invalid values : "<<"("<<hr<<','<<tmp<<")\n\n"; 
        else
        {
            hour = hr;
            temp = tmp;
        }
    }
    
};


int main(){

    Reading rd(10, 100);

    Rd* reading = rd.get_Reading(); // now this will give us the rd values.


    rd.set_Reading('t', 102.4);
    cout<<"hour: "<<reading->hour<<endl;
    cout<<"Temp: "<<reading->temp<<endl; 

}