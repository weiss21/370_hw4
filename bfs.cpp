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

void check(int qStack[], int &size, int vertices);
int main()

{
    string fileName;
    int start;
    cout << "Enter filename: "; 
    cin >> fileName;
    cout << "Enter a start vertex: ";
    cin >> start;
    ifstream infile(fileName.c_str());
  
    int num;
    infile >> num; 

    int dynamarray[num][num];
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
            infile >> dynamarray[i][j];
    }

    infile.close();
    

    int stack[num];
    int queue_length = 0;
    stack[0] = start;
    queue_length++;
    int vertex;
    for(int i = 0; i < queue_length; i++)
    {
        vertex = stack[i];
        for(int j = 0; j < num; j++)
        {
            if(dynamarray[vertex][j] != 0)
                check(stack, queue_length, j);
        }
    }
    cout << "\nBFS Order: ";
    cout << stack[0] ;
    for( int i = 1; i < queue_length; i++)
        cout << " ---> " << stack[i] ;
    cout << endl;
}

void check(int stack[], int &length, int vertex)
{

    for(int i = 0; i < length; i++)
    {
        if(stack[i] == vertex)
            return;
    }
    stack[length] = vertex;
    length++;

}