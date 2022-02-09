#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  size 16 //essendo una matrice 16x16 basta inizializzare anche una sola dimensione;
typedef enum {False,True} logical;

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

void scelta_stanza(char stanza[][size],char stanza_prog[][size],char); /* Nelle specifiche del progetto viene richiesto di implementare una specifica disposizione di una stanza
 * per poi testarne diverse configurazioni. Volendo rispettare queste specifiche si rende disponibile la scelta della stanza richiesta
 * e una stanza in cui è possibile generare randomicamente gli ostacoli per effettuare test senza modificare il codice.*/

void visualizza_matrice(char [][size]); /* Visualizza in output la stanza,in particolare, la disposizione degli ostacoli e il movimento del robot.*/
void genera_ostacoli(char [][size]); /* Immette ostacoli generati randomicamente nella stanza_prog;
 * La generazione randomica viene eseguita su un intervallo che segue questi criteri:
     * 1: gli ostacoli non devono sovrapporsi alle pareti.
     * 2: gli ostacoli non devono presentarsi sull'uscita o ostacolarne l'accesso (Edge Case).
     * 3: la generazione per le righe avviene da  (a[2][0] ed a[n-2][0]).
     * 4: la generazione delle colonne avviene da (a[0][2] ed a[0][m-2]).
     * poiché in ogni riga/colonna due posizioni rappresentano gli estremi, cioè le pareti RAND_MAX=16-2, quindi [1;14].*/
void posizione_robot(char a[][size],char);

int main()
{
    char stanza[size][size]={{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
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
    scelta_stanza(stanza,stanza_prog,Robot);

}

void scelta_stanza(char stanza[size][size],char stanza_prog[size][size],char Robot)
{
    int scelta;
    printf("\nDesidera inizializzare la stanza come da disposizioni del progetto? (0=No,1=Si):");
    scanf("%d",&scelta);
    if(scelta == True)
    {
        posizione_robot(stanza_prog,Robot);
        printf("\n-Il Robot verrà inizializzato con il carattere: %c \n",Robot);
        visualizza_matrice(stanza_prog);
    }

    else if (scelta == False)
    {
        genera_ostacoli(stanza);
        puts("\n-Gli ostacoli sono stati disposti.\n");
        posizione_robot(stanza,Robot);
        visualizza_matrice(stanza);
    }
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
void genera_ostacoli(char a[size][size])
{
    int i,z;
    printf("\n-Inserisci la quantità di ostacoli da inserire (valori da 1 a 50 generano un percorso accettabile):");
    scanf("%d",&z);
    srand((unsigned int)time(0));
    for(i=1;i<z;i++)
    {
        obstacle.x = 2+rand()%14;
        obstacle.y = 2+rand()%14;
        a[obstacle.x][obstacle.y]='X';
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