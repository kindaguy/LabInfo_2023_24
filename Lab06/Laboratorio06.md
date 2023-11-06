# Laboratorio 6: conteggio e caricamento dati "eterogenei" da file. Formazione librerie

# Esercizio 1
Il file __dati_header.dat__ è così formato:

- Il primo valore è un intero che indica il numero __N__ di dati (razionali, in singola precisione) che seguono. È garantito che __N >=1__.
- __N__ dati (__float__).

Scrivere un programma che:

1. Carichi i dati presenti sul file in un array di __float__. È GARANTITO che il numero di dati presenti sul file è al massimo 150: usare una COSTANTE (tramite direttiva __#define__) per dimensionare l'array. Notate che, una volta letto il primo valore registrato sul file, il numero di dati è noto, e quindi non è necessario contare i dati.
2. Ordini l'array usando l'algoritmo __selectionSort__, ovvero quello che sposta prima in testa all'array l'elemento più piccolo, in seconda posizione il secondo elemento più piccolo ecc....
3. Determini il minimo, il massimo, la mediana, la media e la deviazione standard dei dati.

I primi 3 e gli ultimi 3 valori dell'array ordinato, insieme a tutte le statistiche determinate al punto 3, devono essere stampati a video e REGISTRATI sul file __risultati.dat__.


# Esercizio 2

Il file __sfere.dat__ contiene un numero non precisato (ma minore di __NN  = 150__) di coppie della forma $(\text{dato}, \text{colore})$, dove $\text{dato}$ è un valore razionale (__float__) e colore è un singolo carattere (__char__), nell'insieme $\{'b','g','r'\}$. Il file descrive un insieme di sfere di diverso diametro nominale, colorate di colore diverso (blu, giallo, rosso) per permettere ad un addetto di distinguerle facilmente. Il valore __float__ registrato sul file corrisponde al diametro effettivo della sfera (che può differire dal diametro nominale a causa di piccole imperfezioni del processo di produzione).

Contare e caricare i dati dal file in due vettori, che chiameremo

__float vdiams[NN]__
__char vcols[NN]__

Determinare il diametro medio e la deviazione standard delle palline blu, gialle e rosse (dovete ottenere 3 valori medi e 3 deviazioni standard).

AVANZATO: ordinare i due vettori dei dati in _ordine di colore crescente_. A tal fine considerare che 

- $'b'<'g'<'r'$: i caratteri sono ordinati (ordine lessicografico...e in fondo sono numeri (codifica ASCII)).
- i due vettori sono "correlati": la sfera $i$-esima è descritta dall'$(i-1)$-esimo elemento del vettore __vdiams__ e dall'$(i-1)$-esimo elemento del vettore __vcols__. Quindi se, nel pocesso di ordinamento, l'elemento $k$-esimo di __vcols__ viene spostato in posizione $j$, lo stesso spostamento deve essere operato sul vettore __vdiams__.


# Esercizio 3 (da set esercizi settimana 5):

Facciamo ordine: 

1. Recuperate tutte le funzioni che calcolano statistiche (media, deviazione standard, massimo, minimo di un array di dati) e usatele per popolare la libreria __libStatistica__ (__libStatistica.C/libStatistica.h__).

2. Recuperate tutte le funzioni che gestiscono il contenuto di un array di dati e inseritele nella libreria __libArray__ (__libArray.C/libArray.h__).

Ricordate: il file __.h__ conterrà la dichiarazione di tutte le funzioni della libreria, insieme alla documentazione di uso (descrizione relazione input/output, significato dei parameteri); il file __.C__ conterrà  la definizione delle funzioni dichiarate nel __.h__. Il file __.C__ inizia con 

__#include "nomeLib.h"__ 

