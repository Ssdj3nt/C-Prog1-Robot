#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  size 16 // Dimensione delle righe e delle colonne.

struct robot
{
    int x;
    int y;
}coordinate;

void visualizza_matrice(char [][size]); // Visualizza in output la stanza.
void posizione_robot(char a[][size],char);
void movimento1(char a[][size]);
void movimento2(char a[][size]);

int main()
{
    char stanza_prog[size][size]={{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
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
    char Robot='R';
    int random;
    posizione_robot(stanza_prog,Robot);
    printf("\n-Il Robot verrà inizializzato con il carattere: %c \n",Robot);
    visualizza_matrice(stanza_prog);

    srand((unsigned int) time(0));
    while(coordinate.x != 0)
    {
        visualizza_matrice(stanza_prog);
        random = rand()%10;
        if(random >= 0 && random<3)
            movimento1(stanza_prog);
        else
            movimento2(stanza_prog);
    }
    printf("\nIl Robot è uscito dalla stanza.\n");
    visualizza_matrice(stanza_prog);
}

void visualizza_matrice(char a[size][size])
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
            printf("%2c",a[i][j]);
        printf("\n");
    }
}
void posizione_robot(char a[size][size],char Robot)
{
    do
    {
        puts("\n-Indica le cordinate della posizione iniziale del robot (2 a 14).");
        printf("-x:");
        scanf("%d",&coordinate.y);
        printf("-y:");
        scanf("%d",&coordinate.x);
        if(a[coordinate.x][coordinate.y] == ' ')
        {
            printf("\n-Robot inserito correttamente.\n");
            a[coordinate.x][coordinate.y]=Robot;
        }
        else
            printf("\n-Errore, qui è presente un ostacolo, riprova.\n");
    }
    while(a[coordinate.x][coordinate.y] == 'X');
}
void movimento1(char a[size][size])
{


} //30% dei casi.
void movimento2(char a[size][size])
{

} //70% dei casi.