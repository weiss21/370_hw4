/*
 * Title: bfs.cpp
 * Abstract: Implements the Breadth-First Search (BFS) algorithm. 
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
    int count;
    int num, kNum;
    
   cout << "Enter input file name: ";
   cin >> fileName;
   myFile.open(fileName.c_str()); //open file
   
   if (myFile >> num)
    {
      count = num; // first line details count of array
    }
    //create matrix
    int** dynamArray = new int*[count]; //initialize dynamic array
    for(int k = 0; k < count; k++){
        dynamArray[k] = new int[count];
    }
    
    for(int i = 0; i < count; i++){
        for(int j = 0; j < count; j++){
            myFile >> num;
            dynamArray[i][j] = num;
        }
    }
    
    //prints out and tests for loop below
    /*
    for(int i = 0; i < count; i++){
        for(int j = 0; j < count; j++){
           cout << dynamArray[i][j] << " ";
        }
        cout << endl;
    }
    */
    
    //delete matrix
    for(int k = 0; k < count; k++){
        delete[] dynamArray[k];
    }
    delete[] dynamArray;
    return 0;
}