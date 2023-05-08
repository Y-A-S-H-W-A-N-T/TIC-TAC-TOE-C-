#include <bits/stdc++.h>
using namespace std;
char tic[3][3];
char player1='X';
char player2='O';
int win=1;
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
void initializeboard()
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
        cout<<"[------- PLAYER 1 WON -------]"<<endl;
        win=0;
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
        cout<<"[------- PLAYER 2 WON -------]"<<endl;
        win=0;
    }
}
void checkfordraw()
{
    int dot=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(tic[i][j]=='.')
            {
                dot++;
            }
        }
    }
    if(dot==0)
    {
        cout<<"[---------------- MATCH DRAW ----------------]"<<endl;
        exit(0);
    }
}
void restart()
{
    if(win==0)
    {
        string ans;
        re:
        cout<<"PLAY AGAIN (yes/no) - >";
        cin>>ans;
        if(ans=="yes")
        {
            win=1;
            initializeboard();
        }
        else if(win==0)
        {
            cout<<"<<<<<<<<<<<<<<<<<<<< THE END >>>>>>>>>>>>>>>>>>>>"<<endl;
            exit(0);
        }
        else
        {
            cout<<"Enter 'yes' or 'no'"<<endl;
            goto re;
        }
    }
}
int main()
{
    initializeboard();
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
       checkfordraw();
       restart();
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
       checkfordraw();
       restart();
    }
}
