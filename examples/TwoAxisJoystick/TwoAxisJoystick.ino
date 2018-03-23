#include <AnalogJoystick.h>

AnalogJoystick joystcik(A5, A4, A3);

void setup() {
  Serial.begin(9600);
  joystcik.begin();
}

void loop() {
  float x = joystcik.read_x_position();
  float y = joystcik.read_y_position();
  bool button = joystcik.is_button_pressed();

  Serial.print("X = ");
  Serial.print(x);
  Serial.print(", Y = ");
  Serial.print(y);
  Serial.print(", Button = ");
  Serial.print(button);
  Serial.println();

  delay(100);
}
