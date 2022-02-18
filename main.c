//Algoritmo per la simulazione del movimento di un robot in una stanza. Per il 30% il robot si muove in modo casuale, per il restante 70% vede quante caselle sono libere
// in una direzione e si muove di una casella alla volta verso di essa.In ogni caso il robot non deve mai prendere una direzione e poi tornare alla posizione precedente.
//Una volta posizionato, il robot si muove cosi da cercare l'uscita; una volta trovata l'uscita il programma termina.

#include <stdio.h>//Libreria standard I/O del C.
#include <stdlib.h>//Libreria per la funzione srand() e rand() per generare un seme e per generare numeri pseudocasuali.
#include <time.h>//Libreria utilizzata per inizializzare il seme a 0, cosi facendo, non si generano ripetizioni nella generazione di numeri casuali.
#define  size 16//La variabile size viene definita con il valore di 16, usata poi per indicare il numero di righe e di colonne.

struct robot
{
    int x;
    int y;
}c;//Struct che contiene le due variabili per le coordinate 'x' e 'y' del robot.

//Le function dichiarate di seguito prendono in input solamente la matrice e la sua grandezza.
void visualizza_matrice(char [][size]);//Visualizza in output(terminale) la stanza.
void posizione_robot(char [][size]);//Function deputata all'inserimento del robot nella stanza in una posizione iniziale scelta dall'utente.
void movimento1(char [][size]);//Function deputata al movimento casuale nella stanza del robot.Questo movimento si verifica nel 30% dei casi.
void movimento2(char [][size]);//Function deputata al movimento in cui il robot “vede” e individua il percorso piu lungo percorribile.Questo movimento si verifica nel 70% dei casi.
int  max_array(int []);//Funzione deputata alla ricerca dell'indice del massimo dell array 2D, essa simula la vista del robot in cui ''vede'' nelle 4 direzioni quale sia il percorso percorribile piu lungo.
int p=0;//Variabile globale in cui viene memorizzata la direzione presa del robot cosi che al passo successivo non possa tornare alla posizione precedente.

int main(void)
{
    srand((unsigned int) time(0));//Inizializzazione del seme per la generazione di numeri pseudocasuali.
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
                             {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}};//Matrice 16x16 che rappresenta la stanza e i suoi ostacoli.

    int x;//Variabile usata per contenere numeri casuali.
    posizione_robot(stanza);//Viene inserito il robot nella stanza.
    visualizza_matrice(stanza);//Visualizza la stanza dopo aver posizionato il robot.
    while((c.x>=0 && c.x<size) && (c.y>=0 && c.y<size))//Ciclo iterativo che ci consente di richiamare le function dei movimenti del robot finche esso non esce dalla stanza.
    {
        visualizza_matrice(stanza);//Visualizzazione della stanza.
        printf("RIGA=%d\t COLONNA=%d\n\n",c.x,c.y);//Visualizzazione della riga e della colonna che occupa il robot.
        x=rand()%10;//Generazione di numeri da 0 a 9.
        if(x>=0 && x<3)//Se i numeri generati vanno da 0 a 2, il robot si muove in modo casuale (30%).
            movimento1(stanza);
        else
            movimento2(stanza);//Tutti i numeri maggiori uguali di 3 fanno muovere il robot in modo'intelligente (70%).
    }
    printf("\nIl robot e' uscito dalla stanza!\n");//Quando il ciclo finisce e il robot esce dalla stanza viene visualizzato a terminale il messaggio.*/
}

void visualizza_matrice(char stanza[size][size])
{
    int i,j;//Indici per le righe e per le colonne.
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
            printf("%2c",stanza[i][j]);//Per tutte le righe e per tutte le colonne della matrice effettua la visualizzazione a terminale.
        printf("\n");//Questa operazione ci consente di visualizzare a terminale la disposizione sotto forma di matrice del contenuto di righe e colonne.
    }
}

void posizione_robot(char stanza[size][size])
{
    do//Esegui...
    {
        puts("\n-Indica le coordinate della posizione iniziale del robot.");
        printf("-x:");
        scanf("%d",&c.x);//Inseriamo all indirizzo della variabile struct x un valore, corrispondente a una coordinata.
        printf("-y:");
        scanf("%d",&c.y);//Inseriamo all indirizzo della variabile struct y un valore, corrispondente a una coordinata.
        if(stanza[c.x][c.y] == ' ')//Se le coordinate scelte rappresentano una casella della stanza vuota allora...
        {
            printf("\n-Robot inserito correttamente.\n");
            stanza[c.x][c.y]='R';//il robot viene inserito.
        }
        else
            printf("\n-Errore, qui e' presente un ostacolo, riprova.\n");//Altrimenti..
    }
    while(stanza[c.x][c.y] == 'X');//Finche' le coordinate inserite ricadono sulle mura o sugli ostacoli della stanza, viene chiesto all'utente di reinserire le coordinate.
}

