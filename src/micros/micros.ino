int contador1 = 0; //Declarar el contador
int contador2 = 0; //Declarar el contador

unsigned long tiempoInicio1;
unsigned long tiempoInicio2; 

const int intervalo1 = 100000; //Intervalo de 100000 microsegundos = 0.1 segundos
const int intervalo2 = 2000000; //Intervalo de 2000000 milisigundos = 2 segundos

void setup() {
  Serial.begin(9600);
  tiempoInicio1 = micros();
  tiempoInicio2 = tiempoInicio1; 

}

void loop() {
  
  int tiempoActual = micros();

  if ((tiempoActual - tiempoInicio1) >= intervalo1){
    contador1++; //Incrementamos el contador
    //Imprimir el contador
    Serial.print("ctr1: ");
    Serial.println(contador1);
    Serial.print("ctr2: ");
    Serial.println(contador2);
    tiempoInicio1 = tiempoActual;
  } else if ((tiempoActual - tiempoInicio2) >= intervalo2) {
    contador2++;
    contador1 -= contador2;
    Serial.print("ctr1: ");
    Serial.println(contador1);
    Serial.print("ctr2: ");
    Serial.println(contador2);
    tiempoInicio2 = tiempoActual;
  }
  
}