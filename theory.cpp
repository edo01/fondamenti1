/*
	STREAM:
	
    every system has his way to represent the end of line. For example under windows the end
	of line is rapresented by the CR LF(carriage return, line feed) and under UNIX CR(carriage return).	

    Come interpreta i numeri dello stream? secondo u na serie di regole. Ad esempio little-endian.

    big-endian: memorizzazione/trasmissione che inizia dal byte più significativo (estremità più grande) per finire col meno significativo, è utilizzata dai processori Motorola;
    little endian: memorizzazione/trasmissione che inizia dal byte meno significativo (estremità più piccola) per finire col più significativo, è utilizzata dai processori Intel;
*/

/*
    INCLUDE:

    #include � una direttiva per il preprocessore(!) C, provocando poco prima della compilazione 
    delle modifcihe testuali. Ad esempio #inlcude <nome_file> nel momento prima della compilazione
	aggiunge il testo del file al posto dell'istruzione
*/

/*
    PRINT:
    
    printf(<stringa-formato>, <sequenza-elementi>) a differenza di di scanf, i parametri di scanf non necessitano
        dell'operatore deferenziale.

        simboli:
        1)int %d
        2)float %f
        3)carattere singolo %c
        4)stringa di caratteri %s
*/

/*
    SCANF:

    scanf(<stringa-formato>, <sequenza-variabili>); si dice che la scanf è distruttiva rispetto al valore
	presente nella memoria. scanf ritorna il numero di valori letti e convertiti correttamente.

    es:
    	int var_intero;
    	float var_float;
    	scanf("%d%f", &var_intero, &var_float);

    & è l'operatore unario di referenziazione, che restituisce l’indirizzo dell’operando su cui viene applicato.
    L’operazione complementare alla referenziazione è la dereferenziazione o indirezione, per cui è definito l’operatore unario *
    che restituisce la locazione di memoria corrispondente all’indirizzo contenuto nel suo operando.

    Quindi l'operatore & restituisce l-value mentre * restituisce r-value.

    tutti i parametri dello scanf richiedono l'operatore deferenziale, tranne le stringhe. Lo scanf restituisce
	il numero di caratteri lettere oppure il codice di EOF
	La scanf si comporta cos�:
	1) Con le char legge qualunque carattere;
	2) Con i numeri legge e scarta finch� non incontra un numero
	3) se deve leggere due numeri, li separa con lo spazio

	esempi:
	- scanf("%d,%d", &intero1, &intero2); 2,3 giusto 2, 3 giusto
	- scanf("%c%c%c%d%f", &c1, &c2, &c3, &i, &x); con ABC 3 7.345 c1=A, c2=B, C3=C i=3, x=7.345

	PROBLEMI:
	- ATTENZIONE il carattere invio corrisponde a due caratteri CR LF. Il primo viene interpretato come separatore, il secondo
	  rimane nel buffer. Un modo per scartare questo carattere � fare uno scanf("%c").
	- la scanf � deprecate e windows non fa compilare. Utilizzare la direttiva _CRT_SECURE_NO_DEPRECATE, oppure lo scanf_s("%c",&c1,1) l'ultimo parametro
	  indica il numero di parametri
*/

/*
    #define _CRT_SECURE_NO_DEPRECATE // Sono direttive al pre-compilatore, per poter utilizzare funzioni deprecate
    #define _CRT_SECURE_NO_WARNINGS
*/

/*
    CORTOCIRCUITO:
    
        void cortocircuito() {
            int a = 5, b = 5, c = 5;
            if (a > 0 || (a = a + 1)) printf("%d\n", a); //stampa 5
            if (b > 0 || (b = b + 1)) printf("%d\n", b); //stampa 6
            if (c > 0 || (c = c -5 )) printf("%d", c); //non stampa nulla
        }
*/

/*
 ERRORE COMNUNE DI APPROSSIMAZIONE:
    void calc2() {
    	float k;
        k = 5.6F;
        k = k - 5.59F; // the value of k is 0.00999975204, this is a common error of approsimation
    }
*/

/*
    SIZEOF:
    sizeof is a special operator of C
    remember that dim(long int) = dim(int) only in microsoft systems
*/

/*
    Esiste un file in c in cui il compilatore mappa il nome esterno delle funzioni e il nome interno del compilatore
    Il C supporta solamente il passaggio di valore per copia(valore), utile per separare l'ambiente del chiamante, da quello del chiamato.
    Esistono anche i passaggi di variabili per riferimento però, a cosa servono? il passaggio per copia è più semplice ed efficacie
    soprattutto a livello di back up. Ora però il passaggio per copia può diventare molto oneroso. Anche solo un giga di array
    diventa molto oneroso e il passaggio per riferimento è quindi più efficiente.
    In gergo in C si dice che il C ha entrambi anche se in realtà è stato sviluppato solo il passaggio per copia.

*/