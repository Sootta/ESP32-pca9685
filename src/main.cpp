#include <Arduino.h>
#include <Wire.h>

const uint8_t PCA9685_ADDR = 0x40;
const uint8_t MODE1 = 0x00;
const uint8_t PRESCALE = 0xFE;
const uint8_t LED0_ON_L = 0x06;
const uint8_t LED0_ON_H = 0x07;
const uint8_t LED0_OFF_L = 0x08;
const uint8_t LED0_OFF_H = 0x09;

// I2Cレジスタに1バイト書き込む関数
void writeRegister(uint8_t reg, uint8_t value) {
  Wire.beginTransmission(PCA9685_ADDR);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();                
}

void setPWM(uint8_t channel, uint16_t on, uint16_t off) {
  Wire.beginTransmission(PCA9685_ADDR);
  Wire.write(LED0_ON_L + 4 * channel);
  Wire.write(on & 0xFF);
  Wire.write(on >> 8);
  Wire.write(off & 0xFF);
  Wire.write(off >> 8);
  Wire.endTransmission();
}

void setup() {
  Wire.begin();
  delay(500);
  writeRegister(MODE1, 0x10);
  delay(500);
  writeRegister(PRESCALE, 121);
  delay(500);
  writeRegister(MODE1, 0x20);
  delay(500);
}

void loop() {
  setPWM(0, 0, 205);
  delay(500);  
  setPWM(0, 0, 307);
  delay(500);  
  setPWM(0, 0, 410);
  delay(500);
}

