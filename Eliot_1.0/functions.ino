
  
  // la funzione dist() restituisce un valore booleano TRUE se rileva un ostacolo a distanza maggiore di 30cm
  
  int dist(){

  int distMax = 30;  
  int trovato = false;                                                     // imposta la variabile che restiuisce a false
    
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
    delay(100);                                                    //ritarda il suono di 100 millisecondi .
     analogWrite(buzzer, 0);                                       //azzera l'output riferita al pin buzzer . 
    
  }




 bool RicOst()    
 {  
   for (int i = pos_in - ang_mov ; i <= pos_in + ang_mov; i = i + 15) // ciclo di for per la rotazione del servo . 
   {
     myservo.write (i);   // comanda al servo di angolarsi in base alla misura stabilita nel ciclo di for .
     delay (50);          // ritarda la rotazione di 10 millisecondi .
       if ( dist()< dist_min )      // scelta per emissione del suono alla rilevazione dell'ostacolo .
        {
          trovato=true;
          beep();         // Funzione di avvertimento tramite un beep .
          frenata();
        }
    }
    if (trovato==false)         //controllo per trovare l'oggetto
    {
      for (int i = pos_in + ang_mov ; i >= pos_in - ang_mov; i = i - 15) //ciclo di for per indicare la posizione iniziale aggiungendo e sottraendo l'angolo in movimento
      {
         myservo.write (i);  //scrive sul monitor seriale la variabile iteratore
         delay (50);         // crea un ritardo di 50 millisecondi
         if ( dist()< dist_min )   //controllo per vedere la funzione dist è maggiore dell'angolo minimo
         {
           trovato=true;           //assegnazione per trovare l'angolo
           beep();                 //chiamata a funzione di beep()
           frenata();              //chiamata a funzione di ferenata()
         }
      }
    }
}
 
 
    void marcia_avanti(int vel) {        //Funzione per far muovere la macchina verso avanti
    motorS.run(FORWARD);                 //indica al motore1 di andare avanti
    motorS.setSpeed(vel-70);                //indica al motore1 la velocità
    motorD.run(FORWARD);                 //indica al motore2 di andare avanti
    motorD.setSpeed(vel);                //indica al motore2 la velocità
    }

    void marcia_dietro() {               //Funzione per far muovere la macchhina verso dietro
    motorS.run(BACKWARD);                //indica al motore1 di andare indietro
    motorS.setSpeed(vel);              //indica al motore1 la velocità di retromarcia
    motorD.run(BACKWARD);                //indica al motore2 di andare indietro
    motorD.setSpeed(vel);              //indica al motorD la velocità di retromarcia
    delay (700);                         //indica il ritardo di 500 millisecondi
    frenata();                           //chiamata a funzione della frenata
    }
    
    void frenata() {                      //Funzione per far fermare la macchina
      motorS.run(RELEASE);                //funzione per far frenare il motore1
      motorD.run(RELEASE);                //funzione per far frenare il motore2
      delay (500);                        //indica il ritardo di 500 millisecondi
    }
   
    
 
 int guarda_S ()
 {
   int locale=200;                                                //variabile locale distanza da paragonare
   for(int i = pos_in - ang_fer; i<=pos_in; i = i + 10)           //ciclo di for per paragonare la posizione iniziale sottraendo l'angolo fermo
   {
     myservo.write(i);                                           //scrivere sul monitor seriale la variabile iteratore
     locale=dist();                                              //assegnare la variabile locale alla funzione dist()
     if (locale<dist())                                          //condizione per determinare se la variabile locale è minore della funzione dist()
     {
       locale=dist();                                            //assegna la variabile locale alla funzione dist()
     }
     delay(500);                                                //ritardo di 500 millisecondi
     return locale;                                             //restituisce la variabile locale
   }
 }
 
 
 
  void gira_S()                                                 //Funzione per far girare la macchina a sinistra
 {
   motorD.run(FORWARD);                                         //indica al motore2 di  girare a sinistra
   motorD.setSpeed(vel);                                        //indica al motore2 la velocità
   motorS.run(RELEASE);                                         //indica al motore1 di girare a sinistra
   delay(700);                                                  //indica il ritardo di 500 millisecondi
   frenata();                                                   //chiamta a funzione della frenata
   
   }
   
   
 
 
 int guarda_D ()
 {
   int locale=200;                                                //variabile locale distanza da paragonare
   for(int i = pos_in + ang_fer; i>=pos_in; i = i - 10)          //ciclo di for per aggiungere alla variabile iteratore la posizione iniziale più l'angolo fermo 
   {
     myservo.write(i);                                          //scrive sull monitor swìeriale la variabile iteratore
     locale=dist();                                             //variabile locale assegnata alla funzione dist()
     if (locale<dist())                                        //controllo se la variabile locale è minore della distanza
     {
       locale=dist();                                         //assegnata la variabile locale alla funzione dist()
     }
     delay(500);                                             //ritardo di 500 millisecondi 
     return locale;                                         //restituisce la variabile locale
   }
 }
 
 
 
  void gira_D()                                                  //Fuhnzione per far girare a destra la macchina
 {
   motorS.run(FORWARD);                                          //indica al motore1 di girare a destra
   motorS.setSpeed(vel);                                         //indica al motore1 la velocità
   motorD.run(RELEASE);                                          //indica al motore2 di girare a destra
   delay(700);                                                   //indica un ritardo di 500 millisecondi
   frenata();                                                    //chiamata a funzione della frenata()
   }
 
 

