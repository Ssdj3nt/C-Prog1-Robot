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

// Procedura per la visualizzazione in output della matrice, della disposizione degli ostacoli e movimento del robot.
void visualizza(char [][lunghezza]);
// Immissione degli ostacoli generati randomicamente dalla procedura (int ostacoli).
void gen_ostacoli(char [][lunghezza]);
/*La generazione randomica viene eseguita su un intervallo che segue questi criteri:
     * 1: gli ostacoli non devono sovrapporsi alle pareti.
     * 2: gli ostacoli non devono presentarsi sull'uscita.
     * 3: la generazione per le righe avviene da  (a[1][0] ed a[n-2][0]).
     * 4: la generazione delle colonne avviene da (a[0][1] ed a[0][m-2]).
     * poiché in ogni riga/colonna due posizioni rappresentano gli estremi, cioè le pareti RAND_MAX=16-2;
     * quindi [1;14].*/
int gen_random(int);

void main()
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
                                        {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X'},
                                        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}};
    visualizza(stanza);
}

void visualizza(char a[profondita][lunghezza])
{
    int i,j;
    for(i=0;i<profondita;i++)
    {
        for(j=0;j<lunghezza;j++)
            printf("%2c",a[i][j]);
        printf("\n");
    }
}
void gen_ostacoli(char [profondita][lunghezza])
{
}
int gen_random(int x)
{
    srand((unsigned int) time(0));
    x = 1+rand()%14;
}

