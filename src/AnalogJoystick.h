#include <Arduino.h>

class AnalogJoystick {
private:
  unsigned int x_pin;
  unsigned int y_pin;
  unsigned int button_pin;
  float min_x_value;
  float max_x_value;
  float min_y_value;
  float max_y_value;
private:
  const int MAX_POSITION_VALUE = 1024;
public:
  AnalogJoystick(
    unsigned int x_pin,
    unsigned int y_pin,
    unsigned int button_pin,

    float min_x_value,
    float max_x_value,
    float min_y_value,
    float max_y_value
  );
  AnalogJoystick(
    unsigned int x_pin,
    unsigned int y_pin,
    unsigned int button_pin
  );

  void begin() const;

  float read_x_position() const;
  float read_y_position() const;
  bool is_button_pressed() const;

private:
  float get_interval_length(float min_value, float max_value) const;
  float normalize_position(float position) const;
};
