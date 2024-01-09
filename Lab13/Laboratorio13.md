# Laboratorio 13: Svolgimento tema d'esame

Risolviamo insieme il tema d'esame della prova di laboratorio del 29 gennaio 2019. Nel costruire la soluzione, metteremo in evidenza quelle che sono le necessità tipiche di "molti" dei temi d'esame proposti e prepareremo dei template di soluzione, che possano essere "riciclati", con opportune modifiche, in altri esercizi/temi.

Nella cartella troverete sia il testo della prova che i file di dati necessari.

## Esercizio 1
Predisponete una cartella di nome __Cognome_matricola__ (ad esempio, __Tamascelli_16379__). Copiare i file __sfere.dat__ e __tolleranze.dat__, presenti nella cartella __Lab12__ in questa cartella. Aprite la cartella in VS Code, in modo da visualizzare il suo contenuto.

## Esercizio 2
Copiate la cartella creata nell'Esercizio 1 nella cartella __/home/comune/20240109_ProvaProva__  attraverso il comando __cp__. Per chi fosse "arrugginito" sui comandi basilari di shell, ricordiamo che, per effettuare tale copia, serve:
- Collocare la shell nella cartella che contiene la cartella da copiare.
- Accertarsi che la cartella da copiare sia presente visualizzando il contenuto della cartella corrente tramite il comando __ls__.
- Effettuare la copia della cartella

__cp -r Cognome_Matricola /home/comune/20240109_ProvaProva__

Ovviamente dovete sostiuire a __Cognome_Matricola__ il nome della cartella che avete creato nell'Esercizio 1.


A questo punto verificare che la cartella sia stata correttamente copiata ovvero:
- portatevi nella cartella di destinazione

__cd /home/comune/20240109_ProvaProva__

- Lanciate il comando __ls__ e sinceratevi che la vostra cartella sia presente in elenco.

ATTENZIONE: essere in grado di copiare una cartella o file tramite comandi di shell è un'abilità necessaria, e non sufficiente, al superamento della prova d'esame. Considerate che durante l'esame non sarà fornito alcun aiuto per il completamento di questa, elementare, operazione.

# Esercizio 3

Da qui in avanti ci riferiremo alla cartella __Cognome_matricola__ come alla _cartella di lavoro_.


Il testo richiede di usare una t-upla (__struct__) __sfera__. Create, nella cartella di lavoro, un file __sfera.h__ dove:

- definite la t-upla __sfera__ come prescritto nel testo d'esame.
- dichiarate le  funzioni basilari per la lettura (da stream) di una singola sfera e per la stampa (a video e su file) della descrizione di una sfera.

Create, sempre nella cartella di lavoro, un file __sfera.C__ dove implementate le funzioni di lettura/scrittura di una sfera dichiarate nel file __sfera.h__.

Verificate il funzionamento delle funzioni. A questo scopo dovrete scrivere un programma (con __main__) che richiami le funzioni. In questa fase è opportuno cominciare a definire un __makefile__ che vi consenta di compilare ed eseguire il vostro programma in modo "agile".

# Esercizio 4

Implementiamo il Punto 1 del tema, ovvero:
1. Carichiamo le sfere descritte nel file __sfera.dat__ in un vettore di __sfera__ allocato dinamicamente.
2. Contiamo il numero di sfere complessivo e per colore.
3. Completiamo la descrizione delle sfere aggiungendo le specifiche di diametro nominale e tolleranza fornite nel file __tolleranze.dat__.

NOTA: il file __tolleranze.dat__ contiene 3 righe. Ciascuna riga specifica il diametro nominale e la tolleranza per uno specifico colore. In questo caso non è necessario "contare" e poi allocare. Ci sono diversi modi di procedere. Noi ne implementeremo uno, ma altre soluzioni sono possibili.

# Esercizio 5

A questo punto possiamo procedere con il completamento dei campi delle sfere, come richiesto nel Punto 2 del tema. 

# Esercizio 6
Il Punto 3 del tema chiede di ordinare il vettore di sfere in ordine di colore crescente. Il campo __col__ è di tipo __char__. Come ben noto i __char__ sono "moralmente" valori interi positivi rappresentati su 8 bit, e quindi ordinati. In particolare __'b' < 'g' < 'r'__. Possiamo quindi usare uno qualsiasi degli algoritmi di ordinamento nella nostra libreria, modificando solamente il tipo del vettore da ordinare e  la chiave di ordinamento.

# Esercizio 7

Procediamo con la soluzione del Punto 4. Si tratta di eliminare le sfere blu "difettate". L'operazione di eliminazione di un elemento da un vettore è nota, e abbiamo visto diverse possibili soluzioni (swap e right-shift). Prestate solo attenzione al fatto che SOLO il sottovettore delle sfere blu va considerato in questo passo, quindi il vettore su cui lavorare non è l'intero vettore delle sfere. Alternativamente, possiamo creare un nuovo vettore contenente solo le sfere blu, e lavorare su quello. Entrambi gli approcci sono validi. Noi ne sceglieremo uno.

ATTENZIONE: ignorate il Punto 5 del tema d'esame: nel 2019 il programma del corso includeva l'uso di alcune istruzioni della libreria RooT (una cosa scritta da fisici, e quindi poco affidabile ;-) ....

# Esercizio 8

La consegna dell'esame prevede di copiare la cartella di lavoro in una cartella specifica. La cartella di lavoro dovrà includere:

- tutti i file __.C__ (__.cpp__ o __.cxx__) e __.h__ necessari alla generazione del codice eseguibile.
- un __makefile__ che consenta di compilare ed eseguire il programma tramite i comandi __make compila__ e __make esegui__
- i file di dati e il file __risultati.dat__ dove il programma eseguibile avrà stampato quanto richiesto.

Verificate che la cartella di lavoro contenga tutto il necessario, verificate che la compilazione e l'esecuzione vadano a buon fine, cancellate tutti i __.o__ e __.x__  e POI copiate la cartella di lavoro nella cartella di destinazione (vedi Esercizio 2).

ATTENZIONE: per la copia non provate ad usare il comando scp indicato nel testo del tema: con le nuove configurazioni di laboratorio la copia via ssh da lab a lab non funziona più...