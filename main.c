#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  size 16 // Dimensione delle righe e delle colonne.
#define TRUE 1
#define FALSE 0

struct robot
{
    int x;
    int y;
}c;

void visualizza_matrice(char [][size]); // Visualizza in output la stanza.
void posizione_robot(char [][size]);
void movimento1(char [][size],int *);
void movimento2(char [][size]);

int main()
{
    srand((unsigned int) time(0));
    char stanza[size][size]={{'X',' ',' ',' ','X','X','X','X','X','X','X','X','X','X','X','X'},
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
                             {'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
                             {'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
                             {'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
                             {'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
                             {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}};

    int *pos;
    posizione_robot(stanza);
    while((c.x>0 && c.x<size) && (c.y>0 && c.y<size))
    {
        visualizza_matrice(stanza);
        printf("RIGA=%d\t COLONNA=%d\n",c.x,c.y);
        movimento1(stanza,pos);
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
        puts("\n-Indica le coordinate della posizione iniziale del robot.");
        printf("-x:");
        scanf("%d",&c.x);
        printf("-y:");
        scanf("%d",&c.y);
        if(stanza[c.x][c.y] == ' ')
        {
            printf("\n-Robot inserito correttamente.\n");
            stanza[c.x][c.y]='R';
        }
        else
            printf("\n-Errore, qui e' presente un ostacolo, riprova.\n");
    }
    while(stanza[c.x][c.y] == 'X');
}
void movimento1(char stanza[size][size],int *pos)
{
    int nr,x=FALSE;
    stanza[c.x][c.y] = ' ';

    while(x==FALSE)
    {
        nr=rand()%4;
        switch (nr)
        {
            case 0: if(stanza[--c.x][c.y] == 'X' && (*pos==3 || *pos==4))c.x++;*pos=1;x=TRUE;break;//NORD

            case 1: if(stanza[++c.x][c.y] == 'X' && (*pos==3 || *pos==4))c.x--;*pos=2;x=TRUE;break;//SUD

            case 2: if(stanza[c.x][--c.y] == 'X' && (*pos==1 || *pos==2))c.y++;*pos=3;x=TRUE;break;//EST

            case 3: if(stanza[c.x][++c.y] == 'X' && (*pos==1 || *pos==2))c.y--;*pos=4;x=TRUE;break;//OVEST
        }
    }
    stanza[c.x][c.y]='R';
}//Movimento casuale,30% dei casi.

void movimento2(char a[size][size])
{

}//Movimento intelligente,70% dei casi.