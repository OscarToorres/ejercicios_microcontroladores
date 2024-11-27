int contador = 0; //Declarar el contador

void setup() {
  Serial.begin(9600);

  // put your setup code here, to run once:

}

void loop() {
  //Imprimir el contador
  Serial.print("Contador: ");
  Serial.println(contador);

  contador++; //Incremetar el contador

  delay(1000);
  // put your main code here, to run repeatedly:
}