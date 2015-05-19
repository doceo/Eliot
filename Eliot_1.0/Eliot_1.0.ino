//##############################################################################################################################################
//##   Coordinatori : Mellone Dario - Papaccio Raffaele (gruppo 3)                                                                             ##
//##   Autori : Paolella Antonio - Cacciapuoti Pasquale (gruppo 4), Conte Angelo - Papaccio Noè Ugo (gruppo6), Esposito Gaetano - Grieco Davide                                                                                                                     
//##   (gruppo 8),Piccirillo Alessio - Salvatore Oro (gruppo2), Di Martino Andrea - Cannizzaro Luigi (gruppo5), Gigante Gennaro - Orlando Pasquale-                                                                                                                                       ##
//##    Toscanese Andrea (gruppo1), Casella Maria - Scamardella Assunta (gruppo 10), Amato Roberto - Docimo Francesco (gruppo9), Pisano Giovanni                                                                                                                                      ##
//##    (gruppo 7)                                                                                                                                      ##
//##    Prof. Diomede Mazzone, Alessandro Orecchio
//##############################################################################################################################################                                                                                                                     ##


#include <AFMotor.h>                              // Include la libreria del motore .
#include <Servo.h>                               // Include la libreria del servo motore .

Servo myservo;                                    // Crea la classe servo per controllare l oggetto .
int triggerPort=A3;                               // Sensore che invia il segnale .
int echoPort = A5;                                // Sensore che riceve il segnale inviato dal trigger .
int cmconv = 59;                                  // Calcolo distanza dell'onda . 
int pos_in = 90;                                  // Variabile che definisce la posizione iniziale a 90° del servo-motore . 
int ang_mov=30;                                   // Variabile che definisce l'angolazione del servo in movimento . 
int vel=200;                                      // Variabile che definisce la velocità .
int ost_S;                                        // Variabile che trova l'ostacolo a sinistra .
int ost_D;                                        // Variabile che trova l'ostacolo a destra .
int ang_fer=75;                                   // Variabile che indica i gradi dell'angolo fermo .
int dist_min=30;                                  //Variabile che definisce la distanza minima dell'oggetto .
boolean trovato;                                  //Variabile che trova l'oggetto .

AF_DCMotor motorS(1);                             //Dichiarazione oggetto motore destro .
AF_DCMotor motorD(4);                             //Dichiarazione oggetto motore sinistro .
   // Inizializzo la variabile per contenere il pin collegato al buzzer
 int buzzer = A0;

void setup() {
    myservo.write(pos_in);                        // Il servo ruota nella posizione iniziale .
    pinMode(triggerPort, OUTPUT);                 // Il trigger viene inserito ad una porta input . 
    pinMode(echoPort, INPUT);                     // L'echo viene inserito ad una porta input . 
    digitalWrite(triggerPort, LOW);               // Porta a 0 l'input del trigger . 
    myservo.attach(9);                            // Attaccare il servo nel pin 9 per l' oggetto.
                                                  
      
    
    
    // Inizializzo il pin come OUTPUT e imposto il segnale a LOW
    
    pinMode(buzzer, OUTPUT);                      // Inserisce il buzzer ad un pin di output . 
    analogWrite(buzzer, 0);                       // Annullamento suono del buzzer . 
    digitalWrite(triggerPort, LOW);               // Porta a 0 l'output del trigger . 
    marcia_avanti(vel);

   
}

void loop() {                                     
  
  RicOst ();                                       //Chiamata a funzione ricerca ostacoli .  
  if(trovato==true)                                //Controllo per trovare l'angolo                                 
   {
     ost_S=guarda_S();                             //Assegnazione di guardare l'ostacolo a sinistra .
     ost_D=guarda_D();                             //Assegnazione di guardare l'ostacolo a sinistra .
     marcia_dietro();                              //Indica la marcia dietro (chiamata a funzione marcia dietro) . 
     marcia_avanti(vel);                           //Indica la marcia avanti (chiamata a funzione marcia avanti).
     if (ost_S > ost_D)                            //Controllo per vedere se l'ostacolo a sinistra e più lontano dell'stacolo a destra .
     {
       gira_D();                                   //Assegna di girare a destra .
     }
     else                                         
    {
      gira_S();                                     //Assegna di girare a sinistra .
    }  
    trovato=false;                                 //Indica che l'oggetto non e stato trovato
 }
 
 marcia_avanti(vel);
 }
    

