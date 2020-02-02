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

void selection(int arr[], int size, int k)
{
   int i, j, min, index, temp;
   for (i = 0;i < k;i++)
   {
       min = arr[i];
       index = i;
       for (j = i + 1;j < size;j++)
       {
           if (arr[j] < min)
           {
               min = arr[j];
               index = j;
           }
       }
       if( index != i){
           temp = arr[index];
           arr[index] = arr[i];
           arr[i] = temp;
       }
   }
}

int main(){
    
    ifstream myFile;
    string fileName;
    int *dynamArray;
    int count;
    int num, kNum;
    
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
	
	cout << "Enter the value k: ";
	cin >> kNum;
	
	selection(dynamArray, count, kNum);
	cout << "Output: ";
	for(int i = 0; i < kNum; i++){
	    cout  << dynamArray[i];
	    if(i < kNum - 1){
	        cout << ", ";
	    }
	}
	cout << endl;
	
	delete[] dynamArray; //delete dynamic array
    return 0;
}