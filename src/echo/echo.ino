
void setup() {
  Serial.begin(9600);
}

void loop() {
  
  // Verificar si hay datos para leer
  if(Serial.available() > 0){
    char recibido = Serial.read();

    // Hacer el cambio de caracteres
    if(recibido >= 'A' && recibido <= 'Z') {
      recibido = recibido + 32;
    }else if(recibido >= 'a' && recibido <= 'z') {
      recibido = recibido - 32;
    }

    // Devolverlo
    Serial.write(recibido);
  }

}