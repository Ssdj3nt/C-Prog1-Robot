#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define  size 16 // Dimensione delle righe e delle colonne.

struct data
{
    int x;
    int y;
    char label;
}robot;

void visualizza_matrice(char [][size]); // Visualizza in output la stanza.
void posizione_robot(char [][size]);
void movimento1(char [][size]);
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
    robot.label = 'R';
    int random;
    posizione_robot(stanza);

    srand((unsigned int) time(0));

    while((robot.x>0 && robot.x<size-2) && (robot.y>0 && robot.y<size-2))
    {
        visualizza_matrice(stanza);
        printf("x=%d\t y=%d\n",robot.x,robot.y);
        random = rand()%10;
        if(random >= 0 && random<10)
            movimento1(stanza);
        /*else
            movimento2(stanza);*/
    }
    printf("\nIl Robot è uscito dalla stanza.\n");
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
        scanf("%d",&robot.y);
        printf("-y:");
        scanf("%d",&robot.x);
        if(stanza[robot.x][robot.y] == ' ')
        {
            printf("\n-Robot (%c) inserito correttamente.\n",robot.label);
            stanza[robot.x][robot.y]=robot.label;
        }
        else
            printf("\n-Errore, qui è presente un ostacolo, riprova.\n");
    }
    while(stanza[robot.x][robot.y] == 'X');
}
void movimento1(char stanza[size][size])
{
    int r_num;
    stanza[robot.x][robot.y]=' ';
    r_num = rand()%4;

    switch (r_num){

        case 0: if(stanza[--robot.x][robot.y] == 'X')stanza[++robot.x][robot.y];
        if(stanza[robot.x][--robot.y] == 'X'){
                stanza[robot.x][++robot.y];}

        case 1: if(stanza[--robot.x][robot.y] == 'X')stanza[++robot.x][robot.y];
            if(stanza[robot.x][++robot.y] == 'X'){
                stanza[robot.x][--robot.y];}

        case 2: if(stanza[++robot.x][robot.y] == 'X')stanza[--robot.x][robot.y];
            if(stanza[robot.x][++robot.y] == 'X'){
                stanza[robot.x][--robot.y];}

        case 3: if(stanza[++robot.x][robot.y] == 'X')stanza[--robot.x][robot.y];
            if(stanza[robot.x][--robot.y] == 'X'){
                stanza[robot.x][++robot.y];}}
}//30% dei casi.
void movimento2(char a[size][size])
{

} //70% dei casi.