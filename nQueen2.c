#include<stdio.h>
#define N 4

int board[N][N]={0};

int isSafe(int row,int col){
    for(int i=0;i<col;i++){
        if(board[row][i]==1){
            return 0;
        }
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1){
            return 0;
        }
    }
    for(int i=row,j=col;i<N && j>=0;i++,j--){
        if(board[i][j]==1){
            return 0;
        }
    }
    return 1;
}

void solve(int col){
    if(col==N){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(board[i][j]==1){
                    printf("Q ");
                }
                else printf(". ");
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    for(int row=0;row<N;row++){
        if(isSafe(row,col)){
            board[row][col]=1;
            solve(col+1);

            board[row][col]=0;
        }
    }
}

int main(){
    solve(0);
    return 0;
}