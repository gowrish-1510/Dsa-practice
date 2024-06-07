#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//implementation of Dijkstra algorithm for shortest path using weight matrix
//Time complexity: O(n^2) --> Due to the use of 2d array for storing weights(can be optimised by adjacency list)

void Dijkstra(int n,int **arr,int source)
{
    int count=0,minindex;
    stack<int> temp;
    bool *visited= new bool[n];
    int *weight= new int[n];
    int *parent= new int[n];

    for(int i=0; i<n; i++)
    {
        visited[i]=false;
        weight[i]= INT_MAX;
        parent[i]=-1;
    }
    weight[source]=0;
    int i=source;
    cout<<"Vertices and their distance from source:"<<endl;

    while(count!=n-1)
    {
        visited[i]=true;
        int minpath=INT_MAX;
        for(int j=0; j<n; j++)
        {
            if(arr[i][j]>0 && (weight[i]+arr[i][j]< weight[j]) && !visited[j]) //if vertex weight is greater than distance from current vertex,update
            {
                weight[j]= weight[i]+ arr[i][j]; //update distance
                parent[j]=i;  //update parent
            }
        }

        for(int j=0; j<n; j++)
        {
            if(weight[j]<minpath && !visited[j])
            {
                minpath=weight[j];
                minindex=j;
            }
        }

        int k=minindex;
        while(k!=source)
        {
            temp.push(k);
            k=parent[k];
        }
        cout<<source;
        while(!temp.empty())
        {
            cout<<"->"<<temp.top();
            temp.pop();
        }
        cout<<" Distance :- "<<minpath<<endl;
        i=minindex;
        count++;

    }
    delete[] visited;
    delete[] parent;
    delete[] weight;

}

int main()
{
    int n,source;
    int **weight;

    cout<<"enter the no. of vertices"<<endl;
    cin>>n;
    weight= new int*[n];

    cout<<"enter the weight matrix (Enter 0 if no direct edge):"<<endl;
    for(int i=0; i<n; i++)
    {
        weight[i]= new int[n];
        for(int j=0; j<n; j++)
        {
            cin>>weight[i][j];
        }
    }

    cout<<"Enter source vertex: ";
    cin>>source;

    Dijkstra(n,weight,source);

     for (int i = 0; i < n; i++)
    {
        delete weight[i];
    }
    delete[] weight;
    return 0;
}
