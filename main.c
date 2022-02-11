#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  size 16 // Dimensione delle righe e delle colonne.

struct data
{
    int x;
    int y;
}r;

void visualizza_matrice(char [][size]); // Visualizza in output la stanza.
void posizione_robot(char [][size]);
void movimento1(char [][size],int *);
void movimento2(char [][size]);

int main()
{
    char stanza[size][size]={{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
                                  {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                  {'X',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                  {'X',' ',' ','X',' ',' ',' ','X','X','X','X','X','X','X','X','X'},
                                  {'X',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                  {'X',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                  {'X',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                  {'X',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                  {'X',' ',' ','X',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
                                  {'X',' ',' ','X',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
                                  {'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ','X','X','X',' ','X'},
                                  {' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
                                  {' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
                                  {' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
                                  {'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
                                  {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}};
    int nc;
    int *pos=0;
    posizione_robot(stanza);
    srand((unsigned int) time(0));

    while((r.x>=0 && r.x<size-2) && (r.y>=0 && r.y<size-2)) //ciclo ripetuto finchè? il robot resta all'interno alla stanza
    {
        visualizza_matrice(stanza);
        printf("RIGA=%d\t COLONNA=%d\n",r.x,r.y);
        movimento1(stanza,pos);
        /*nc=rand()%10;
        if(nc>=0 && nc<3)
            movimento1(stanza);
        else
            movimento2(stanza);*/
    }
    printf("\nIl robot e' uscito dalla stanza\n");
    visualizza_matrice(stanza);
}

void visualizza_matrice(char stanza[size][size])
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
            printf("%2c",stanza[i][j]);
        printf("\n");
    }
}
void posizione_robot(char stanza[size][size])
{
    do
    {
        puts("\n-Indica le cordinate della posizione iniziale del robot (2 a 14).");
        printf("-x:");
        scanf("%d",&r.y);
        printf("-y:");
        scanf("%d",&r.x);
        if(stanza[r.x][r.y] == ' ' && r.x<size && r.y<size)
            printf("\n-Robot inserito correttamente.\n");
        else
            printf("\n-Errore, riprova.\n");
    }
    while(stanza[r.x][r.y] == 'X' || (r.x>size && r.y>size));
}
void movimento1(char stanza[size][size],int *pos)
{
    int n;
    stanza[r.x][r.y]=' ';
        n=rand()%4;
        if(n==0 && stanza[r.x][--r.y]=='X' && *pos!=2) //Nord 1
        {
            r.y++;
            *pos=1;
        }
        if(n==1 && stanza[r.x][++r.y]=='X' && *pos!=1) //Sud 2
        {
            r.y--;
            *pos=2;
        }
        if(n==2 && stanza[--r.x][r.y]=='X' && *pos!=4) //Ovest 3
        {
            r.x++;
            *pos=3;

        }
        if(n==3 && stanza[++r.x][r.y]=='X' && *pos!=3) //Est 4
        {
            r.x--;
            *pos=4;
        }
}

