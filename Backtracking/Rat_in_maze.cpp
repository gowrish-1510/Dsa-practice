#include<iostream>
using namespace std;

bool is_valid(int i,int j, int n, int **matrix,int **visited)
{
    if(i>=n || i<0)
        return false;
    if(j>=n || j<0)
        return false;
    if(matrix[i][j]==0)
        return false;
    if(visited[i][j])
        return false;

    return true;

}

void maze_helper(int **matrix,int n,int **visited,int i,int j)
{
    visited[i][j]=1;

    if(i==n-1 && j==n-1)
    {
        cout<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cout<<visited[i][j]<<" ";
            cout<<endl;
        }
        visited[i][j]=0;
        return;
    }

    if(is_valid(i+1,j,n,matrix,visited))
        maze_helper(matrix,n,visited,i+1,j);

    if(is_valid(i,j+1,n,matrix,visited))
        maze_helper(matrix,n,visited,i,j+1);

    if(is_valid(i-1,j,n,matrix,visited))
        maze_helper(matrix,n,visited,i-1,j);

    if(is_valid(i,j-1,n,matrix,visited))
        maze_helper(matrix,n,visited,i,j-1);

    visited[i][j]= 0; //backtrack to previous cell
}

void rat_in_maze(int **matrix,int n)
{
    int **visited= new int*[n];

    for(int i=0; i<n; i++)
    {
        visited[i]= new int[n];
        for(int j=0; j<n; j++)
        {
            visited[i][j]=0;
        }
    }

    maze_helper(matrix,n,visited,0,0);
    for (int i = 0; i < n; i++)
        delete[] visited[i];
    delete[] visited;
    return;
}

int main()
{
    int n, **matrix;
    cin>>n;
    matrix= new int*[n];

    cout<<"enter 0 wherever entry is restricted else enter 1"<<endl;
    for(int i=0; i<n; i++)
    {
        matrix[i]= new int[n];
        for(int j=0; j<n; j++)
            cin>>matrix[i][j];
    }
    cout<<"All possible solutions are:"<<endl;
    rat_in_maze(matrix,n);
    return 0;
}
