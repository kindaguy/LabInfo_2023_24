# Laboratorio 11: operazioni array: resize, ricerca, ricerca binaria. Make, makefile e dintorni. Regressione.

## Esercizio 1
Arricchiamo la nostra collezione di operazioni su array. Lavoreremo su vettori di interi, ma ricordatevi di implementare le stesse operazioni per diversi tipi.

1. Definire le funzioni 

__int resizeMyArray(myArrayInt * myA, int new Dim)__ 
__int resizeMyArray(myArrayInt & myA, int new Dim)__ 

che, preso in ingresso l'indirizzo di un __myArrayInt__ e una nuova dimensione __int newDim__, ridimensionino l'array alla nuova dimensione indicata. In particolare, sia __size__ la dimensione dell'array da ridimensionare. Distinguiamo 2 casi: 

- se __size__ < __newSize__, ovvero stiamo allargando il vettore. Allora tutti gli elementi del vettore originale devono essere ricopiati nel nuovo, più grande.

- se __size__ > __newSize__, ovvero stiamo restringendo il vettore, allora nel nuovo vettore dovremo copiare solo i primi __newSize__ elementi.

ATTENZIONE: il vettore che viene ridimensionato potrebbe contenere un numero __used__ di elementi diverso da __size__ (ovvero potrebbe non essere saturo). Non curiamoci di questo dettaglio (che potrebbe, in generale, portare ad una ottimizzazione) ma PRESTIAMO ATTENZIONE ad aggiornare, se necessario, il valore di __used__ nel nuovo vettore.

Le funzioni, oltre a "restituire"  il myArrrayInt opportunamente allargato (per "side effect"), dovranno restituire il valore 0 se l'operazione è andata a buon fine, -1 se invece qualcosa è andato storto (per esempio allocazione nuovo array in memoria).

SUGGERIMENTO:  la funzione __memcpy__  ha signature
__void * memcpy ( void * destination, const void * source, size_t num );__
e si trova nella libreria __\<cstring\>__. Trovate informazioni più dettagliate al link https://cplusplus.com/reference/cstring/memcpy/
Provate ad usarla per fare il copia-incolla in modo intelligente....



## Esercizio 2

Sia dato un vettore di interi, caricato con i dati contenuti nel file __interi.dat__, già usato nel Laboratorio 8 e qui riportato per vostra convenienza.

Modificare le funzioni (vedi Esercizio 6 Laboratorio 9 e soluzione proposta (__solEs6.C__ e funzioni libreria connesse)): 

__int caricaMyArrayFile(char nomefile[], myArrayInt& rMyArray);__
__int caricaMyArrayFile(char nomefile[], myArrayInt *pMyArray);__

in modo tale che il caricamento dei dati da file avvenga con _un solo ciclo di lettura da file_. Strategia: iniziare usando un vettore di, per esempio, 20 elementi interi da allargare, quando necessario, aggiungendo di volta in volta 20 posizioni....(vedi Esercizio 1).

## Esercizio 3

Scrivere una funzione 

__int ricerca(myArrayInt v, int chiave)__

che, preso in ingresso un array di interi e una chiave (valore intero) da ricercare, restituisca la posizione (di una istanza) dell'elemento ricercato se tale elemento c'è, -1 altrimenti.


## Esercizio 4: Regressione
Scrivere un programma che, caricato un vettore di __puntoR2__ dal file __rilevazioni.dat__ generato nell'Esercizio 4 della settimana scorsa (Laboratorio 10), in cui si assume un modello lineare

$f(x) = m x + q$

stimi i parametri di regressione usando gli stimatori


$\widehat{m} = \frac{\sum_{j=1}^n (t_i - \bar{t})(x_i - \bar{x} )}{\sum_{j=1}^n (t_i - \bar{t})^2}$

e

$\widehat{q} = \bar{x} - \widehat{m}\bar{t}$,

dove $\bar{a}$ indica la media aritmetica di $a$.

Determinare, e stampare a video, il valore medio e lo scarto quadratico medio degli scarti dei valori reali (posizioni rilevate) rispetto alle posizioni previste dalla regressione lineare. 

## Esercizio 5 (Avanzato)

Supponiamo adesso che l'array su cui effettuare la ricerca sia ordinato in ordine non decrescente, ovvero 

$v_1 \leq v_2 \leq \ldots \leq v_n$.

Progettare un algoritmo di ricerca di una chiave intera che sfrutti la struttura dell'array. 

NOTA: sia data la funzione

__int ricercaBinaria(int v[], int inizio, int fine, int chiave)__

che cerca l'elemento in un array __v__ all'interno del range di indici __[inizio,fine]__. 

Sia $m = \lfloor \frac{\textbf{inizio}+\textbf{fine}}{2} \rfloor$. Ora:
- se $v[m] == \text{chiave}$ restituisco $m$;
- se $v[m] \neq \text{chiave}$ e $\textbf{inizio} \geq \textbf{fine}$, restituisco -1;
- se $v[m] > \text{chiave}$, continuo a cercare nel sottovettore $[\textbf{inizio},m-1]$, ovvero

 __return ricercaBinaria(v,inizio, m+1)__

- se $v[m] < \text{chiave}$, continuo a cercare nel sottovettore $[m+1,\textbf{fine}]$, ovvero 
 __return ricercaBinaria(v,m+1, fine)__
