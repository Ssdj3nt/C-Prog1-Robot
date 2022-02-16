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
int max_array(int []);
int p;//Variabile globale in cui viene salvata la direzione, cosi facendo il robot non potrà tornare nella direzione opposta al passo successivo.

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

    int x;
    posizione_robot(stanza);
    while((c.x>=0 && c.x<=size) && (c.y>=0 && c.y<=size))
    {
        x=rand()%5;
        visualizza_matrice(stanza);
        printf("RIGA=%d\t COLONNA=%d\n",c.x,c.y);
        movimento1(stanza);
    }
    printf("\nIl robot e' uscito dalla stanza\n");
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

void movimento1(char stanza[size][size])
{
    int nr;
    stanza[c.x][c.y] = ' ';
    nr=rand()%4;

        switch(nr)
        {
            case 0:	c.x--;if(stanza[c.x][c.y]=='X' && p!=2)c.x++;p=1;break;
            case 1:	c.x++;if(stanza[c.x][c.y]=='X' && p!=1)c.x--;p=2;break;
            case 2: c.y--;if(stanza[c.x][c.y]=='X' && p!=4)c.y++;p=3;break;
            case 3:	c.y++;if(stanza[c.x][c.y]=='X' && p!=3)c.y--;p=4;break;
        }
    stanza[c.x][c.y]='R';
}//30% dei casi.

void movimento2(char stanza[size][size])
{
    int pos[4]={0},i,j,ind_max;
    /*pos[]   = array di 4 elementi che contiene il numero di caselle libere per ogni direzione
            pos[0]=numero di caselle libere verso ovest
            pos[1]=numero di caselle libere verso est
            pos[2]=numero di caselle libere verso nord
            pos[3]=numero di caselle libere verso sud
      ind_max = indice del massimo. Serve per stabilire (tramite switch) in quale locazione dell'array pos vi � il massimo
    */
    j=c.y;
    while(stanza[c.x][j-1]!='X' && j>0)
    {
        --j;
        ++pos[0];//caselle libere ovest
    }
    j=c.y;
    while(stanza[c.x][j+1]!='X' && j<size)
    {
        ++j;
        ++pos[1];//caselle libere est
    }
    i=c.x;
    while(stanza[i-1][c.y]!='X' && i>0)
    {
        --i;
        ++pos[2];//caselle libere nord
    }
    i=c.x;
    while(stanza[i+1][c.y]!='X' && i<size)
    {
        ++i;
        ++pos[3];//caselle libere sud
    }
    ind_max=max_array(pos);
    stanza[c.x][c.y]=' ';

    switch(ind_max)
    {
        case 0: c.x--;if(stanza[c.x][c.y]=='X') ++c.x;stanza[c.x][c.y]='R';break;//NORD
        case 1: c.x++;if(stanza[c.x][c.y]=='X') --c.x;stanza[c.x][c.y]='R';break;//SUD
        case 2: c.y--;if(stanza[c.x][c.y]=='X') ++c.y;stanza[c.x][c.y]='R';break;//EST
        case 3: c.y++;if(stanza[c.x][c.y]=='X') --c.y;stanza[c.x][c.y]='R';break;//OVEST
    }
}//70% dei casi.

int max_array(int a[])
{
    int i,max=-1,num_max,ind[4];
    /*ind[]    = array che conterr� gli indici di 1 o pi� massimi
      num_max  = indica quanti massimi ci sono all'interno dell'array arr[]
    */
    for(i=0;i<4;++i)
        if(a[i]>max)
        {
            max=a[i];
            ind[0]=i;//salva l'indice del massimo nella locazione ind[0]
            num_max=1;
        }
        else
        if(a[i]==max)
        {
            ind[num_max]=i;
            ++num_max;
        }

    if(num_max>1)//se num_max>1 ci sono pi� massimi, quindi viene restituito un indice a caso tra questi
    {
        max=rand()%num_max;
        return ind[max];
    }
    else
        return  ind[0];//se num_max non risulta maggiore di 1 viene restituito l'indice dell'unico max dell'array
}