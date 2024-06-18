#include<iostream>
#include<string>
using namespace std;

bool is_valid(int i,int j, int n, char **matrix,int **visited)
{
    if(i>=n || i<0)
        return false;
    if(j>=n || j<0)
        return false;
    if(visited[i][j])
        return false;

    return true;

}

bool search_helper(char** matrix,int n,int i,int j,string word,int **visited,int index)
{
    visited[i][j]=1;
    bool check;

    if(matrix[i][j]== word[index])
    {
        if(index==word.length()-1)
            return true;
        index++;

        if(is_valid(i+1,j,n,matrix,visited))
        {
            check= search_helper(matrix,n,i+1,j,word,visited,index);
            if(check)
                return true;
        }

        if(is_valid(i,j+1,n,matrix,visited))
        {
            check= search_helper(matrix,n,i,j+1,word,visited,index);
            if(check)
                return true;
        }

        if(is_valid(i-1,j,n,matrix,visited))
        {
            check= search_helper(matrix,n,i-1,j,word,visited,index);
            if(check)
                return true;
        }

        if(is_valid(i,j-1,n,matrix,visited))
        {
            check= search_helper(matrix,n,i,j-1,word,visited,index);
            if(check)
                return true;
        }

    }

    visited[i][j]=0;
    return false;
}

bool word_search(int n, char **matrix,string word)
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

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(search_helper(matrix,n,i,j,word,visited,0))
            {
                for (int i = 0; i < n; i++)
                delete[] visited[i];
                delete[] visited;
                return true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    delete[] visited[i];
    delete[] visited;
    return false;

}

int main()
{
    int n;
    string word;
    char **matrix;

    cout<<"enter dimension :"<<endl;
    cin>>n;
    cout<<"enter character matrix:"<<endl;
    matrix= new char*[n];
    for(int i=0;i<n;i++){
        matrix[i]= new char[n];
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    //fflush(stdin);
    cout<<"enter word for checking presence"<<endl;
    cin>>word;
    if(word_search(n,matrix,word))
        cout<<"word found!";
    else
        cout<<"word not found";

    return 0;

}
