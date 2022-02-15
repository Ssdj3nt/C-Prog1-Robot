#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  size 16 // Dimensione delle righe e delle colonne.

struct robot
{
    int x;
    int y;
}c;

void visualizza_matrice(char [][size]); // Visualizza in output la stanza.
void posizione_robot(char [][size]);
void movimento1(char [][size]);
void movimento2(char [][size]);

int main()
{
    srand((unsigned int) time(0));
    char stanza[size][size]={{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
                             {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                             {'X',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                             {'X',' ',' ','X',' ',' ',' ','X','X','X','X','X','X','X','X','X'},
                             {'X',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                             {'X',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                             {'X',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                             {'X',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                             {'X',' ',' ','X',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' '},
                             {'X',' ',' ','X',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' '},
                             {'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ','X','X','X',' ',' '},
                             {'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' '},
                             {'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' '},
                             {'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
                             {'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
                             {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}};

    posizione_robot(stanza);
    visualizza_matrice(stanza);
    while((c.x>=0 && c.x<=size) && (c.y>=0 && c.y<=size))
    {
        visualizza_matrice(stanza);
        printf("RIGA=%d\t COLONNA=%d\n",c.x,c.y);
        movimento1(stanza);
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
        puts("\n-Indica le cordinate della posizione iniziale del robot.");
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
void movimento1(char stanza[size][size])
{
    int nr;
    nr=rand()%4;
    stanza[c.x][c.y] = ' ';

    switch (nr)
    {
        case 0: if(stanza[--c.x][c.y] == 'X') stanza[++c.x][c.y];break;//NORD

        case 1: if(stanza[++c.x][c.y] == 'X') stanza[--c.x][c.y];break;//SUD

        case 2: if(stanza[c.x][--c.y] == 'X') stanza[c.x][++c.y];break;//EST

        case 3: if(stanza[c.x][++c.y] == 'X') stanza[c.x][--c.y];break;//OVEST
    }
    stanza[c.x][c.y]='R';
}
void movimento2(char a[size][size])
{

}