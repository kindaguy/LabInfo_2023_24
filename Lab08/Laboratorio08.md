# Laboratorio 8: conteggio e caricamento dati "eterogenei" da file. Formazione librerie

# Esercizio 1: Crivello di Eratostene

Il Crivello di Eratostene è un semplice algoritmo per la determinazione di tutti i numeri primi in un intervallo assegnato $[2,N_\text{max}]$. L'idea del Crivello è quella di:

1)  Preparare un vettore di $N_\text{max}+2$ valori di tipo __bool__, inizializzati a __true__.

2) Sia $p$ il primo valore $geq 2$ marcato __true__ (all'inizio sarà proprio il valore 2). Assegnare a tutti i multipli interi di $p$ ($2p,3p,\ldots$) nel range $[2*n,N_\text{max}]$ il valore __false__: questi numeri non sono certamente primi.

3) Determinare il più piccolo intero che sia ancora marcato __true__, e usarlo come nuovo valore di $p$ al punto 2. Proseguire fino a quando non ci sono più valori di $p$ utilizzabili.

Notate che l'algoritmo usa 2 cicli annidati: in quello più esterno si determina il valore di $p$ da usare (e quel valore non va messo a __false__ perché sarà un primo) e un ciclo più interno in cui si vanno a marcare tutti i multipli di $p$ nel range indicato.

Al termine dell'operazione di marcatura, determinare il numero $n_p$ di primi nel range e salvarli in un vettore di interi di $n_p$ elementi allocato dinamicamente.

Salvare sul fine __primi.dat__, corredati da opportune didascalie:
- Il valore di  $N_\text{max}$.
- Il numero di primi nel range.
- La densità $n_p/N_\text{max}$ dei primi nel range.
- Tutti i primi determinati

# Esercizio 2

Scrivere una funzione 

__bool isPrime(int n)__

che restituisce __true__ se il numero intero positivo __n__ è primo, __false__ altrimenti. Ricordiamo che:

- Un numero è primo se e solo se è divisibile (leggi: la divisione dà resto zero) solo per se stesso e per 1.

- Il resto della divisione a/b si calcola con l'operatore __a%b__ (che restituisce un valore tra __0__ e __b-1__).

# Esercizio 3

Scrivere una funzione 

__bool isPerfectSquare(int n)__

che restituisce __true__ se __n__ è un quadrato perfetto, ovvero $n=k^2$ per qualche intero $k$, __false__ altrimenti. 

Ricordate: 

- la radice quadrata di un numero si determina usando la funzione __sqrt()__ della libreria __cmath__; __sqrt()__ restituisce un razionale (__float__ o __double__).

- se assegnate un razionale (ad esempio __float__) ad un intero, la parte decimale viene troncata.

# Esercizio 4
Il file __interi.dat__ contiene un numero non precisato di interi positivi. Scrivere un programma che:

- Determini il numero $n$ di interi registrati sul file e li carichi in un vettore di interi allocato dinamicamente di dimensione $n$. Da qui in avanti indicheremo con $v_i$ l'$i$-esimo elemento del vettore $i=0,1,\ldots,n-1$.
- Allochi dinamicamente due vettori di __bool__ di dimensione $n$ di nome __isPrime__ e __isSquare__. Usando le funzioni __isPrime__ e __isSquare__ definite negli esercizi precedenti, assegnare a __isPrime[i]__ (risp. __isSquare[i]__) il valore __true__ se $v_i$ è primo (risp. è un quadrato perfetto).
- Elimini dal vettore tutti i valori che non siano né primi né quadrati perfetti. Attenzione: usate pure l'eliminazione tramite scambio, che in questo contesto va benissimo, ma ricordatevi di mantenere allineati i 3 vettori coinvolti.

Stampare a video e sul file __risultati.dat__ i valori sopravvissuti alla eliminazione del punto precedente indicando, per ogni valore registrato, se è primo o quadrato perfetto.

