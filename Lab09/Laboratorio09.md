# Laboratorio 9: Riferimenti e t-uple (struct)

# Esercizio 1
Il file __interi.dat__ (è lo stesso del laboratorio precedente) contiene un numero non precisato di interi positivi. Scrivere una funzione 

__int * caricaInteriFile(char nomefile[], int& quanti)__

preso in ingresso il nome del file, carichi in un vettore di interi allocato dinamicamente i dati registrati sul file. La funzione deve restituire l'idirizzo dell'array allocato dinamicamente (__int *__) e il numero di interi caricati (ovvero la dimensione del vettore) per _side effect_, ovvero registrando il numero dei dati in __quanti__. In caso di errore di apertura dello stream la funzione  dovrà restituire il valore __NULL__ e registrare -1 in quanti. In caso di errore di allocazione dinamica dell'array, la funzione dovrà restituire ancora __NULL__ e registrare il valore -2 in __quanti__.

NOTA: il parametro attuale assegnato al parametro formale __quanti__ dovrà essere una variabile (di tipo __int__) della funzione chiamante  (ad esempio __main__). Se nella funzione usate __quanti__ direttamente come contatore, sinceratevi di aver fatto l'opportuna inizializzazione a zero del contatore....

# Esercizio 2
Sfruttando la funzione __isPrime__ definita nel laboratorio precedente, scrivere una funzione 

__int *selezionaPrimi(int dati[], int ndati, int& nprimi)__ 

che, preso in ingresso un vettore __dati__ di interi e il numero di dati presenti nel vettore, crei dinamicamente un nuovo vettore di interi che contiene solo i numeri primi in __dati__ e restituisca:

-il vettore contenente i primi (__int *__) e la sua dimensione (ovvero il numero di primi in __dati__) usando il riferimento  __int& nprimi__.

# Esercizio 3

Il file __sfere.dat__, già incontrato nel Laboratorio 7, contiene delle coppie _(diametro,colore)_ dove, ricordiamo, _diametro_ è un numero razionale in singola precisione (__float__) e _colore_ è un carattere. Definita la t-upla

__struct sfera{
   float diam;
   char colore;
};__

scrivere un programma che, determinato il numero di sfere descritte sul file, le carichi in un vettore di __sfera__ allocato dinamicamente di dimensione pari al numero delle sfere. Come nell'esercizio 3 del Laboratorio 7.

Il programma dovrà stampare a video il numero di sfere descritte nel file e stampare la descrizione delle prime e delle ultime 3 sfere caricate.

# Esercizio 4

Partendo da quanto fatto nell'esercizio precedente, scrivere una funzione

__sfere * caricaSfereFile(char nomefile[], int& quanti)__

che carichi le sfere descritte nel file __sfere.dat__  in un vettore di __sfera__ allocato dinamicamente e restituisca l'indirizzo del vettore allocato (__sfera *__) e il numero delle sfere caricate usando il riferimento __int& quanti__.


# Esercizio 5

Scrivere una funzione

___void scremaSfere(sfera dati[], int dim, int &nuovadim)__

che, eliminate dall'array __dati__ tutte le sfere di colore _giallo_ (__'g'__) (usando, per esempio, eliminazione via swap) "restituisca" tramite il riferimento __nuovadim__ il numero delle sfere sopravvissute alla scrematura. Stampare a video il vettore delle sfere (così da controllare di aver eliminato tutti le sfere gialle).

# Esercizio 6: struttura dati myArrayInt 
Come discusso in precedenza, per usare in modo consistente un array (di qualsiasi tipo) è necessario avere 3 informazioni:

- l'indirizzo di partenza dell'array
- la dimensione dell'array
- il numero di elementi usati dell'array

Queste 3 informazioni formano la descrizione di un singolo "oggetto" array. Oggettiviamo questo concetto, esemplificando su array di interi, definendo una t-upla

__struct myArrayInt{
   int size;  //Dimensione dell'array
   int used;  //Numero elementi array usati
   int *raw;  //Indirizzo di inizio dell'array
};__

Modificare l'Esercizio 1 scrivendo la seguente funzione

__myArrayInt caricaInteriFile(char nomefile[], int &errcode)__

che "carichi i dati contenuti nel file __interi.dat__" in un array di interi allocato dinamicamente. Tutte le informazioni sull'array (quindi dimensione, numero di elementi usati e indirizzo di partenza dell'array) dovranno essere registrati, all'interno della funzione, in una variabile locale di tipo __myAraryInt__ (chiamiamola __myArrayInt vettore__). La funzione dovrà restituire la variabile __vettore__. Siccome è possibile assegnare  una t-upla ad un'altra t-upla, il programma chiamante potrà registrare il valore restituito dalla funzione in  una sua variabile locale, ad esempio __myArrayInt dati__, in questo modo:

__dati  = caricaInteriFile("interi.dat", errore)__

dove __errore__ è una variabile di tipo __int__ che, all'uscita della funzione, conterrà:

- 0: se è andato tutto bene
- 1: se ci sono stati problemi con lo stream
- 2: se ci sono stati problemi con l'allocazione.

