# Laboratorio 10: Metodi Monte Carlo, Simulazione semplice esperimento e ancora sul caricamento dati da file.

## Esercizio 1

Creiamo la nostra libreria per la generazione di numeri casuali. Creati, e salvati in modo opportuno, i file __libCaso.C__ e __libCaso.h__, dichiarare e definire le seguenti funzioni:

- __double randUniforme(double minimo, double massimo)__: restituisce un valore estratto uniformemente a caso in $[\text{minimo},\text{massimo}]$.

- __double randGaussiano(double media, double stdVar)__: restituisce un numero estratto a caso da una popolazione Gaussiana di media e deviazione standard assegnata usando la trasformazione di Box-Muller.

- __void impostaSeme()__: deve richiamare al suo interno __srand(time(NULL))__ per impostare il seme del generatore di numeri casuali.


## Esercizio 2
Stimiamo $\pi$ usando la tecnica Monte Carlo discussa a lezione. Supporremo che il quarto di  circonferenza (nel primo quadrante) _A_ abbia centro nel punto O=(0,0) e raggio unitario. I punti verranno invece sparati a caso nel quadrato _E_ di lato 1 con spigolo in basso a sinistra nell'origine.  Struttureremo la soluzione come segue:

1. La funzione 

__bool isInsideCircle(puntoR2 p, double r)__

 che, preso in ingresso un 
 
 __struct puntoR2{
   double x;
   double y;
 };__
 
  restituisca __true__ se il punto corrispondente cade all'interno di una circonferenza di raggio __r__ centrata nell'orgine, __false__ atrimenti. 

2. Definire una funzione 

__int countWithin(int n, double r)__

che, preso in ingresso un valore intero __n__ e un raggio __r__, estragga __n__ punti a caso nel quadrato _E_ di lato __r__ e spigolo in basso a sx nell'origine $O=(0,0)$ degli assi; la funzione deve restituire il numero di punti che cadono all'interno di una circonferenza di ragio __r__ e centro nell'origine. A tal fine, la funzione dovrà usare la funzione __isInsideCircle__ introdotta al punto precedente.

3. Definire una funzione

__double rilev(int n, double r)__

che preso in ingresso il numero di punti a caso da utilizzare, fornisca una <u>rilevazione</u> di $\pi$ usando la relazione vista a lezione. 

4. Fatto questo, scrivere un programma che fornisca una stima di $\pi$ attraverso _M=50_ rilevazioni, ciascuna delle quali usa _N=100_ punti estratti a caso. Il programma dovrà quindi calcolare la media e la varianza del campione del vettore di rilevazioni. La media del campione sarà  la nostra stima di $\pi$, la varianza invece una misura della qualità  della misura. Cosa succede alla varianza calcolata se invece di 100 punti usassimo 200,300,400,500  punti per ogni rilevazione?


## Esercizio 3
Fornire una stima Monte Carlo dell'integrale, usando, con attenzione, una delle due strategie discusse a lezione.

 ![](integrale.jpeg)
 
 usando M=20 rilevazioni ciscuna delle quali usa _k=50_ punti estratti a caso nell'intervallo [0,2]. Calcolare la stima (misura) dell'integrale (media delle _M_ misure) e la deviazione standard del campione delle misure. Cosa succede se usiamo _k=100,150,200_ punti per ogni misura? 


 ## Esercizio 4

 Scrivere una funzione

 __double rileva(double time, double x0,double v,double u)__

 che, preso in ingresso un tempo __time__ calcoli la posizione  di un punto materiale che si muova secondo la legge

 $x(t) = x0 + v t$

 a cui somma un valore casuale $\epsilon$  estratto a caso da una popolazione normale di media $\mu=0$ e deviazione standard $\sigma = 0.4$. Il valore generato sarà pertanto uguale a 

 $y(t) = x(t)+ \epsilon$.

 Fissati i valori __x0 = 2, v = 0.3, u = 0.2__, usare la funzione __rileva__ per generare 100 coppie $(t_i,y_i = y(t_i))$ con $t_i = 0.2 * i, i=0,1,\ldots,99$. Registrare le coppie generate su un file dal nome __rilevazioni.dat__. Ogni riga del file dovrà contenere una coppia $t_i$ $y_i$. 
 
 IMPAGINAZIONE: ciascun valore di una coppia deve essere registrata sul file in un campo di ampiezza 12. Usare il modificatore __setw(...)__ della libreria __iomanip__.

 ## Esercizio 5

 Definiamo una libreria per la gestione di array di punti sul piano, ovvero di 

 __struct puntoR2{
   double x;
   double y;
 };__

 (vedi Esercizio 2). A tal fine creeremo la t-upla

 __myArrayPuntoR2{
   int size;
   int used;
   puntoR2 *raw;
 };__

 Modificare la funzione 

 __myArrayInt caricaInteriFile(char nomefile[], int &errcode)__

 in modo tale che carichi il contenuto del file contenente coppie di razionali (come per esempio il file __rilevazioni.dat__) in un __myArrayPuntoR2__.

 Osserviamo quanto segue: la funzione di caricamento da file ha sempre la stessa struttura, indipendentemente dal tipo di dato che viene caricato....forse potremmo renderla il più generale possibile....

 A tal fine, potremmo definire la funzione

 __T leggiDato(ifstream& reflusso)__

 oppure

 __T leggiDato(ifstream *puflusso)__

 dove __T__, come al solito, è un segnaposto per un tipo di dato qualsiasi (anche t-upla). A questa funzione deleghiamo la lettura di un dato (eventualmente composito) da file... Le modifiche allo stream, tra cui l'avanzamento della "testina di lettura" persisteranno anche dopo la chiamata della funzione, per entrambe le segnature della funzione: notate che passiamo un reference o un puntatore.

 A questo punto la funzione di caricamento da file dovrà  essere modificata solo nella parte dove dichiariamo il tipo del dato....