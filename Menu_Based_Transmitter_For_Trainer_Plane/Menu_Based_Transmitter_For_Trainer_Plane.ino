#include <EEPROM.h>

#include <RF24.h>
#include <SPI.h>
#include <Wire.h>
#include <nRF24L01.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0);
//long now;
// bool toggle = true;
// const float r1 = 1000;
// const float r2 = 215;
int8_t prevl2;
RF24 radio(7, 8);
const byte address[6] = "12345";
const char* menuItems[] = { "motor", "s1", "s2", "s3" };
int16_t config[4][3] = {
  { 180, 90, 0 },
  { 0, 33, 85 },
  { 29, 16, 120 },
  { -10, 44, 60 }
};
uint8_t menuSize = sizeof(menuItems) / sizeof(menuItems[0]);
int8_t currentMenu = 0;
int16_t j1x, j1y, j2x, j2y, pot;
int16_t l1, l2, sw;
void setup() {

  Serial.begin(9600);

  u8g2.begin();
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Wire.begin();
  delay(500);
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  EEPROM.get(0, config);
}

struct dataPack {
  int16_t motor, s1, s2, s3;
};

dataPack data;
int8_t diff, diff2, prevDiff2;
void loop() {

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_9x15_tr);
  u8g2.setCursor(64 - (u8g2.getStrWidth(menuItems[currentMenu]) / 2), u8g2.getMaxCharHeight());
  u8g2.print(menuItems[currentMenu]);
  GetInp();
  radio.write(&data, sizeof(data));
  if (l2 == 1) u8g2.drawBox(0, 62, 128, 2);
  u8g2.setFont(u8g2_font_8x13_tr);
  // u8g2.setCursor(60, u8g2.getMaxCharHeight() * 2);
  // u8g2.print(config[currentMenu][0]);

  // u8g2.setCursor(60, u8g2.getMaxCharHeight() * 3);
  // u8g2.print(config[currentMenu][1]);

  // u8g2.setCursor(60, u8g2.getMaxCharHeight() * 4);
  // u8g2.print(config[currentMenu][2]);
  for (int i = 0; i < 3; i++) {
    u8g2.setCursor(60, u8g2.getMaxCharHeight() * (i+2));
    u8g2.print(config[currentMenu][i]);
  }
  u8g2.sendBuffer();
}

void GetInp() {
  j1x = analogRead(A0);
  j1y = analogRead(A1);
  j2x = analogRead(A2);
  j2y = analogRead(A3);

  l1 = digitalRead(5);
  l2 = digitalRead(4);
  sw = digitalRead(2);
  pot = analogRead(A6);
  diff = diff2 = 0;
  if (l2 == 1) {
    if (currentMenu == 0) data.motor = constrain(map(j1y, 0, 1023, config[0][0], config[0][2]), 0, 180);
    else if (currentMenu == 1) data.s1 = constrain(map(j2y, 0, 1023, config[1][0], config[1][2]) + config[1][1], 0, 180);
    else if (currentMenu == 2) data.s2 = constrain(map(j2y, 0, 1023, config[2][2], config[2][0]) + config[2][1], 0, 180);
    else if (currentMenu == 3) data.s3 = constrain(map(j2y, 0, 1023, config[3][0], config[3][2]) + config[3][1], 0, 180);


    if (j2x > 800) diff = -1;
    else if (j2x < 200) diff = 1;
    if (j1x > 800) diff2 = -1;
    else if (j1x < 200) diff2 = 1;

    if (l1 == 1) {
      config[currentMenu][0] += diff;
      config[currentMenu][2] += diff2;
    } else {
      config[currentMenu][1] += diff;
      if (diff2 != prevDiff2) {
        currentMenu += diff2;
        if (currentMenu >= menuSize) currentMenu = 0;
        else if (currentMenu < 0) currentMenu = menuSize - 1;
      }
    }
  } else {
    if (prevl2 == 1) {
      EEPROM.put(0, config);
      Serial.println("Config Saved");
    }
    data.motor = constrain(map(j1y, 0, 1023, config[0][0], config[0][2]), 0, 180);
    data.s1 = constrain(map(j2x, 0, 1023, config[1][0], config[1][2]) + config[1][1], 0, 180);
    data.s2 = constrain(map(j2x, 0, 1023, config[2][2], config[2][0]) + config[2][1], 0, 180);
    data.s3 = constrain(map(j2y, 0, 1023, config[3][0], config[3][2]) + config[3][1], 0, 180);
  }
  prevDiff2 = diff2;
  prevl2 = l2;
}
// void VoltageCheck() {
//   float vOut = analogRead(A7) * (5.0 / 1023.0);
//   float vIn = vOut * ((r1 + r2) / r2);
//   if (vIn < 6.5) {
//     if (millis() - now >= 100) {
//       toggle = !toggle;
//       now = millis();
//     }
//     digitalWrite(10, toggle ? LOW : HIGH);
//     digitalWrite(9, toggle ? HIGH : LOW);
//   }
// }
