unsigned long timerInicio = 0;
int timerCondicion = 1000;
bool publicando = false;
bool modoAlternativo = false;
int valorActual = 1;

void setup() {
  Serial.begin(9600);
  menu();
}

void loop() {

    if (Serial.available()){
      String recibe = Serial.readString();
      recibe.trim();
      recibe.toLowerCase();
      
      if (recibe.equals("h")){
        menu();
      }else if (recibe.equals("start")) {
        publicando = true;
      } else if (recibe.equals("stop")){
        publicando = false;
      }else if(recibe.equals("t")){
        Serial.println("Ingrese un intervalo (entre 1 y 10 Hz):");

        while (Serial.available() == 0) {} // Esperar por entrada
        int frecuencia = Serial.parseInt(); // Leer valor numérico

        if (frecuencia >= 1 && frecuencia <= 10) {
          
          timerCondicion = 1000 / frecuencia; // Calcular intervalo en milisegundos
          Serial.print("Intervalo actualizado a ");
          Serial.print(timerCondicion);
          Serial.println(" ms.");
        } else {
          Serial.println("Frecuencia inválida. Debe ser entre 1 y 10.");
        }
      } else if(recibe.equals("m")) {
              modoAlternativo = !modoAlternativo; // Alternar modo
      if (modoAlternativo) {
        Serial.println("Modo alternativo activado.");
      } else {
        Serial.println("Modo fijo activado.");
      }
      } else {
        Serial.println("Comando no reconocido. Escriba 'h' para ayuda.");
      }    
    }

    //Publicar valores
    if (publicando && millis() - timerInicio >= timerCondicion) {
      timerInicio = millis(); // Reiniciar el temporizador
      if (modoAlternativo) {
        valorActual = !valorActual; // Alternar entre 0 y 1
      }
      Serial.println(valorActual); // Publicar valor
    }

}

void menu(){
  Serial.println("H o h (help): muestra este menu de ayuda.");
  Serial.println("START o start: publica cada segundo un valor por el puerto serie.");
  Serial.println("STOP o stop: detiene la publicación del valor.");
  Serial.println(" o t (time): El siguiente valor enviado cambiará el periodo de publicación de la señal entre 1 y 10 veces por segundo.");
  Serial.println("M o m (mode): cambia el modo de fijo a alternativo. En modo fijo la señal se emite mantiene siempre el mismo valor siendo el ultimo emitido, por defecto debe ser un 1. Por otra parte, en modo alternativo cada vez que se publica el valor se alterna entre 0 y 1.");
}