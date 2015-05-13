=== Eliot ===
Autori: Presenti nel codice di Arduino
Tag: Motori, Arduino, Macchina
Versione Stabile:1.0
Licenza:GPL 3.0

== Descrizione ==

Il codice è stato scritto per scopi didattici, da parte di una 4 ITI di Napoli, seguiti dai professori:
Mazzone Diomede;
Orecchio Alessandro.

La macchina ha:
La ricerca dell'ostacolo;
Emissione di un suono all'ostacolo trovato, con distanza uguale a 30cm;
La conversione dei valori in cm;
Le funzioni rispettive per comandare i motori, e il servo-motore;

Requisiti:
*	3 Ruote;
*	2 Motori DC;
* 	1 Servo-Motore;
* 	1 Sensore IR;
* 	Cavetti di Collegamento;
* 	Arduino 1 rev 3;
* 	Motor Shield Adafruit.

== Istallazione ==

Per installare il seguente codice per una prorpia macchina, c'è bisogno dell'IDE Arduino, 
scaricabile gratuitamente dal sito:www.arduino.cc

== File Presenti ==

I file presenti sono:

* 	Diagramma UML del codice;
* 	Requisiti Software del codice;
* 	Codice Arduino, commentato per la correzzione dello stesso;
* 	Algoritmo di progettazione del codice;
*	Presentazione esercitazione;
* 	License.

I bug riscontrati con il codice conosciuti sono:

1)Problema:La macchinina gira a random quando ricerca l'ostacolo,non ha una preferenza, non risolto.
2)Problema:La nostra macchinina ha tendenza verso destra, per via delle ruote, problema risolto andando a modificare la funzione 
	   "marcia_avanti()" il motore di destra, riducendo la velocità.

= Ringraziamenti =

Sentito ringraziamento per il download e per la continuzione del codice e di tutti che hanno contribuito
allo sviluppo del codice:

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

Mazzone Diomede;
Orecchio Alessandro.

 

 
