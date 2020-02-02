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

void insertInQueue(int queue[], int &length, int vertex)
{
    //cout << "insert " << vertex << endl;
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
    int beginning;
    cout << "Enter input file name: "; //asks input
    cin >> fileName;
    cout << "Enter a start vertex: ";
    cin >> beginning;
    ifstream infile(fileName.c_str());
  
    int N;
    infile >> N; 

    int adjacency[N][N];
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            infile >> adjacency[i][j];
    }

    infile.close();
    

    int queue[N];
    int queue_length = 0;
    queue[0] = beginning;
    queue_length++;
    int vertex;
    for(int i = 0; i < queue_length; i++)
    {
        vertex = queue[i];
        for(int j = 0; j < N; j++)
        {
            if(adjacency[vertex][j] != 0)
                insertInQueue(queue, queue_length, j);
        }
    }
    cout << "\nBFS Order: ";
    cout << queue[0] ;
    for( int i = 1; i < queue_length; i++)
        cout << " ---> " << queue[i] ;
    cout << endl;
}