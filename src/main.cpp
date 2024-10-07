#include <Arduino.h>
#include <pca9685.h>

Pca9685 pca9685 = Pca9685(); 

void setup() {
  pca9685.begin();
}

void loop() {
  pca9685.writeMotor(0, 0);
  delay(500);
  pca9685.writeMotor(90, 0);
  delay(500);
  pca9685.writeMotor(180, 0);
  delay(500);
}

