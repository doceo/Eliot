
  
  // la funzione dist() restituisce un valore booleano TRUE se rileva un ostacolo a distanza maggiore di 30cm
  
  int dist(){

  int distMax = 30;  
  int trovato = false;                                                     // imposta la variabile che restituisce a false
    
  digitalWrite (triggerPort, HIGH);                                        // attraverso il trigger inizia a emettere onde
  delayMicroseconds(10);                                                   // per dieci secondi
  digitalWrite(triggerPort,LOW);                                           // e si ferma

  long duration =pulseIn(echoPort, HIGH);                                  //attraverso la funzione pulseIn acquisiamo il segnale tramite il sensore

  long int distanza = 0.036 * duration /2;                                 //calcoliamo la distanza

  Serial.print(" durata: ");                                               //stampiamo sul monitor seriale la durata del segnale e la distanza ottenuta
  Serial.println(duration);
  Serial.print(" distanza: ");

  if (duration >38000)     { 
          Serial.println("fuori portata");                                 //segnaliamo se la distanza è fuori dalla portata dello strumento
  
  }else { 
           Serial.print(distanza); 
           Serial.println ("cm");
           Serial.println (" ");
         }
         
//evitiamo una divisione per zero, sostituendo lo zero con 1000
if (duration == 0)
   duration == 1000;
   
   long int rval = microsecondsToCentimeters(duration);                    //calcoliamo la distanza in centimetri
 
 
 return rval;

}

long microsecondsToCentimeters(long microseconds)
  {
   return microseconds / cmconv;
  }
  
  
  void beep ()     
  {
    
    analogWrite(buzzer, 300);                                      //indica al pin buzzer un valore analogico pari a 300 .
    delay(100);                                                    //il tempo necessario a far suonare il beep
     analogWrite(buzzer, 0);                                       //azzera l'output riferita al pin buzzer . 
    
  }




 bool RicOst()    
 {  
   for (int i = pos_in - ang_mov ; i <= pos_in + ang_mov; i = i + 15) // ciclo di for per la rotazione del servo-motore, sommandolo . 
   {
     myservo.write (i);   // Il servo-motore viene settato all'angolazione definita dal ciclo .
     delay (50);          // Il tempo necessario per ricercare l'ostacolo .
       if ( dist()< dist_min )      // Confronto tra la distanza ottenuta e la distanza minima .
        {
          trovato=true;
          beep();         // Funzione di avvertimento tramite un beep .
          frenata();      // Chiamata a funzione "frenata()"
        }
    }
    if (trovato==false)         //Scelta in caso non si trovi l'oggetto .
    {
      for (int i = pos_in + ang_mov ; i >= pos_in - ang_mov; i = i - 15) // ciclo di for per la rotazione del servo-motore, sottraendolo . 
      {
         myservo.write (i);  
         delay (50);         
         if ( dist()< dist_min )   
         {
           trovato=true;           
           beep();                 
           frenata();              
         }
      }
    }
}
 
    // Funzione che permette la marcia in senso orario .
     
    void marcia_avanti(int vel) {        
    motorS.run(FORWARD);                 // Indica al motoreS di partire in senso orario .
    motorS.setSpeed(vel-70);             // Setta la velocità del motore di sinistra .
    motorD.run(FORWARD);                 // Indica al motoreD di partire in senso orario 
    motorD.setSpeed(vel);                // Setta la velocità del motore di destra .
    }

    //Funzione per far muovere la macchina in senso antiorario .
    
    void marcia_dietro() {               
    motorS.run(BACKWARD);                // Indica al motoreS di partire in senso orario .
    motorS.setSpeed(vel);              // Setta la velocità del motore di sinistra .
    motorD.run(BACKWARD);                // Indica al motoreD di partire in senso orario .
    motorD.setSpeed(vel);              // Setta la velocità del motore di destra .
    delay (700);                         // Il tempo necessario per far fare la marcia indietro .
    frenata();                           // Chiamata a funzione "frenata()" .
    }
    
    
    //Funzione per far fermare la macchina per mezzo secondo .
    
    void frenata() {                      
      motorS.run(RELEASE);                // Metodo per far frenare il motoreS .
      motorD.run(RELEASE);                // Metodo per far frenare il motoreD .
      delay (500);                        // Il tempo necessario per far frenare la macchina .
    }
   
    
 //Funzione per guardare a sinistra quando la macchina è ferma .
 
 int guarda_S ()
 {
   int locale=200;                                                // La variabile da paraganore al valore presente in "dist()" .
   for(int i = pos_in - ang_fer; i<=pos_in; i = i + 10)           // Ciclo di for per sottrarre la posizione iniziale all'angolo fermo .
   {
     myservo.write(i);                                           // Il servo-motore viene settato all'angolazione definita dal ciclo .
     locale=dist();                                             
     if (locale<dist())                                          // Condizione per determinare se il valore della variabile "locale" è minore di quella presente nella funzione "dist()" .
     {
       locale=dist();                                          
     }
     delay(500);                                                // Il tempo necessario per guardare a sinistra .
     return locale;                                             //restituisce la variabile "locale" .
   }
 }
 
 
 //Funzione per far girare la macchina a sinistra .
 
  void gira_S()                                                
 {
   motorD.run(FORWARD);                                         //Indica al motoreD di  girare a sinistra .
   motorD.setSpeed(vel);                                        //Indica al motoreD la velocità .
   motorS.run(RELEASE);                                         //Indica al motoreS di fermersi.
   delay(700);                                                  //Il tempo necessario per girare a sinistra
   frenata();                                                   //Chiamata a funzione della frenata
   
   }
   
   
 //Funzione per guardare a destra quando la macchina è ferma 
 
 int guarda_D ()
 {
   int locale=200;                                                // La variabile da paraganore al valore presente in "dist()" .
   for(int i = pos_in + ang_fer; i>=pos_in; i = i - 10)          // Ciclo di for per sommare la posizione iniziale all'angolo fermo .
     myservo.write(i);                                          //Il servo-motore viene settato all'angolazione definita dal ciclo .
     locale=dist();                                             
     if (locale<dist())                                        // Controllo se la variabile locale è minore della distanza .
     {
       locale=dist();                                       
     }
     delay(500);                                             // Il tempo necessario per guardare a destra .
     return locale;                                         // Restituisce la variabile locale .
   }
 }
 
 //Funzione per far girare a destra la macchina
 
  void gira_D()                                                  
 {
   motorS.run(FORWARD);                                          //Indica al motoreS di girare a destra .
   motorS.setSpeed(vel);                                         //indica al motoreS la velocità .
   motorD.run(RELEASE);                                          //Indica al motoreD di fermarsi .
   delay(700);                                                   //il tempo necessario per girare a destra .
   frenata();                                                    //chiamata a funzione della frenata() .
   }
   
   

