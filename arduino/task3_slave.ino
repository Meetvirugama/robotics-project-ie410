#include <Braccio.h>
#include <Servo.h>

String input = "";

void setup() {
  Serial.begin(9600);
  Braccio.begin();
}

void loop() {

  if(Serial.available()){
    input = Serial.readString();
    input.trim();

    if(input == "READY"){

      // Move to handover
      Braccio.ServoMovement(20, 90, 90, 90, 90, 90, 10);
      delay(2000);

      // Grab
      Braccio.ServoMovement(20, 90, 90, 90, 90, 90, 70);
      delay(1000);

      Serial.println("GRIPPED");
    }
  }
}