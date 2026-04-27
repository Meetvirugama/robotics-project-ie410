#include <Braccio.h>
#include <Servo.h>

String input = "";

void setup() {
  Serial.begin(9600);
  Braccio.begin();
}

void loop() {

  // Move to handover position holding object
  Braccio.ServoMovement(20, 90, 90, 90, 90, 90, 70);
  delay(2000);

  Serial.println("READY");

  // Wait for confirmation
  while(true){
    if(Serial.available()){
      input = Serial.readString();
      input.trim();

      if(input == "GRIPPED"){
        break;
      }
    }
  }

  // Release object
  Braccio.ServoMovement(20, 90, 90, 90, 90, 90, 10);

  while(1);
}