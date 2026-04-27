#include <Braccio.h>
#include <Servo.h>

void moveSafe(int b, int s, int e, int w, int r, int g){
  Braccio.ServoMovement(20, b, s, e, w, r, g);
  delay(800);
}

void setup() {
  Braccio.begin();
}

void loop() {

  // HOME
  moveSafe(90, 90, 90, 90, 90, 10);

  // Hover above A
  moveSafe(90, 90, 90, 90, 90, 10);

  // Lower to A
  moveSafe(90, 120, 60, 90, 90, 10);

  // Grab object
  moveSafe(90, 120, 60, 90, 90, 70);

  // Lift
  moveSafe(90, 90, 90, 90, 90, 70);

  // Move to B
  moveSafe(45, 90, 90, 90, 90, 70);

  // Lower
  moveSafe(45, 120, 60, 90, 90, 70);

  // Release
  moveSafe(45, 120, 60, 90, 90, 10);

  // Back to HOME
  moveSafe(90, 90, 90, 90, 90, 10);

  while(1);
}