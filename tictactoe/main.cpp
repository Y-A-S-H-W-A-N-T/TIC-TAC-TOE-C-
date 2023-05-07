#include <bits/stdc++.h>
using namespace std;
char tic[3][3];
char player1='X';
char player2='O';
void displayboard()
{
    cout<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<tic[i][j]<<" ";
        }
        cout<<endl;
    }
}
void initialboard()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            tic[i][j]='.';
        }
    }
}
void insertpos1(int pos[])
{
    int a=pos[0];
    int b=pos[1];
    tic[a][b]=player1;
}
void insertpos2(int pos[])
{
    int a=pos[0];
    int b=pos[1];
    tic[a][b]=player2;
}
void checkboard()
{
    if(
    (tic[1][1]=='X')&&(tic[0][0]=='X')&&(tic[2][2]=='X') || (tic[1][1]=='X')&&(tic[2][0]=='X')&&(tic[0][2]=='X')
    ||
    (tic[1][1]=='X')&&(tic[0][1]=='X')&&(tic[2][1]=='X') || (tic[1][1]=='X')&&(tic[1][0]=='X')&&(tic[1][2]=='X')
    ||
    (tic[0][0]=='X')&&(tic[0][1]=='X')&&(tic[0][2]=='X') || (tic[0][0]=='X')&&(tic[1][0]=='X')&&(tic[2][0]=='X')
    ||
    (tic[2][0]=='X')&&(tic[2][1]=='X')&&(tic[2][2]=='X') || (tic[2][2]=='X')&&(tic[1][2]=='X')&&(tic[0][2]=='X')
    )
    {
        cout<<"X------- PLAYER 1 WON -------X"<<endl;
        exit(0);
    }
    if(
    (tic[1][1]=='O')&&(tic[0][0]=='O')&&(tic[2][2]=='O') || (tic[1][1]=='O')&&(tic[2][0]=='O')&&(tic[0][2]=='O')
    ||
    (tic[1][1]=='O')&&(tic[0][1]=='O')&&(tic[2][1]=='O') || (tic[1][1]=='O')&&(tic[1][0]=='O')&&(tic[1][2]=='O')
    ||
    (tic[0][0]=='O')&&(tic[0][1]=='O')&&(tic[0][2]=='O') || (tic[0][0]=='O')&&(tic[1][0]=='O')&&(tic[2][0]=='O')
    ||
    (tic[2][0]=='O')&&(tic[2][1]=='O')&&(tic[2][2]=='O') || (tic[2][2]=='O')&&(tic[1][2]=='O')&&(tic[0][2]=='O')
    )
    {
        cout<<"X------- PLAYER 2 WON -------X"<<endl;
        exit(0);
    }
}
int main()
{
    initialboard();
    cout<<"X------- TIC TAC TOE -------X"<<endl;
    displayboard();
    cout<<"Enter the position in 2D indexing format"<<endl;
    while(true)
    {
       int pos[2];
       p1:
       cout<<"PLAYER 1 --- Enter position - > ";
       for(int i=0;i<2;i++)cin>>pos[i];
       if(tic[pos[0]][pos[1]]=='.')
       {
           insertpos1(pos);
       }
       else
       {
           goto p1;
       }
       displayboard();
       checkboard();
       p2:
       cout<<"PLAYER 2 --- Enter position - > ";
       for(int i=0;i<2;i++)cin>>pos[i];
       if(tic[pos[0]][pos[1]]=='.')
       {
           insertpos2(pos);
       }
       else
       {
           goto p2;
       }
       displayboard();
       checkboard();
    }
}
