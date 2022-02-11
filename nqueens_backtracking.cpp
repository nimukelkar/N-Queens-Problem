#include <iostream>
#define N 4
int success = 0;
using namespace std;

void display(int A[][N]) //Displays the chessboard.
{
    for (int j = 0; j < N; j++)
    {
        cout << endl;
        cout << endl;
        for (int i = 0; i < N; i++)
        {
            cout << A[i][j] << " ";
        }
    }
    cout << endl;
}

bool satconstraint(int board[][N], int col, int row)  
{


    for (int j = 0; j < col; j++)
    {
        if (board[row][j] == 1)
        {
            return false;
        }
    }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 1)
            {
                return false;
            }
        }
            for (int i = row, j = col; i >= 0 && j >= 0; i++, j--)
            {
                if (board[i][j] == 1)
                {
                    return false;
                }
            }
            return true;
        }
    


bool solve(int board[][N], int col){
    if(col==N){
        success=1;
        return true;
    }
    for(int row=0;row<N;row++){
        if(satconstraint(board,col,row)==true){
            board[row][col]=1;
            if (solve(board,col+1))
                return true;
            board[row][col]=0;
        }
    }
    return false;
}

int main(){
    int board[N][N]={0};
    solve(board,0);
    cout<<"Successs is"<<success<<endl;
    display(board);
    return 0;

}