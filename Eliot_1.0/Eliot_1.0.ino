//####################################################################################################################################################
//##   Maintainers : Mellone Dario - Papaccio Raffaele (gruppo 3)                                                                                   ##
//##   Autori : Paolella Antonio - Cacciapuoti Pasquale (gruppo 4), Conte Angelo - Papaccio Noè Ugo (gruppo6), Esposito Gaetano - Grieco Davide     ##                                                                                                                
//##   (gruppo 8),Piccirillo Alessio - Salvatore Oro (gruppo2), Di Martino Andrea - Cannizzaro Luigi (gruppo5), Gigante Gennaro - Orlando Pasquale- ##                                                                                                                                      ##
//##   Toscanese Andrea (gruppo1), Casella Maria - Scamardella Assunta (gruppo 10), Amato Roberto - Docimo Francesco (gruppo9), Pisano Giovanni     ##                                                                                                                                  ##
//##   (gruppo 7)                                                                                                                                   ##
//##   Cordinatori:Prof Diomede Mazzone , Prof Alessandro Orecchio                                                                                  ##
//####################################################################################################################################################                                                                                                                     ##


#include <AFMotor.h>                              // Include la libreria del motore .
#include <Servo.h>                                // Include la libreria del servo motore .

Servo myservo;                                    // Crea l'oggetto myservo .
int triggerPort=A3;                               // Il trigger viene collegato alla porta A3 .
int echoPort = A5;                                // il sensore echo viene collegato alla porta A5 .
int cmconv = 59;                                  // Variabile di conversione . 
int pos_in = 90;                                  // Variabile che definisce la posizione iniziale a 90° del servo-motore . 
int ang_mov=30;                                   // Variabile che definisce l'angolazione del servo in movimento . 
int vel=200;                                      // Variabile che definisce la velocità .                                         
int ost_D;                                        // Variabile che conserva la distanza dell'ostacolo a destra .
int ost_S;                                        // Variabile che conserva la distanza dell'ostacolo a sinistra .
int ang_fer=75;                                   // Variabile che indica l'angolazione dell'oggetto quando è fermo .
int dist_min=30;                                  //Variabile che definisce la distanza minima dell'oggetto .
boolean trovato;                                  //Variabile che conserva l'ostacolo trovato .

AF_DCMotor motorS(1);                            // Motore sinistro collegato al pin 1 . 
AF_DCMotor motorD(4);                            // Motore destro collegato al pin 4 .
 
 int buzzer = A0;                                 // Il buzzer viene collegato alla porta A0 . 

void setup() {
    myservo.write(pos_in);                        // Il servo-motore viene settato alla posizione iniziale .
    pinMode(triggerPort, OUTPUT);                 // Il sensore trigger viene collegato in una porta di tipo output  . 
    pinMode(echoPort, INPUT);                     // Il sensore echo viene collegato in una porta di tipo input . 
    digitalWrite(triggerPort, LOW);               // Porta a 0 l'input del trigger .* 
    myservo.attach(9);                            // Il servo-motore viene assegnato al pin 9.
                                                  
      
    
    
    // Inizializzo il pin come OUTPUT e imposto il segnale a LOW
    
    pinMode(buzzer, OUTPUT);                      // Il buzzer è collegato ad un pin di output . 
    analogWrite(buzzer, 0);                       // Il buzzer viene settato a 0 . 
    digitalWrite(triggerPort, LOW);               // Porta a 0 l'output del trigger* . 
    marcia_avanti(vel);                           // Chiamata a funzione "marcia_avanti" .

   
}

void loop() {                                     
  
  RicOst ();                                       //Chiamata a funzione ricerca ostacoli .  
  if(trovato==true)                                                                
   {
     ost_S=guarda_S();                             //Funzione guarda l'ostacolo a sinistra .
     ost_D=guarda_D();                             //Funzione guarda l'ostacolo a destra .
     marcia_dietro();                              //Indica la marcia dietro (chiamata a funzione marcia in dietro) . 
     marcia_avanti(vel);                           //Indica la marcia avanti (chiamata a funzione marcia in avanti).
     if (ost_S < ost_D)                            //Confronto tra l'ostacolo a sinistra e a destra .
     {
       gira_D();                                   //Funzione che sceglie di girare a destra se l'ostacolo è a sinistra .
     }
     else                                         // Altrimenti
    {
     gira_S();                                     //Funzione che sceglie di girare a sinistra se l'ostacolo è a destra  .
    }  
    trovato=false;                                 //Indica che l'oggetto non e stato trovato .
 }
 
 marcia_avanti(vel);                               
 }
 
 
   
            

    