void movimento1(char stanza[size][size])
{
    int nr;
    stanza[c.x][c.y] = ' ';//Ogni quando viene richiamata la funzione la posizione precedente del robot viene inizializzata come una casella vuota.
    nr=rand()%4;//Generazione casuale di numeri da 0 a 3, scelto un numero casuale il robot va in quella direzione corrispondente al numero generato.

    switch(nr)
        {
            case 0:if(p!=2){c.x++;p=1;}if(stanza[c.x][c.y]=='X'){c.x--;p=0;}break; //Se il robot non e' stato precedentemente a SUD allora... - Caso in cui il robot scelga di andare a NORD.

            case 1:if(p!=1){c.x--;p=2;}if(stanza[c.x][c.y]=='X'){c.x++;p=0;}break; //Se il robot non e' stato precedentemente a NORD allora... - Caso in cui il robot scelga di andare a SUD.

            case 2:if(p!=4){c.y++;p=3;}if(stanza[c.x][c.y]=='X' && c.y<size){c.y--;p=0;}break; //Se il robot non e' stato precedentemente a OVEST allora... - Caso in cui il robot scelga di andare a EST.

            case 3:if(p!=3){c.y--;p=4;}if(stanza[c.x][c.y]=='X' && c.y>=0){c.y++;p=0;}break; //Se il robot non e' stato precedentemente a EST allora... - Caso in cui il robot scelga di andare a OVEST.
        }stanza[c.x][c.y]='R';//Quando il robot ha scelto dove andare allora viene inserito il carattere rappresentante la sua posizione.
}

void movimento2(char stanza[][size])
{

    int pos[4]={0},i,j,ind_max;/* pos[] e' un array di 4 elementi che contiene il numero di caselle libere per ogni direzione.
      ind_max = indice del massimo. Serve per stabilire (tramite switch) in quale locazione dell'array pos vi è il massimo.*/

    i=c.x;
    while(stanza[i-1][c.y]!='X' && i>0){
        --i;
        ++pos[0];}//Caselle libere a NORD.


    i=c.x;
    while(stanza[i+1][c.y]!='X' && i<size){
        ++i;
        ++pos[1];}//Caselle libere a SUD.


    j=c.y;
    while(stanza[c.x][j+1]!='X' && j<size){
        ++j;
        ++pos[2];}//Caselle libere ad EST.


    j=c.y;
    while(stanza[c.x][j-1]!='X' && j>0){
        --j;
        ++pos[3];}//Caselle libere ad OVEST.


    ind_max=max_array(pos);
    stanza[c.x][c.y]=' ';


    switch(ind_max)
        {
            case 0:if(p!=2){c.x++;p=1;}if(stanza[c.x][c.y]=='X'){c.x--;p=0;}break; //Se il robot non e' stato precedentemente a SUD allora... - Caso in cui il robot scelga di andare a NORD.

            case 1:if(p!=1){c.x--;p=2;}if(stanza[c.x][c.y]=='X'){c.x++;p=0;}break; //Se il robot non e' stato precedentemente a NORD allora... - Caso in cui il robot scelga di andare a SUD.

            case 2:if(p!=4){c.y++;p=3;}if(stanza[c.x][c.y]=='X'){c.y--;p=0;}break; //Se il robot non e' stato precedentemente a OVEST allora... - Caso in cui il robot scelga di andare a EST.

            case 3:if(p!=3){c.y--;p=4;}if(stanza[c.x][c.y]=='X'){c.y++;p=0;}break; //Se il robot non e' stato precedentemente a EST allora... - Caso in cui il robot scelga di andare a OVEST.
        }

        stanza[c.x][c.y]='R';//Quando il robot ha scelto dove andare allora viene inserito il carattere rappresentante la sua posizione.
}

int max_array(int arr[])//arr[] = rappresenta l'array pos, il quale contiene il numero di caselle libere per ogni direzione
{
    int i,max=-1,num_max,ind[4];/*ind[] = array che conterrà gli indici di 1 o più massimi.
 * num_max  = indica quanti massimi ci sono all'interno dell'array arr[].*/
    for(i=0;i<4;++i)
        if(arr[i]>max)
        {
            max=arr[i];
            ind[0]=i;//Salva l'indice del massimo nella locazione ind[0].
            num_max=1;
        }
        else
        if(arr[i]==max)
        {
            ind[num_max]=i;
            ++num_max;
        }

    if(num_max>1)//Se num_max>1 ci sono più massimi, quindi viene restituito un indice a caso tra questi.
    {
        max=rand()%num_max;
        return ind[max];
    }
    else
        return  ind[0];//Se num_max non risulta maggiore di 1 viene restituito l'indice dell'unico max dell'array.
}


