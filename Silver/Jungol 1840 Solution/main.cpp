#include<stdio.h>
using namespace std;

int a,b;
int arr[10][10],rchk[10][10],cchk[10][10],lchk[10][10];
void input()
{
    int i,j,k;
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            scanf("%d",&k);
            arr[i][j]=k;
            rchk[i][k]=cchk[j][k]=lchk[i/3*3+j/3][k]=1;
        }
    }
}



int sudoku(int i,int j)
{
    if(j>8) i++,j=0;
    if(i>8) return 1;
    if(arr[i][j]) return sudoku(i,j+1);
    else{
        for(int k=1;k<10; k++)
        {
            if(rchk[i][k]+cchk[j][k]+lchk[i/3*3+j/3][k] == 0){
                rchk[i][k]=cchk[j][k]=lchk[i/3*3+j/3][k]=1;
                arr[i][j]=k;
                if(sudoku(i,j+1)) return 1;
                arr[i][j]=0;
                rchk[i][k]=cchk[j][k]=lchk[i/3*3+j/3][k]=0;
            }
        }
    }
    return 0;
}

void output()
{
    for(int  i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    input();
    sudoku(0,0);
    output();
    return 0;
}