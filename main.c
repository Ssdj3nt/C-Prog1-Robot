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
int maggiore(int ,int);
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
                             {'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
                             {'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
                             {'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
                             {'X',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','X'},
                             {'X','X','X',' ',' ',' ','X','X','X','X','X','X','X','X','X','X'}};//Matrice 16x16 che rappresenta la stanza e i suoi ostacoli.

    int x;//Variabile usata per contenere numeri casuali.
    posizione_robot(stanza);//Viene inserito il robot nella stanza.
    visualizza_matrice(stanza);//Visualizza la stanza dopo aver posizionato il robot.
    while((c.x>=0 && c.x<size) && (c.y>=0 && c.y<size))//Ciclo iterativo che ci consente di richiamare le function dei movimenti del robot finche esso non esce dalla stanza.
    {
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
    int max1=0,max2=0,max3=0,max4=0;
    int i,j=0,a,ra;

    while(stanza[c.x][c.y]!='X' && c.x<=size){//SUD
        c.x++;
        max1++;}
    if(stanza[c.x][c.y]=='X'){
        c.x--;
        max1--;}
    for(i=0;i<max1;i++)
        c.x--;

    while(stanza[c.x][c.y]!='X' && c.x>=0){//NORD
        c.x--;
        max2++;}
    if(stanza[c.x][c.y]=='X'){
        c.x++;
        max2--;}
    for(i=0;i<max2;i++)
        c.x++;

    while(stanza[c.x][c.y]!='X' && c.y<=size){//EST
        c.y++;
        max3++;}
    if(stanza[c.x][c.y]=='X'){
        c.y--;
        max3--;}
    for(i=0;i<max3;i++)
        c.y--;

    while(stanza[c.x][c.y]!='X' && c.y>=0){//OVEST
        c.y--;
        max4++;}
    if(stanza[c.x][c.y]=='X'){
        c.y++;
        max4--;}
    for(i=0;i<max4;i++)
        c.y++;

    if(maggiore(max1,max2)==maggiore(max3,max4)){
        ra=rand()%3;
        switch (ra)
        {
            case 0:a=maggiore(max1,max2);break;
            case 1:a=maggiore(max3,max4);break;
        }}
    else
        a = maggiore(maggiore(max1,max2), maggiore(max3,max4));

    if(a==max1){while(j!=max1){
        stanza[c.x][c.y]=' ';
        c.x++;
        stanza[c.x][c.y] = 'R';
        visualizza_matrice(stanza);
        printf("RIGA=%d\tCOLONNA=%d\n\n",c.x,c.y);//Visualizzazione della riga e della colonna che occupa il robot.
        j++;}}

    else if(a==max2){while(j!=max2){
            stanza[c.x][c.y]=' ';
            c.x--;
            stanza[c.x][c.y] = 'R';
            visualizza_matrice(stanza);
            printf("RIGA=%d\tCOLONNA=%d\n\n",c.x,c.y);//Visualizzazione della riga e della colonna che occupa il robot.
            j++;}}

    else if(a==max3){while(j!=max3){
            stanza[c.x][c.y]=' ';
            c.y++;
            stanza[c.x][c.y] = 'R';
            visualizza_matrice(stanza);
            printf("RIGA=%d\tCOLONNA=%d\n\n",c.x,c.y);//Visualizzazione della riga e della colonna che occupa il robot.
            j++;}}

    else if(a==max4){while(j!=max4){
            stanza[c.x][c.y]=' ';
            c.y--;
            stanza[c.x][c.y] = 'R';
            visualizza_matrice(stanza);
            printf("RIGA=%d\tCOLONNA=%d\n\n",c.x,c.y);//Visualizzazione della riga e della colonna che occupa il robot.
            j++;}}

}
int maggiore(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

