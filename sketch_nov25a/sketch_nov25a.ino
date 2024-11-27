#include <esp_task_wdt.h>

#define WDT_TIMEOUT 3

void setup() {
  Serial.begin(9600);
  

}

void loop() {
  Serial.println("Hello Óscar!");

}
