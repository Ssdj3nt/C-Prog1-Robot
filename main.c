#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  lunghezza  16
#define  profondita 16

struct robot
{
    int x;
    int y;
}coordinate;
struct ostacolo
{
    int x;
    int y;
}obstacle;

void visualizza_matrice(char [][lunghezza]); // Visualizza in output la stanza,in particolare, la disposizione degli ostacoli e il movimento del robot.
void genera_ostacoli(char [][lunghezza]); // Immette ostacoli generati randomicamente nella stanza.
/*La generazione randomica viene eseguita su un intervallo che segue questi criteri:
     * 1: gli ostacoli non devono sovrapporsi alle pareti.
     * 2: gli ostacoli non devono presentarsi sull'uscita o ostacolarne l'accesso (Edge Case).
     * 3: la generazione per le righe avviene da  (a[2][0] ed a[n-2][0]).
     * 4: la generazione delle colonne avviene da (a[0][2] ed a[0][m-2]).
     * poiché in ogni riga/colonna due posizioni rappresentano gli estremi, cioè le pareti RAND_MAX=16-2, quindi [1;14].*/
void posizione_robot(char a[][lunghezza],char);

int main()
{
    char stanza[profondita][lunghezza]={{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
                                        {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}};

    char Robot='R';
    visualizza_matrice(stanza);
    genera_ostacoli(stanza);
    puts("\n-Gli ostacoli sono stati disposti.\n");

    printf("-Il Robot verrà inizializzato con il carattere: %c \n",Robot);
    posizione_robot(stanza,Robot);

}

void visualizza_matrice(char a[profondita][lunghezza])
{
    int i,j;
    for(i=0;i<profondita;i++)
    {
        for(j=0;j<lunghezza;j++)
            printf("%2c",a[i][j]);
        printf("\n");
    }
}
void genera_ostacoli(char a[profondita][lunghezza])
{
    int i,z;
    puts("\n-Inserisci la quantità di ostacoli da inserire (valori da 1 a 50 generano un percorso accettabile):");
    scanf("%d",&z);
    srand((unsigned int)time(0));
    for(i=1;i<z;i++)
    {
        obstacle.x = 2+rand()%14;
        obstacle.y = 2+rand()%14;
        a[obstacle.x][obstacle.y]='X';
    }
    visualizza_matrice(a);
}
void posizione_robot(char a[profondita][lunghezza],char Robot)
{
    do
    {
        puts("\n-Indica le cordinate della posizione iniziale del robot (2 a 14).");
        puts("-Inserisci l'ordinata:");
        scanf("%d",&coordinate.x);
        puts("-Inserisci l'ascissa:");
        scanf("%d",&coordinate.y);
        if(a[coordinate.x][coordinate.y] == ' ')
        {
            printf("\n-Robot inserito correttamente.\n");
            a[coordinate.x][coordinate.y]=Robot;
            visualizza_matrice(a);
        }
        else
            printf("\n-Errore, qui è presente un ostacolo, riprova.\n");
    }
    while(a[coordinate.x][coordinate.y] == 'X');
}