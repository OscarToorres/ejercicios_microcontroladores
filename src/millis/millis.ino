int contador1 = 0; //Declarar el contador
int tiempoAnterior = 0; 
const int intervalo1 = 1000; //Intervalo de 0.1 segundos

void setup() {
  Serial.begin(9600);

}

void loop() {
  
  int tiempoActual = millis();

  if ((tiempoActual - tiempoAnterior) == intervalo1){
    contador1++; //Incrementamos el contador
    //Imprimir el contador
    Serial.print("ctr1: ");
    Serial.println(contador1);
    tiempoAnterior = tiempoActual;
  }
  
}