#include <iostream>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

const int N=18, M=45;

char matr[N][M]={
        {' ','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',' ',},
        {'|','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~','|',},
        {'|',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','|',},
        {'|','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~','|',},
        {'|',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','|',},
        {'|','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~','|',},
        {'|',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','|',},
        {'|','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~','|',},
        {'|',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','|',},
        {'|','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~','|',},
        {'|',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','|',},
        {'|','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~','|',},
        {'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',' ',' ',' ','-','-','-','-','-','-','-','-','|',},
        {'|','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','|',' ',' ',' ','|','w','w','w','w','w','w','w','|',},
        {'|','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','|',' ',' ',' ','|','w','w','w','w','w','w','w','|',},
        {'|','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','|',' ',' ',' ','|','w','w','w','w','w','w','w','|',},
        {'|','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','|',' ',' ',' ','|','w','w','w','w','w','w','w','|',},
        {'\\','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','/',},
                   };

char sol[N][M]={
        {' ','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',' ',},
        {'|','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~','|',},
        {'|',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','|',},
        {'|','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~','|',},
        {'|',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','|',},
        {'|','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~','|',},
        {'|',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','|',},
        {'|','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~','|',},
        {'|',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','|',},
        {'|','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~','|',},
        {'|',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','|',},
        {'|','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~',' ','~','|',},
        {'|','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-',' ',' ',' ','-','-','-','-','-','-','-','-','|',},
        {'|','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','|',' ',' ',' ','|','w','w','w','w','w','w','w','|',},
        {'|','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','|',' ',' ',' ','|','w','w','w','w','w','w','w','|',},
        {'|','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','|',' ',' ',' ','|','w','w','w','w','w','w','w','|',},
        {'|','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','w','|',' ',' ',' ','|','w','w','w','w','w','w','w','|',},
        {'\\','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','/',},
                   };

void scrivi_sol();
void scrivi_mappa();
void ponte1();
void ponte2();
void ponte3();
void gioco(int scelta);
void titolo();
void menu();
void caricamento();

int main()
{
    int scelta, scelta_menu;
    fstream fd;
    string s;

    caricamento();
    _sleep(5000);
    system("pause");
    system("cls");
    do
    {
       titolo();
       menu();
       cout<<endl<<endl<<"Scegli cosa fare (inserisci il numero corrispondente): ";
       cin>>scelta_menu;
       switch (scelta_menu)
       {
          case 1:
          {
             cout<<endl<<endl;
             system("pause");
             system("cls");
             cout<<"Scegli che livello affrontare: "<<endl<<endl<<"Semplice (1)"<<endl<<"Normale (2)"<<endl<<"Incubo (3)"<<endl<<endl;
             cout<<"Inserisci il numero: ";
             cin>>scelta;
             cout<<endl<<endl<<endl;
             system("pause");
             system("cls");
             caricamento();
             _sleep(2500);
             system("pause");
             system("cls");
             gioco(scelta);
          }
          system("pause");
          system("cls");
          break;
          case 2:
          {
             system("cls");
             fd.open("partite.txt", ios::in);
             if(!fd.is_open())
             {
                cout<<"Errore nell'apertura del file"<<endl;
                exit(1);
             }
             else
             {
                cout<<"Partite Recenti: "<<endl<<endl;
                while(!fd.eof())
                {
                   getline(fd,s);
                   cout<<endl<<s<<endl;
                }
             }
             cout<<endl<<endl<<endl<<endl<<endl<<endl;
             system("pause");
             system("cls");
             break;
          }
          case 3:
          {
             system("cls");
             cout<<endl<<endl<<endl;
             cout<<" ISTRUZIONI:"<<endl<<endl;
             cout<<" 1) Quando sceglierai la modalita' in cui giocare, ti verra' mostrata la soluzione del livello...ATTENZIONE PER UN PERIODO LIMITATO!!!"<<endl;
             cout<<" 2) Dopo la soluzione dovrai ricordarti il ponte mostrato e arrivare alla fine, rappresentata con una F;"<<endl;
             cout<<" 3) Ti muoverai con W (sopra) A (sinistra) S (sotto) D (destra);"<<endl;
             cout<<" 4) Chi fara' meno unti vincera', infatti per ogni mossa il punteggio aumentera' di 5, per ogni !, aumentera' di 2;"<<endl;
             cout<<" 5) Avrai tre vite, quando sbaglierai apparira' un ! che ti ricordera' dell'errore. Se finisci le tre vite...GAME OVER!!!"<<endl<<endl<<endl<<endl;
             cout<<" Vai al menu'!"<<endl;
             cout<<endl<<endl<<endl;
             cout<<"                             *                                                       *                                                           *"<<endl;
             cout<<"                           *   *                                                   *   *                                                       *   *"<<endl;
             cout<<"                      * * *     * * *                                         * * *     * * *                                             * * *     * * *"<<endl;
             cout<<"                       *           *                                            *          *                                                *          *"<<endl;
             cout<<"                         *       *                                                *      *                                                   *       *"<<endl;
             cout<<"                       *           *                                            *          *                                               *           *"<<endl;
             cout<<"                     * * *       * * *                                        * * *      * * *                                           * * *       * * *"<<endl;
             cout<<"                           *   *                                                   *   *                                                      *     *"<<endl;
             cout<<"                             *                                                       *                                                           * "<<endl;
             cout<<endl<<endl<<endl;
          }
          system("pause");
          system("cls");
          break;
          case 4:
          {
             cout<<endl<<endl<<endl;
             system("pause");
             system("cls");
             cout<<endl<<endl<<endl;
             cout<<"                                                                                Grazie per aver giocato a Scary Bridge!!!"<<endl;
             cout<<endl<<"                                                                              Gioco creato da Flavio Olivieri - Classe: 3Bi"<<endl;
             cout<<endl<<"                                                                            Progetto di Fine Anno Scolastico 2018/2019 - Informatica"<<endl;
             cout<<endl<<endl<<endl;
             system("pause");
             exit (0);
          }
          default:
          {
             cout<<endl<<endl;
             cout<<"Scelta non disponibile nel menu', reinseriscila"<<endl;
             cout<<endl<<endl;
          }
          break;
          system("pause");
          system("cls");
       }
    }while(scelta_menu!=4);
    return 0;
}

void scrivi_sol()
{
    int m, n;

    for(m=0;m<N;m++)
    {
        cout<<"                                                                          ";
        for(n=0;n<M;n++)
          cout<<sol[m][n];
        cout<<endl;
    }
}

void scrivi_mappa()
{
    int m, n;

    for(m=0;m<N;m++)
    {
        cout<<"                                                                          ";
        for(n=0;n<M;n++)
          cout<<matr[m][n];
        cout<<endl;
    }
}

void ponte1()
{
   sol[15][34]='°';
   sol[14][34]='°';
   sol[13][34]='°';
   sol[12][34]='°';
   sol[11][34]='°';
   sol[11][33]='°';
   sol[11][32]='°';
   sol[11][31]='°';
   sol[11][30]='°';
   sol[10][30]='°';
   sol[9][30]='°';
   sol[8][30]='°';
   sol[8][29]='°';
   sol[7][29]='°';
   sol[6][29]='°';
   sol[5][29]='°';
   sol[4][29]='°';
   sol[4][30]='°';
   sol[4][31]='°';
   sol[4][32]='°';
   sol[4][33]='°';
   sol[3][33]='°';
   sol[3][34]='°';
   sol[2][34]='°';
   scrivi_sol();
}

void ponte2()
{
   sol[15][34]='°';
   sol[14][34]='°';
   sol[13][34]='°';
   sol[12][34]='°';
   sol[11][34]='°';
   sol[11][33]='°';
   sol[11][32]='°';
   sol[11][31]='°';
   sol[11][30]='°';
   sol[11][29]='°';
   sol[11][28]='°';
   sol[11][27]='°';
   sol[11][26]='°';
   sol[11][25]='°';
   sol[10][25]='°';
   sol[10][24]='°';
   sol[10][23]='°';
   sol[9][23]='°';
   sol[8][23]='°';
   sol[8][22]='°';
   sol[7][22]='°';
   sol[6][22]='°';
   sol[6][23]='°';
   sol[6][24]='°';
   sol[6][25]='°';
   sol[6][26]='°';
   sol[6][27]='°';
   sol[6][28]='°';
   sol[6][29]='°';
   sol[6][30]='°';
   sol[6][31]='°';
   sol[6][32]='°';
   sol[6][33]='°';
   sol[6][34]='°';
   sol[6][35]='°';
   sol[6][36]='°';
   sol[6][37]='°';
   sol[5][37]='°';
   sol[4][37]='°';
   sol[4][36]='°';
   sol[4][35]='°';
   sol[4][34]='°';
   sol[3][34]='°';
   sol[2][34]='°';
   scrivi_sol();
}

void ponte3()
{
   sol[15][34]='°';
   sol[14][34]='°';
   sol[13][34]='°';
   sol[12][34]='°';
   sol[11][34]='°';
   sol[11][35]='°';
   sol[11][36]='°';
   sol[11][37]='°';
   sol[10][37]='°';
   sol[10][38]='°';
   sol[9][38]='°';
   sol[9][39]='°';
   sol[8][39]='°';
   sol[7][39]='°';
   sol[6][39]='°';
   sol[6][38]='°';
   sol[6][37]='°';
   sol[6][36]='°';
   sol[6][35]='°';
   sol[6][34]='°';
   sol[6][33]='°';
   sol[7][33]='°';
   sol[8][33]='°';
   sol[8][32]='°';
   sol[8][31]='°';
   sol[8][30]='°';
   sol[8][29]='°';
   sol[8][28]='°';
   sol[8][27]='°';
   sol[7][27]='°';
   sol[6][27]='°';
   sol[5][27]='°';
   sol[5][26]='°';
   sol[4][26]='°';
   sol[4][25]='°';
   sol[4][24]='°';
   sol[5][24]='°';
   sol[6][24]='°';
   sol[7][24]='°';
   sol[8][24]='°';
   sol[8][23]='°';
   sol[8][22]='°';
   sol[7][22]='°';
   sol[6][22]='°';
   sol[5][22]='°';
   sol[4][22]='°';
   sol[3][22]='°';
   sol[2][22]='°';
   sol[2][23]='°';
   sol[2][24]='°';
   sol[2][25]='°';
   sol[2][26]='°';
   sol[2][27]='°';
   sol[2][28]='°';
   sol[2][29]='°';
   sol[2][30]='°';
   sol[3][30]='°';
   sol[4][30]='°';
   sol[4][31]='°';
   sol[4][32]='°';
   sol[3][32]='°';
   sol[3][33]='°';
   sol[3][34]='°';
   sol[2][34]='°';
   scrivi_sol();
}

void gioco(int scelta)
{
   int i=16, j=34, vite=3, ris, punteggio=0;
   char rana='Ï';
   string nome, data;
   fstream fd;
   sol[i][j]=rana;
   sol[1][34]='F';
   sol[1][33]='|';
   sol[1][35]='|';
   matr[i][j]=rana;
   matr[1][34]='F';
   matr[1][33]='|';
   matr[1][35]='|';

   if(scelta==1) ponte1();
   if(scelta==2) ponte2();
   if(scelta==3) ponte3();

   if(scelta==1) cout<<"Soluzione modalita' Semplice" <<endl<<endl;
   if(scelta==2) cout<<"Soluzione modalita' Normale" <<endl<<endl;
   if(scelta==3) cout<<"Soluzione modalita' Incubo" <<endl<<endl;
   if(scelta==1) _sleep(3500);
   if(scelta==2) _sleep(4500);
   if(scelta==3) _sleep(5500);
   system("cls");
   if(scelta==1) cout<<"Modalita' in corso: Semplice "<<"    Vite: "<<vite<<endl<<endl;
   if(scelta==2) cout<<"Modalita' in corso: Normale "<<"    Vite: "<<vite<<endl<<endl;
   if(scelta==3) cout<<"Modalita' in corso: Incubo "<<"    Vite: "<<vite<<endl<<endl;
   sndPlaySound("start.wav", SND_ASYNC);
   scrivi_mappa();
   cout<<endl<<endl<<"Premi ESC per uscire"<<endl;
   do
   {
      ris=getch();
      if(ris==119) ///sopra
      {
         if(i>1) ///controllo se non si trova in cima
         {
            if(matr[i-1][j]!='!') ///controllo se nella cella dopo non sia contenuto un !
            {
                matr[i-1][j]=rana; ///mi muovo
                matr[i][j]='°';
                punteggio=punteggio+5; ///mi muovo
                if(i<12&&sol[i-1][j]==' '||sol[i-1][j]=='~') ///se è uscito dal ponte iniziale e calpesta spazi o ~ perde la vita
                {
                    vite--;
                    matr[i-1][j]='!'; ///metto il ! dove c'è stato  l'errore
                    sndPlaySound("error.wav", SND_ASYNC);
                    matr[16][34]=rana; ///rimetto la rana nella posizione originale
                    punteggio=punteggio+2;
                    i=17; ///rendo la i uguale all'inizio
                    j=34; ///rendo la j uguale all'inizio
                }
                i--;
                if (matr[1][34]==rana)
                {
                    cout<<endl<<endl<<endl<<endl<<"                                                                                                HAI VINTO!!!"<<endl;
                    sndPlaySound("win.wav", SND_SYNC);
                    break;
                }
            }
            system("cls");
            if(scelta==1) cout<<endl<<" Modalita' in corso: Semplice "<<"    Vite: "<<vite<<endl<<endl;
            if(scelta==2) cout<<endl<<" Modalita' in corso: Normale "<<"    Vite: "<<vite<<endl<<endl;
            if(scelta==3) cout<<endl<<" Modalita' in corso: Incubo "<<"    Vite: "<<vite<<endl<<endl;
            cout<<endl<<" Punteggio: "<<punteggio<<endl;
            scrivi_mappa();
            cout<<endl<<endl<<"Premi ESC per uscire"<<endl;
         }
      }
      if(ris==115) ///sotto
      {
            if(i<16) ///controllo se non si trova in basso
            {
               if(matr[i+1][j]!='!'&&matr[i+1][j]!='-') ///controllo se nella cella dopo non sia contenuto un !
               {
                  matr[i+1][j]=rana; ///mi muovo
                  matr[i][j]='°'; ///mi muovo
                  punteggio=punteggio+5;
                  if(i<12&&sol[i+1][j]==' '||sol[i+1][j]=='~') ///se è uscito dal ponte iniziale e calpesta spazi o ~ perde la vita
                  {
                     vite--;
                     matr[i+1][j]='!'; ///metto il ! dove c'è stato  l'errore
                     sndPlaySound("error.wav", SND_ASYNC);
                     matr[16][34]=rana; ///rimetto la rana nella posizione originale
                     punteggio=punteggio+2;
                     i=15; ///rendo la i uguale all'inizio
                     j=34; ///rendo la j uguale all'inizio
                  }
                  i++;
               }
               system("cls");
               if(scelta==1) cout<<"Modalita' in corso: Semplice "<<"    Vite: "<<vite<<endl<<endl;
               if(scelta==2) cout<<"Modalita' in corso: Normale "<<"    Vite: "<<vite<<endl<<endl;
               if(scelta==3) cout<<"Modalita' in corso: Incubo "<<"    Vite: "<<vite<<endl<<endl;
               cout<<endl<<" Punteggio: "<<punteggio<<endl;
               scrivi_mappa();
               cout<<endl<<endl<<"Premi ESC per uscire"<<endl;
            }
      }
      if(ris==97&&matr[i][j-2]!='|'&&matr[i][j-2]!='-') ///sinistra
      {
         if(j>1) ///controllo se non si trova all'estrema sinistra
         {
            if(matr[i][j-1]!='!') ///controllo se nella cella dopo non sia contenuto un !
            {
               matr[i][j-1]=rana; ///mi muovo
               matr[i][j]='°'; ///mi muovo
               punteggio=punteggio+5;
               if(sol[i][j-1]==' '||sol[i][j-1]=='~') ///se è uscito dal ponte iniziale e calpesta spazi o ~ perde la vita
               {
                   vite--;
                   matr[i][j-1]='!'; ///metto il ! dove c'è stato  l'errore
                   sndPlaySound("error.wav", SND_ASYNC);
                   matr[16][34]=rana; ///rimetto la rana nella posizione originale
                   punteggio=punteggio+2;
                   i=16; ///rendo la i uguale all'inizio
                   j=35; ///rendo la j uguale all'inizio
               }
               j--;
            }
            system("cls");
            if(scelta==1) cout<<"Modalita' in corso: Semplice "<<"    Vite: "<<vite<<endl<<endl;
            if(scelta==2) cout<<"Modalita' in corso: Normale "<<"    Vite: "<<vite<<endl<<endl;
            if(scelta==3) cout<<"Modalita' in corso: Incubo "<<"    Vite: "<<vite<<endl<<endl;
            cout<<endl<<" Punteggio: "<<punteggio<<endl;
            scrivi_mappa();
            cout<<endl<<endl<<"Premi ESC per uscire"<<endl;
         }
      }
      if(ris==100&matr[i][j+2]!='|'&&matr[i][j+2]!='-') ///destra
      {
         if(j<68) ///controllo se non si trova all'estrema destra
         {
            if(matr[i][j-1]!='!') ///controllo se nella cella dopo non sia contenuto un !
            {
               matr[i][j+1]= matr[i][j]; ///mi muovo
               matr[i][j]='°'; ///mi muovo
               punteggio=punteggio+5;
               if(sol[i][j+1]==' '||sol[i][j+1]=='~') ///se è uscito dal ponte iniziale e calpesta spazi o ~ perde la vita
               {
                  vite--;
                  matr[i][j+1]='!'; ///metto il ! dove c'è stato  l'errore
                  sndPlaySound("error.wav", SND_ASYNC);
                  matr[16][34]=rana; ///rimetto la rana nella posizione originale
                  punteggio=punteggio+2;
                  i=16; ///rendo la i uguale all'inizio
                  j=33; ///rendo la j uguale all'inizio
               }
               j++;
            }
            system("cls");
            if(scelta==1) cout<<"Modalita' in corso: Semplice "<<"    Vite: "<<vite<<endl<<endl;
            if(scelta==2) cout<<"Modalita' in corso: Normale "<<"    Vite: "<<vite<<endl<<endl;
            if(scelta==3) cout<<"Modalita' in corso: Incubo "<<"    Vite: "<<vite<<endl<<endl;
            cout<<endl<<" Punteggio: "<<punteggio<<endl;
            scrivi_mappa();
            cout<<endl<<endl<<"Premi ESC per uscire"<<endl;
         }
      }
      if(vite==0)
      {
         cout<<endl<<endl<<endl<<endl<<"                                                                                                GAME OVER!!!"<<endl<<endl;
         sndPlaySound("gameover.wav", SND_SYNC);
         break;
      }
   }while(ris!=27); ///fino a quando non si preme ESC
   cout<<endl<<endl<<endl<<endl;
   system("pause");
   system("cls");
   fd.open("partite.txt", ios::app);
   if(fd.is_open())
   {
       cout<<"Inserisci il nome del giocatore: ";
       cin>>nome;
       cout<<"Inserisci la data in cui hai giocato (gg/mm/aaaa): ";
       cin>>data;
       fd<<"Giocatore: "<<nome<<endl;
       if(scelta==1) fd<<"Modalita' Facile"<<endl;
       if(scelta==2) fd<<"Modalita' Normale"<<endl;
       if(scelta==3) fd<<"Modalita' Incubo"<<endl;
       fd<<"Vite rimanenti: "<<vite<<endl;
       if (vite==0) fd<<"Partita Persa"<<endl;
       else fd<<"Partita Vinta"<<endl;
       fd<<"Punteggio: "<<punteggio<<endl;
       fd<<"Data: "<<data<<endl;
       fd<<"------------------------------------------------------"<<endl;
   }
   else
   {
      cout<<"Errore nell'apertura del file partite.txt"<<endl;
      exit (1);
   }
   cout<<endl<<endl;
}

void titolo()
{
    system("color A0");
    cout<<"                                       *                                                       *                                                           *"<<endl;
    cout<<"                                     *   *                                                   *   *                                                       *   *"<<endl;
    cout<<"                                * * *     * * *                                         * * *     * * *                                             * * *     * * *"<<endl;
    cout<<"                                 *           *                                            *          *                                                *          *"<<endl;
    cout<<"                                   *       *                                                *      *                                                   *       *"<<endl;
    cout<<"                                 *           *                                            *          *                                               *           *"<<endl;
    cout<<"                               * * *       * * *                                        * * *      * * *                                           * * *       * * *"<<endl;
    cout<<"                                     *   *                                                   *   *                                                      *     *"<<endl;
    cout<<"                                       *                                                       *                                                           * "<<endl;
    cout<<endl<<endl;
    cout<<"                                                ******************      ****************      **************     *************     ****       **** "<<endl;
    cout<<"                                               *                  *    *                *    *              *   *     ***     *    *    *   *    * "<<endl;
    cout<<"                                               *     *************     *                *    *     *****    *   *    *   *    *     *    * *    *  "<<endl;
    cout<<"                                               *    *                  *       *********     *     *   *    *   *    *   *    *      *    *    *   "<<endl;
    cout<<"                                               *     *************     *      *              *      ***     *   *     ***     *       *       *    "<<endl;
    cout<<"                                               *                  *    *      *              *              *   *    *      **         *     *     "<<endl;
    cout<<"                                                *************     *    *      *              *     ****     *   *   *  *   *           *     *     "<<endl;
    cout<<"                                                             *    *    *       *********     *    *    *    *   *   *   *   *          *     *     "<<endl;
    cout<<"                                                *************     *    *                *    *    *    *    *   *   *    *   *         *     *     "<<endl;
    cout<<"                                               *                  *    *                *    *    *    *    *   *   *     *   *        *     *     "<<endl;
    cout<<"                                                ******************      ****************      ****      ****     ***       *****        *****      "<<endl;
    cout<<endl;
    cout<<"                                          ***********      *************      ******      ***********          *****************       *************   "<<endl;
    cout<<"                                         *    * *    *    *     ***    *     *      *    *            *       *                 *     *             *  "<<endl;
    cout<<"                                         *  *     *  *    *    *   *   *     *      *    *             *      *                 *     *   **********   "<<endl;
    cout<<"                                         *  *     *  *    *    *   *   *     *      *    *    ****      *     *     ************      *    *           "<<endl;
    cout<<"                                         *    * *    *    *     ***    *     *      *    *   *     *     *    *    *                  *     ********   "<<endl;
    cout<<"                                         * **********     *    *      *      *      *    *   *      *     *   *   *                   *             *  "<<endl;
    cout<<"                                         *    * *    *    *   *  *   *       *      *    *   *      *     *   *   *   **********      *     ********   "<<endl;
    cout<<"                                         *  *     *   *   *   *   *   *      *      *    *    *****      *    *   *    *        *     *    *           "<<endl;
    cout<<"                                         *  *     *   *   *   *    *   *     *      *    *              *      *   *******    *       *     ********   "<<endl;
    cout<<"                                         *    * *     *   *   *     *   *    *      *    *            *         *            *        *             *  "<<endl;
    cout<<"                                          ************     ***       *****    ******      ***********            ************          **************  "<<endl;
}

void menu()
{
    cout<<endl<<endl<<endl;
    cout<<"                                                                                             MENU':"<<endl<<endl;
    cout<<"                                                                                    1) Nuova Partita"<<endl;
    cout<<"                                                                                    2) Vedi i risultati delle partite recenti"<<endl;
    cout<<"                                                                                    3) Leggi le istruzioni"<<endl;
    cout<<"                                                                                    4) Esci"<<endl;
}
 void caricamento()
 {
    system("color A0");
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                                                                 /                                                                /                  "<<endl;
    cout<<"                                                                                /_______________________________________________________________ /                   "<<endl;
    cout<<"                                                                               /                                                                /                    "<<endl;
    cout<<"                                                                              /_______________________________________________________________ /                     "<<endl;
    cout<<"                                                                  ******************      ****************      **************     *************     ****       **** "<<endl;
    cout<<"                                                                 *                  *    *                *    *              *   *     ***     *    *    *   *    * "<<endl;
    cout<<"                                                                 *     *************_____*                *____*     *****    *___*    *   *    *     *    * *    *  "<<endl;
    cout<<"                                                                 *    *   /              *       *********     *     *   *    *   *    *   *    *      *    *    *   "<<endl;
    cout<<"                                                                 *     *************     *      *              *      ***     *   *     ***     *       *       *    "<<endl;
    cout<<"                                                                 *                  *____*      *______________*              *___*    *      **         *     *     "<<endl;
    cout<<"                                                                  *************     *    *      *              *     ****     *   *   *  *   *           *     *     "<<endl;
    cout<<"                                                                       /       *    *    *       *********     *    *    *    *   *   * / *   *          *     *     "<<endl;
    cout<<"                                                                  *************     *____*                *____*    *____*    *___*   */   *   *         *     *     "<<endl;
    cout<<"                                                                 *                  *    *                *    *    *    *    *   *   *     *   *        *     *     "<<endl;
    cout<<"                                                                  ******************      ****************      ****      ****     ***       *****        *****      "<<endl;
    cout<<"                                                                    / _____________________________________________________________ /                                     "<<endl;
    cout<<"                                                             ***********      *************      ******      ***********           *****************       *************   "<<endl;
    cout<<"                                                            *    * *    *    *     ***    *     *      *    *            *        *                 *     *             *  "<<endl;
    cout<<"                                                            *  *     *  *____*    *   *   *_____*      *____*             *_____  *                 *     *   **********   "<<endl;
    cout<<"                                                            *  *     *  *    *    *   *   *     *      *    *    ****      *     /*     ************      *    *           "<<endl;
    cout<<"                                                            *    * *    *    *     ***    *     *      *    *   *     *     *   / *    *                  *     ********   "<<endl;
    cout<<"                                                            * **********_____*    *      *______*      *____*   *______*     * /  *   *                   *             *  "<<endl;
    cout<<"                                                            *    * *    *    *   *  *   *       *      *    *   *      *     */   *   *   **********      *     ********   "<<endl;
    cout<<"                                                            *  *     *   *   *   *   *   *      *      *    *    *****      */    *   *    *        *     *    *           "<<endl;
    cout<<"                                                            *  *     *   *   *   *    *   *     *      *    *              */      *   *******    *       *     ********   "<<endl;
    cout<<"                                                           /*    * *     *__ *   *_____*   * ___*      *____*            * /       *            *         *             *  "<<endl;
    cout<<"                                                          /  ************     ***       *****    ******      ***********  /          ************          **************  "<<endl;
    cout<<"                                                         /                                                               /                                                "<<endl;
    cout<<"                                                        / ____________________________________________________________  /                                                 "<<endl;
    cout<<"                                                       /                                                               /                                                  "<<endl;
    cout<<"                                                      /                                                               /                                                   "<<endl;
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"                                                                                                           LOADING..."<<endl;
 }
