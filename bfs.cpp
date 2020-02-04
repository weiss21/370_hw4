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

void check(int queue[], int &length, int vertex)
{

    for(int i = 0; i < length; i++)
    {
        if(queue[i] == vertex)
            return;
    }
    queue[length] = vertex;
    length++;

}
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

    int adjacency[num][num];
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num; j++)
            infile >> adjacency[i][j];
    }

    infile.close();
    

    int queue[num];
    int queue_length = 0;
    queue[0] = start;
    queue_length++;
    int vertex;
    for(int i = 0; i < queue_length; i++)
    {
        vertex = queue[i];
        for(int j = 0; j < num; j++)
        {
            if(adjacency[vertex][j] != 0)
                check(queue, queue_length, j);
        }
    }
    cout << "\nBFS Order: ";
    cout << queue[0] ;
    for( int i = 1; i < queue_length; i++)
        cout << " ---> " << queue[i] ;
    cout << endl;
}