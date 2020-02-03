/*
 * Title: assignment.cpp
 * Abstract:  Reads the assignment costs of each person from a user and determine the best assignment
 * Author: Wais Robleh
 * ID: 1624
 * Date: 02/03/2020
 */

#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

int *ans;
int **costs;
void permute(int a[],int l,int r,int count,int n,int lcost){

    int tcost=0;
    if(l==r)
    {
        count++;
        cout<<"Person "<<count<<": <";
        for(int i=0;i<n;i++)
        {
            cout<<a[i]+1;
            if(i!=n-1)
            {
                cout<<", ";
            }
            tcost+=costs[i][a[i]];
        }
        cout<<"> => total cost:"<<tcost<<endl;
        if(tcost<lcost)
        {
            lcost = tcost;
            for(int i =0;i<n;i++)

            {
                ans[i] = a[i];
            }
        }
    } else {

        int temp;
        for(int i=l;i<=r;i++){

            temp = a[i];
            a[i] = a[l];
            a[l] = temp;
            permute(a,l+1,r,count,n,lcost);
            temp = a[i];
            a[i] = a[l];
            a[l] = temp;
        }
    }
}

int main()
{

    int lcost;

    lcost = INT_MAX;

    int n;

    cout<<"Enter number of jobs: ";
    cin>>n;
    costs = (int **)malloc(sizeof(int*)*n);
    cout<<"Enter assignment costs of "<< n <<" persons:"<<endl;

    for(int i=0;i<n;i++) {

        costs[i] = (int *)malloc(sizeof(int)*n);

        cout<<"Person "<<i+1<<": ";

        for(int j=0;j<n;j++){

            cin>>costs[i][j];
        }
    }

    ans = (int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++) {

        ans[i] = i;

    }

    permute(ans,0,n-1,0,n,lcost);
    int ans_cost=0;
    cout<<"\nSolution: <";

    for(int i=0;i<n;i++) {

        cout<<ans[i]+1;

        if(i!=n-1) {

            cout<<", ";

        }

        ans_cost+=costs[i][ans[i]];

    }

    cout<<"> => total cost: "<<ans_cost<<endl;

    return 0;

}

