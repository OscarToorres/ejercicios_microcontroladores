int contador1 = 0; //Declarar el contador
int contador2 = 0; //Declarar el contador

void setup() {
  Serial.begin(9600);

  // put your setup code here, to run once:

}

void loop() {
  for(int i = 0; i < 20; i++){

    contador1++; //Incrementamos el contador
    //Imprimir el contador
    Serial.print("ctr1: ");
    Serial.println(contador1);
    Serial.print("ctr2: ");
    Serial.println(contador2);
    delay(100);

  }
  
  contador2++; //Incremetar el contador 2
  Serial.print("ctr1: ");
  Serial.println(contador1);
  Serial.print("ctr2: ");
  Serial.println(contador2);
}