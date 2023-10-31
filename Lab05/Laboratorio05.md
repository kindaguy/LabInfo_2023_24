# Laboratorio 5: ciclo caricamento dati, compilazione separata, uso files.

# Esercizio 1
Implementare gli esercizi risolti in classe durante l'ultima lezione.
1. Conta pari-dispari.
2. Determina esistenza sequenza >10.
3. Determina mediana (implementare ordinamento)...

# Esercizio 2
Facciamo ordine: 

1. Recuperate tutte le funzioni che calcolano statistiche (media, deviazione standard, massimo, minimo di un array di dati) e usatele per popolare la libreria __libStatistica__ (__libStatistica.C/libStatistica.h__).

2. Recuperate tutte le funzioni che gestiscono il contenuto di un array di dati e inseritele nella libreria __libArray__ (__libArray.C/libArray.h__).

Ricordate: il file __.h__ conterrà la dichiarazione di tutte le funzioni della libreria, insieme alla documentazione di uso (descrizione relazione input/output, significato dei parameteri); il file __.C__ conterrà  la definizione delle funzioni dichiarate nel __.h__. Il file __.C__ inizia con 

__#include "nomeLib.h"__ 



## Esercizio 3 (Ciclo Spoletini)

Il file __dati.dat__ contiene un numero non precisato di dati razionali (__float__). Scrivere un programma che determini il numero di dati presenti su file implementando il _ciclo Spoletini_. ATTENZIONE: il programma non dovrà caricare i dati da nessuna parte, solo deteminare il numero di valori scritti su file (sono 100...ed è lo stesso file di dati da cui caricavate i dati la volta scorsa...).

Ricordatevi che uno stream va chiuso quando si è finito di usarlo (con l'istruzione __.close()__).

## Esercizio 4
Modificate la soluzione dell'Esercizio 1 in modo tale che i dati scritti nel file __dati.dat__ vengano copiati, uno alla volta, nel file __dati_copia.dat__. A tal file usare un __ofstream__. Ricordate che spazi e "a capo" dovete gestirli voi...
