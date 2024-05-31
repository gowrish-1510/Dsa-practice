#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;


void bfs_helper(int v1,int v2,int **edges,int n,bool *visited,unordered_map<int,int> &paths,queue<int> &sequence)
{
    visited[v1]=true;
    sequence.push(v1);

    while(!sequence.empty())
    {
        int present=sequence.front();
        sequence.pop();
        for(int i=0; i<n; i++)
        {
            if(!visited[i]&& edges[present][i]==1)
            {
                visited[i]=true;
                sequence.push(i);
                paths[i]=present;
                if(i==v2)
                {
                    return;
                }
            }
        }
    }
}

vector<int> bfs_path(int v1,int v2,int **edges,int n)
{
    unordered_map<int,int> paths;
    bool *visited= new bool[n];
    queue<int> sequence;
    vector<int> arr;

    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }

    bfs_helper(v1,v2,edges,n,visited,paths,sequence);
    if(visited[v2])
    {
        arr.push_back(v2);
        int prev= paths.at(v2);
        while(prev!=v1)
        {
            arr.push_back(prev);
            prev= paths.at(prev);
        }
        arr.push_back(v1);

        reverse(arr.begin(),arr.end());
    }

    delete[] visited;
    return arr;
}

int main()
{
    int **edges,n,v1,v2;
    cout<<"enter no of vertices :";
    cin>>n;
    edges= new int *[n];

    cout<<"enter adjacency matrix"<<endl;
    for(int i=0; i<n; i++)
    {
        edges[i]=new int[n];
        for(int j=0; j<n; j++)
        {
            cin>>edges[i][j];
        }
    }

    cout<<"enter starting and ending vertices: "<<endl;
    cin>>v1>>v2;
    vector<int> path= bfs_path(v1,v2,edges,n);
    vector<int>::iterator it;

    cout<<"path is "<<endl;
    for(it= path.begin(); it!=path.end(); it++)
    {
        cout<<*it<<" ";
    }

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
