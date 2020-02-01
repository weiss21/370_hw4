/*
 * Title: select-sort-k.cpp
 * Abstract: Modifies the selection sort algorithm to sort the first k smallest elements of the array with n elements
 * Author: Wais Robleh
 * ID: 1624
 * Date: 02/01/2020
 */
 
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;


int main(){
    
    ifstream myFile;
    string fileName;
    int *dynamArray;
    int count;
    int num;
    
   cout << "Enter input file name: ";
   cin >> fileName;
   myFile.open(fileName.c_str()); //open file
   
   if (myFile >> num)
    {
      count = num; // first line details count of array
    }
    dynamArray = new int[count]; //initialize dynamic array
    count = 0; //reset array count
    
    while(myFile >> num ) // To get you all the lines.
        {

	        dynamArray[count] = num; //add numbers from file to array
	        count++; //keep track of size in array
        }
    
	myFile.close();
	
	for(int i = 0; i < count; i++){
	    cout << "number " << i << " is " << dynamArray[i] << endl;
	}
	
	delete[] dynamArray; //delete dynamic array
    return 0;
}