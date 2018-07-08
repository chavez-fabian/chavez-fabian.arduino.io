#include <SoftwareSerial.h>

//Declaring the pins
SoftwareSerial BTserial(10, 11); // RX | TX
int smoke_input = A5;
int red = 13;
int green = 12;
//int buzzer = 9;

//Setting the smoke threshold
int smoke_thres = 300;
int smoke_conc = 0;

//Setup for pins
void setup() {
  pinMode(smoke_input, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  //pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  BTserial.begin(9600);
}

//Main function
void loop() {
  smoke_conc = analogRead(smoke_input);
  Serial.print("Smoke level: ");
  Serial.println(smoke_conc);
  if (smoke_conc >= smoke_thres) {
    //tone(buzzer, 1000);
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    BTserial.print("Smoke");
    BTserial.print(",");
    BTserial.print(smoke_conc);
    BTserial.print(",");
    BTserial.print("Red");
    BTserial.print(",");
    BTserial.print("Buzzing");
    BTserial.print(";");
  }
  else {
    //noTone(buzzer);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    BTserial.print("No_Smoke");
    BTserial.print(",");
    BTserial.print(smoke_conc);
    BTserial.print(",");
    BTserial.print("Green");
    BTserial.print(",");
    BTserial.print("No_Buzz");
    BTserial.print(";");
  }
  delay(100);
}
