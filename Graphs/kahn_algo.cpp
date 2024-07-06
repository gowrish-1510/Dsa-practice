#include<iostream>
#include<queue>
using namespace std;


void kahn(int **adj,int n){
queue<int> qu;
int indegree[n];
for(int i=0;i<n;i++){
   indegree[i]=0;
}

bool visited[n];
for(int i=0;i<n;i++){
   visited[i]=false;
}

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(adj[i][j]==1)
            indegree[j]++; //if adjacent increment the indegree at the index
    }
}

for(int i=0;i<n;i++){
    if(indegree[i]==0)
        qu.push(i);  //enqueue all vertices with indegree 0
}

  while(!qu.empty()){
    int node= qu.front();
    qu.pop();
    cout<<node<<" ";
    visited[node]=true;
    for(int i=0;i<n;i++){
       if(adj[node][i]==1 && visited[i]==false){
        indegree[i]--;  //subtract the indegree of the node's children(adjacent nodes)
        if(indegree[i]==0)
            qu.push(i);      //enqueue the nodes with 0 indegree
       }
    }
  }

  cout<<endl;

}

int main(){

    int **edges,n;
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

    cout<<"Topological sort order is:"<<endl;
    kahn(edges,n);
}
