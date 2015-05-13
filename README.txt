=== Eliot ===
Autori: Presenti nel file (indica il nome del file)
Tag: Motori, Arduino, Macchina, Ciclo di Sviluppo software
Versione Stabile:1.0
Licenza:GPL 3.0

== Descrizione ==

Il progetto è stato svolto a scopi didattici all'interno del programma didattico di Tecnologie e 
Progettazione di sistemi informatici e di telecomunicazione svolto dalla 4 A ITI dell'Istituto Pitagora di Pozzuoli.  
Docenti:
Mazzone Diomede;
Orecchio Alessandro.

Come spiegato ampiamente nelle documentazioni a supporto, la macchina Eliot realizza le seguenti funzionalità:
Ricerca di ostacoli;
Emissione di un suono all'ostacolo trovato, con distanza minore o uguale a 30cm;
La conversione dei valori in cm;
Le funzioni rispettivamente per comandare i motori (durante la marcia e/o le sterzate, il servo-motore per 
orientare il sensore di distanza;

License: GPLv3 o successiva

Requisiti:
*	3 Ruote;
*	2 Motori DC;
* 	1 Servo-Motore;
* 	1 Sensore IR;
* 	Cavetti di Collegamento;
* 	Arduino 1 rev 3;
* 	Motor Shield Adafruit.

== Istallazione ==

Il codice va caricato attraverso l'IDE Arduino, scaricabile gratuitamente dal sito:www.arduino.cc

== File Presenti ==

I file presenti sono:

* 	Diagramma UML dei casi d'uso e delle classi;
* 	Requisiti Software del codice;
* 	Codice Arduino, ampiamente documentato;
* 	alcuni punti chiave dell'algoritmo di progettazione del codice;
*	Presentazione esercitazione;
* 	Licenza GPL 3.0

== Bug Riscontrati ==

I bug riscontrati nel codice sono:

1)Problema: La macchinina gira, a differenza di quanto stabilito nei requisiti, senza un criterio preciso: non risolto.
2)Problema: la marcia ha una divergenza verso destra, probabilmente per una non perfetta costruzione. problema risolto
	    modificando la funzione "marcia_avanti()": riducendo la velocità del motore di sinistra.

= Ringraziamenti =

Sentito ringraziamento per il download e per la continuzione del codice e a tutti quelli che hanno contribuito
allo sviluppo dello stesso:

Mellone Dario - Papaccio Raffaele (gruppo 3);
Amato Roberto - Docimo Francesco (gruppo9);
Paolella Antonio - Cacciapuoti Pasquale (gruppo 4);
Pisano Giovanni (gruppo 7);
Conte Angelo - Papaccio Noè Ugo (gruppo6); 
Esposito Gaetano - Grieco Davide (gruppo 8);
Piccirillo Alessio - Salvatore Oro (gruppo2);
Di Martino Andrea - Cannizzaro Luigi (gruppo5);
Gigante Gennaro - Orlando Pasquale - Toscanese Andrea (gruppo1);
Casella Maria - Scamardella Assunta (gruppo 10).

Professori:

Mazzone Diomede,
Orecchio Alessandro.

 

 
