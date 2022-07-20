// In this we will see how to make a program to HOw to a file or read some data by using the Streams.
#include<string>
#include<fstream>
#include<sstream>  // this liberary required to work with istringstream data.
#include<iostream>
#include<vector>   // to work with vectors.
#include <bits/stdc++.h>

/*
    Program: A program to write a file with custom data type like point into the file with the help of the fstream.
*/

using namespace std;  //

// Now first of all we will make a Point data type structure.

struct Point{
    int X;
    int Y;
}; // Now this Point struct will contain the X and Y cordinates.


void Perror(istringstream& buffer){
    cerr<<"Wrong Point format";
    // buffer.putback(ch);
}

Point* ReadPoint(istringstream& buffer){

    // This function will read the point form the buffer and also it will check the point format.
    static Point P;
    char ch;
    int x; // to hold the numbers.
        buffer>>ch; // getting the very first char from the buffer.
        
        if(ch == '('){
            
            buffer>>ch;  // reading the second character it must bu point.  

            if(isdigit(ch)){
                buffer.putback(ch);
                buffer>>x;
                P.X = x;

                buffer>>ch; // reading the 3rd character it must be command to spearate the points.
                if(ch==','){
                    
                    // if we found the command then we expect the next will come point.
                    buffer>>ch;
                    if(isdigit(ch)){
                        buffer.putback(ch);
                        // if we found the next point we will put this point into the P.Y.
                        buffer>>x;    
                        P.Y = x;

                        // Now we need to close this point format with ')'

                        buffer>>ch;
                        if(ch==')'){
                            // Do nothing if we found the right format.
                        }
                        else{
                            Perror(buffer);
                        }
                    }
                }
                else{
                    Perror(buffer);
                }
            }
            else{
                Perror(buffer);
            }
        }
        else {
            Perror(buffer);
        }

    return &P;
}

int main(){

    /*
        Now we need three things:
        1. istringstream: to store the read Points.
        2. Point: to store the point data.
        3. vector: to store the Points.
    */

   Point* P;
   vector<Point> Points;
   istringstream buffer;
   string bufferstring;

   // now we will make a ofstream object to read a file.
   ifstream ist {"Points", ios_base::binary};

   // Now we will read the file line by line.

   while (!ist.eof())
   {
       // read the file until we don't reach at the end of the file.

       // Now first of all we will get the line by using the getline fucntion.
       ist>>bufferstring;
       cout<<"buffer:- "<<bufferstring<<endl;
       if(bufferstring !="")
            buffer.str(bufferstring);

       //after reading the line we need to make some filter

        P = ReadPoint(buffer);

        // Now after reading the all the points we need to put these points into the vector;
        if(P->X != -1 && P->Y != -1)
            Points.push_back(*P);
        P->X = -1;
        P->Y = -1;
        bufferstring="";  // clearing the bufferstring to avoide the duplication.
   }

    cout<<"Points: [";
    for(Point P : Points){
        cout<<"("<<P.X<<","<<P.Y<<") ";
    }
    cout<<"]";

    ist.close();  // closing the file after work is done.
}

