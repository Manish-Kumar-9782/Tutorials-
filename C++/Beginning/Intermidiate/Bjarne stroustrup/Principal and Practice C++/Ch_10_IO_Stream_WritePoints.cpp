// In this we will see how to make a program to HOw to a file or read some data by using the Streams.
#include<string>
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

// Now we write some cordinate on a file by using the ofstream 

int main(){

    // Now first of all we will make a Point Variable
    Point p;

    // Now we will make a vector which will store the all the points.
    vector<Point> Cords; // Cords vector will contain the all the points.

    // Now we will enter all the Points
    char ch=' ';

    cout<<"Please enter points: ";
    
    while(cin){

        if(cin.bad() || cin.fail())
            cerr<<"Somting is wrong with the input stream"<<endl;
        
        cin>>ch;
        if(ch=='q') break;

        cin.putback(ch); // if ch is not q then 
        cin>>p.X;
        cin>>p.Y;

        Cords.push_back(p);            
    }
   
   cout<<"Inserted Points: [";
        for(Point P : Cords)
            cout<<"("<<P.X<<','<<P.Y<<") ";

        cout<<"]";


    // Now after getting all the points we need to wrrite those points into a file.
    // for that we need to make a ofstream object
    ofstream ost {"Points", ios_base::binary}; //  opening the Points file as binary

    if(!ost) cerr<<"Unable to Write the Points file.";

    // Now we need to write the points by using the Operatro >> on ost 

    for(Point P : Cords)
        ost<<"("<<P.X<<','<<P.Y<<")\n";

    ost.close();
}