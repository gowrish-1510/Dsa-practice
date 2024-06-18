#include<iostream>
using namespace std;

bool is_valid(int n,char **board,int row,int col)
{
    for(int i=0; i<row; i++)
    {
        if(board[i][col]=='Q')
            return false;       //checking previous rows with same column
    }
    int i,j;
    for( i=row-1,j=col-1; i>=0 && j>=0; i--,j--)
    {
        if(board[i][j]=='Q')
            return false;          //checking left upper diagonal
    }

    for( i=row-1,j=col+1; i>=0 && j<n; i--,j++)
    {
        if(board[i][j]=='Q')
            return false;         //checking right upper diagonal
    }

    return true;
}

void print_board(int n, char **board)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void queen_helper(int n, char **board,int row)
{
    if(row==n)
    {
        print_board(n,board);
        return;
    }

    for(int j=0; j<n; j++)
    {
        if(is_valid(n,board,row,j))
        {
            board[row][j]='Q';
            queen_helper(n,board,row+1);
            board[row][j]='x'; //backtrack
        }
    }

}

void N_queens(int n)
{
    char **board= new char*[n];
    for(int i=0; i<n; i++)
    {
        board[i]= new char[n];
        for(int j=0; j<n; j++)
            board[i][j]= 'x';
    }

    queen_helper(n,board,0);
    for(int i=0; i<n; i++)
    {
        delete[] board[i];
    }
    delete[] board;
    return;
}

int main()
{
    int n;
    cout<<"enter no of rows: ";
    cin>>n;

    cout<<"All possible N-Queens solution are"<<endl;
    N_queens(n);

    return 0;
}
