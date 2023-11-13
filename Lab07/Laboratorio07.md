# Laboratorio 6: conteggio e caricamento dati "eterogenei" da file. Formazione librerie

# Esercizio 1

Scrivere una funzione __void scambia (int *p1, int *p2)__ che scambi il contenuto delle variabili "passate"  alla funzione. Scrivere anche una versione per __float__ (__void scambia(float *p1, float *p2)__) e modificale la funzione di ordinamento __selsort()__ usata nella soluzione dell'Esercizio 1, settimana 6, in modo tale che usi questa funzione di scambio invece di __void scambia(float v[], int pos1, int pos2)__.

# Esercizio 2

Il file __dati_header.dat__ è così formato:

- Il primo valore è un intero che indica il numero __N__ di dati (razionali, in singola precisione) che seguono. 
- __N__ dati (__float__).

Scrivere un programma che:

1. Una volta letto il numero __N__ di dati _allochi dinamicamente_ un vettore di __N__ elementi __float__. 

1. Carichi i dati presenti sul file in un array di __float__. 
2. Ordini l'array usando l'algoritmo __selectionSort__, ovvero quello che sposta prima in testa all'array l'elemento più piccolo, in seconda posizione il secondo elemento più piccolo ecc....
3. Determini il minimo, il massimo, la mediana, la media e la deviazione standard dei dati. Il calcolo di queste statistiche deve essere effettuato da una funzione __void calcolaStats(float v[], int ndata, float *pmin, float *pmax, float *pmediana, float *pmediam, float *pstddev)__ che "restituisce" il valore delle statistiche richieste per _side-effect_.

I primi 3 e gli ultimi 3 valori dell'array ordinato, insieme a tutte le statistiche determinate al punto 3, devono essere stampati a video e REGISTRATI sul file __risultati.dat__.

ATTENZIONE: ricordatevi di rimuovere l'array allocato dinamicamente quando questo non serve più.


# Esercizio 3

Il file __sfere.dat__ contiene un numero non precisato di coppie della forma $(\text{dato}, \text{colore})$, dove $\text{dato}$ è un valore razionale (__float__) e colore è un singolo carattere (__char__), nell'insieme $\{'b','g','r'\}$. Il file descrive un insieme di sfere di diverso diametro nominale, colorate di colore diverso (blu, giallo, rosso) per permettere ad un addetto di distinguerle facilmente. Il valore __float__ registrato sul file corrisponde al diametro effettivo della sfera (che può differire dal diametro nominale a causa di piccole imperfezioni del processo di produzione).

1. Contare e caricare i dati dal file in due vettori, allocati dinamicamente, che chiameremo __float *vdiams__ e  __char *vcols__. 
2. Determinare il diametro medio e lo scarto quadratico medio considerando tutte le sfere descritte nel file. Stampare a video il risultato.
3. Una volta determinato (e stampato a video) il numero __nrosse__ di palline "rosse", creare un vettore di dimensione __nrosse__ di valori __float__ e copiare al suo interno i diametri delle sole palline rosse. Cancellare il vettore dei diametri e quello dei cololri (__delete [] vdiams; vdiams = NULL; delete [] vcols; vcols = NULL__). 
4. Quale assegnamento ci consentirà di accedere al vettore dei dati sopravvissuto (ovvero le sole sfere rosse) usando __vdiam__?
5. Determinare e stampare a video tutte le statistiche richieste nel Punto 3 dell'esercizio precedente.


# Esercizio 4

Scrivere una funzione

__float *caricaDatiFile(char nomefile[], int *p_ndati)__

che, contati i dati presenti sul file di nome __nomefile__, carichi gli __ndati__ in un vettore di __float__ allocato dinamicamente di dimensione __ndati__. La funzione dovrà restituire l'indirizzo dell'array (ovvero l'indirizzo in cui comincia l'array allocato dinamicamente). La funzione dovrà inoltre "restituire", per side-effect, il numero di dati caricati (attraverso __p_ndata__).

1. Testare il corretto funzionamento della funzione usando il file __data.dat__ presente nella cartella.

# Esercizio 5: "home made" Istogramma
Scrivere un programma che produca un istogramma (artigianale eh...) facendo quanto segue:

1. Chiedere  all'utente di definire un intervallo $[\text{min},\text{max}]$  con $\text{min} < \text{max}$ e un numero $\text{nbins}$ di intervalli in cui dividere $[\text{min},\text{max}]$. A questo punto avremo identificato gli intervalli $[x_0 = \text{min}, x_1 = \text{min}+\delta]$, $(x_1,x_2 = \text{min}+2 \cdot \delta ]$,$\ldots$, $(x_{\text{nbins}-1},  x_N = \text{min}+ \text{nbins} \cdot \delta]$, dove
```math
\delta  = \frac{\text{max} - \text{min}}{\text{nbins}}.
```


 Notate che tutti gli intervalli, tranne il primo, sono aperti a sinistra, e che formano una partizione di $[\text{min},\text{max}]$.

2. Crei un vettore di $\text{nbins}$ interi, allocato dinamicamente e con componenti inizializzate a zero. Nel seguiro chiameremo questo array __contatori__.

A questo punto siamo pronti a riempire l'istogramma. Supponiamo di avere una $n$-upla di dati, che qui per definitezza consideremo di tipo __float__, con elementi nell'intervallo aperto $(\text{min},\text{max})$. 

3. Per ogni dato, diciamo $y_i$, individuare l'intervallo dell'istogramma in cui il dato "cade", ovvero il valore $k: x_k < y_i \leq x_{k+1}$.
ATTENZIONE: per costruzione il campione non può contenere  i valori $\text{min}$ nè $\text{max}$. 
SUGGERIMENTO: per determinare in quale intervallo cade il dato $y$ possiamo usare un contatore e un ciclo:

```c++
int shift=1;
while(shift*delta < y){
   shift++;
}
contatori[shift]++;
```

Una volta determinato il vettore dei contatori, possiamo disegnare l'istogramma come segue:
 - ogni contatore viene rappresentato come una riga di asterischi, con tanti asterischi quanto il valore del contatore.
 -si va a capo dopo ogni contatore.

 NOTA: se il campione dei dati fosse grande (e quindi gli asterischi molti), potremmo "riscalare" il numero di asterischi di un fattore costante per poter visualizzare bene la popolazione relativa di ogni bin....


