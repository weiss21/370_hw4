/*
 * Title: assignment.cpp
 * Abstract:  Reads the assignment costs of each person from a user and determine the best assignment
 * Author: Wais Robleh
 * ID: 1624
 * Date: 02/03/2020
 */

#include <bits/stdc++.h>

using namespace std;
int main () {
 
    int num;
    int x = 1; //keep track of
    vector< vector<int> > counts;
    vector<int> total; //total costs dynamically stored.
    cout<<"Enter number of jobs:";
    cin>>num;
    int cost[num][num];

    cout<<"Enter assignment cost of "<<num<<" persons:"<<endl;

    for(int i =0 ;i<num;i++){
        cout<<"Person "<<i+1<<" : ";
        for(int j = 0 ; j<num;j++){
            cin>>cost[i][j]; //2D matrix costs
        }
    }

    int permutation[num];
    for(int i = 0;i<num;i++){
        permutation[i]=i+1; //jobs within
    }

    sort (permutation,permutation+num); //sorted jobs
    cout<<endl;

    do {
        cout<<"Permutation "<<x<<": <";
        vector<int> y; 

        for(int i = 0 ;i<num;i++)
            y.push_back(permutation[i]); 

        counts.push_back(y); 

        for (int i = 0; i < y.size(); i++) { //print these vector values
            if(i!=y.size()-1)
                cout << y.at(i) << ", ";
            else
                cout<<y.at(i);
        }
        x++;
        int totalCost = 0; //totalCost of this Permutation

        for(int i=0;i<num;i++){

            totalCost+=cost[i][permutation[i]-1]; //find and add
        }

        total.push_back(totalCost); 
        cout<<"> => total cost:"<<totalCost; 
        cout<<'\n';
    } while ( next_permutation(permutation,permutation+num) ); 


    vector<int> min = counts.at(distance(total.begin(), find(total.begin(),total.end(),
    *min_element(total.begin(), total.end()))));


    cout<<"\nSolution: <";
    for (int i = 0; i < min.size(); i++) { 
        if(i!=min.size()-1)
            cout << min.at(i) << ", ";
        else
            cout<<min.at(i);
    }
    //print solution
    cout<<"> => total cost: "<<*min_element(total.begin(), 
        total.end()) << endl; 

    return 0;
}