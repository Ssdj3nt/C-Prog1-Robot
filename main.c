#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 16
#define m 16

struct data
{
    int x;
    int y;
}r;
struct point
{
    int p;
}pre;
void visualizza_matrice(char [][m]); // Visualizza in output la stanza.
void posizione_robot(char [][m]);
void movimento1(char [][m]);
void movimento2(char [][m]);
char swap(char *,char *);
int main()
{
    char stanza[n][m]={{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
                       {'X','.','.','.','.','.','.','.','.','.','.','.','.','.','.','X'},
                       {'X','.',' ','X',' ','.',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                       {'X','.',' ','X',' ','.',' ','X','X','X','X','X','X','X','X','X'},
                       {'X','.',' ','X',' ','.','.','.','.','.','.','.','.',' ',' ','X'},
                       {'X','.',' ','X',' ','.',' ',' ',' ',' ',' ',' ','.',' ',' ','X'},
                       {'X','.',' ','X',' ','.',' ',' ',' ',' ',' ',' ','.',' ',' ','X'},
                       {'X','.',' ','X',' ','.','.','.','.','.',' ',' ','.',' ',' ','X'},
                       {'X','.',' ','X',' ','.',' ','X',' ','.',' ',' ','.',' ',' ','X'},
                       {'X','.',' ','X',' ','.',' ','X',' ','.',' ',' ','.',' ',' ','X'},
                       {'X','.',' ',' ',' ','.',' ','X',' ','.',' ','X','X','X',' ','X'},
                       {'-','.',' ',' ',' ','.',' ','X',' ','.','.','.','.',' ',' ','X'},
                       {'-','.','.','.','.','.',' ','X',' ',' ',' ',' ','.',' ',' ','X'},
                       {'-','.',' ',' ',' ',' ',' ','X',' ',' ',' ',' ','.',' ',' ','X'},
                       {'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ','.',' ',' ','X'},
                       {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}};
    int nc;
    posizione_robot(stanza);
    visualizza_matrice(stanza);
    srand((unsigned int) time(0));
    while((r.x>=0 && r.x<n) && (r.y>=0 && r.y<m))//ciclo ripetuto finch� il robot resta all'interno alla stanza
    {
        visualizza_matrice(stanza);
        printf("RIGA=%d\t COLONNA=%d\n",r.x,r.y);
        nc=rand()%10;
        movimento1(stanza);
        /*if(nc>=0 && nc<3)
            movimento_casuale(stanza);
        else
            movimento_intelligente(stanza);
        system("PAUSE");*/
    }
    printf("\nIl robot e' uscito dalla stanza\n");
    visualizza_matrice(stanza);
}

void visualizza_matrice(char stanza[n][m])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%2c",stanza[i][j]);
        printf("\n");
    }
}
void posizione_robot(char stanza[n][m])
{
    do
    {
        puts("\n-Indica le cordinate della posizione iniziale del robot (2 a 14).");
        printf("-x:");
        scanf("%d",&r.x);
        printf("-y:");
        scanf("%d",&r.y);
        if(stanza[r.x][r.y] == ' ' && r.x<n && r.y<m)
            printf("\n-Robot inserito correttamente.\n");
        else
            printf("\n-Errore, riprova.\n");
    }
    while(stanza[r.x][r.y] == 'X' || (r.x>n && r.y>m));
    stanza[r.x][r.y]='R';
}
void movimento1(char stanza[n][m])
{
    int nr;
    stanza[r.x][r.y]=' ';
    nr=rand()%4;
    if(nr==0 && stanza[r.x][(--r.y)]=='X')  //NORD 1
    {
        if(r.y++ == '.' && pre.p!=2)
        {
            r.y++;
            pre.p=1;
        }
    }
    if(nr==1 && stanza[r.x][(++r.y)]=='X')  //SUD 2
    {
        if(r.y-- == '.' && pre.p!=1)
        {
            r.y--;
            pre.p=2;
        }
    }
    if(nr==2 && stanza[(--r.x)][r.y]=='X')  //EST 4
    {
        if(r.x++ == '.' && pre.p!=3)
        {
            r.x++;
            pre.p=4;
        }
    }
    if(nr==3 && stanza[(++r.x)][r.y]=='X')  //OVEST 3
    {
        if(r.x-- == '.' && pre.p!=4)
        {
            r.x--;
            pre.p=3;
        }
    }
    if((r.x>=0 && r.x<n) && (r.y>=0 && r.y<m))
        stanza[r.x][r.y]='R';
}

void mvoimento2(char stanza[n][m])
{

}

