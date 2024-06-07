#include<iostream>
#include<vector>
using namespace std;

//Prims algo for finding Minm spanning tree using weight matrix
//Time complexity: O(n^2) --> Due to the use of 2d array for storing weights(can be optimised by adjacency list)
class Edge
{
public:
    int source;
    int destination;
    int weight;

    Edge(int source, int destination, int weight)
    {
        this->source = source;
        this->destination = destination;
        this->weight = weight;
    }
};

vector<Edge> Prim(int n, int **matrix)
{
    int i=0,count=0,minw=INT_MAX,min_index;
    bool *visited= new bool[n];
    int *parent= new int[n];
    int *weight= new int[n];

    vector<Edge> MST;

    for(int i=0; i<n; i++)
    {
        visited[i]=false;
        parent[i]= -1;
        weight[i]= INT_MAX;
    }
    weight[0]=0;

    while(count<n-1)
    {
        visited[i]=true;
        minw= INT_MAX;
        for(int j=0; j<n; j++)
        {
            if(matrix[i][j]>0 && matrix[i][j]<weight[j] && !visited[j]){
                weight[j]=matrix[i][j];
                parent[j]=i;
            }
        }
        for(int j=0;j<n;j++){
            if(!visited[j] && (weight[j] < minw)){
                minw=weight[j];
                min_index=j;
            }
        }
        Edge temp(parent[min_index],min_index,minw);
        MST.push_back(temp);
        i=min_index;
        count++;

    }
    delete[] parent;
    delete[] visited;
    delete[] weight;

    return MST;

}

int main()
{
    int n;
    int **weight;

    cout<<"enter the no. of vertices"<<endl;
    cin>>n;
    weight= new int*[n];

    cout<<"enter the weight matrix(Enter 0 if no direct edge) :"<<endl;
    for(int i=0; i<n; i++)
    {
        weight[i]= new int[n];
        for(int j=0; j<n; j++)
        {
            cin>>weight[i][j];
        }
    }

    vector<Edge> MST= Prim(n,weight);
    cout <<"Resultant MST is:" << endl;
    cout <<"Source Destination Weight" << endl;
    for ( auto& edge : MST)
    {
        cout <<edge.source << " " << edge.destination << " " <<edge.weight<< endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete weight[i];
    }
    delete[] weight;

    return 0;

}

