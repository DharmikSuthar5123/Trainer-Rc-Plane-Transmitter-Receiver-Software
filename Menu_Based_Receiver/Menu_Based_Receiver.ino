#include <SPI.h>
#include <Servo.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(7, 8);
Servo esc1;
Servo esc2;
Servo s1;
Servo s2;
Servo s3;
const byte address[] = "12345";
struct dataPack {
  int16_t motor, s1, s2, s3;
};
dataPack data;
int servoVal;
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  esc1.attach(3, 1000, 2000);
  s1.attach(5);
  s2.attach(6);
  s3.attach(9);
}

void loop() {
  if (radio.available()) {
    radio.read(&data, sizeof(data));
  }
  esc1.write(data.motor);
  s1.write(data.s1);
  s2.write(data.s2);
  s3.write(data.s3);

 Serial.print(data.motor);
 Serial.print(" * "); 
 Serial.print(data.s1);
 Serial.print(" * ");
 Serial.print(data.s2);
 Serial.print(" * ");
 Serial.println(data.s3);


}
