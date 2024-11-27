int timerInicio = 0;
int timerCondicion = 1000;
boolean cont = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  menu();
}

void loop() {
  // put your main code here, to run repeatedly:
    if (Serial.available()){
      String recibe = Serial.readString().toLowerCase();
      if (recibe.equals("h")){
        menu();
      }else if (recibe.equals("start")) {
        cont = true;
        generateValue(cont);
      } else if (recibe.equals("start")){
        cont = false;
        generateValue(cont);
      }else if(recibe.equals("t")){
        
      } else if(recibe.equals("m")) {
        
      }    
    }

    
}

void menu(){
  Serial.println("H o h (help): muestra este menu de ayuda.");
  Serial.println("START o start: publica cada segundo un valor por el puerto serie.");
  Serial.println("STOP o stop: detiene la publicación del valor.");
  Serial.println(" o t (time): El siguiente valor enviado cambiará el periodo de publicación de la señal entre 1 y 10 veces por segundo.");
  Serial.println("M o m (mode): cambia el modo de fijo a alternativo. En modo fijo la señal se emite mantiene siempre el mismo valor siendo el ultimo emitido, por defecto debe ser un 1. Por otra parte, en modo alternativo cada vez que se publica el valor se alterna entre 0 y 1.");
}

void generateValue(boolean cont){
  while(cont == true) {

    int timerActual = millis()

    if ((timerActual - timerInicio) >= condicion){
      timerInicio = timerActual;

      Serial.write(1);
    }
  }
}