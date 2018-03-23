#include "AnalogJoystick.h"

AnalogJoystick::AnalogJoystick(
  unsigned int x_pin,
  unsigned int y_pin,
  unsigned int button_pin,

  float min_x_value,
  float max_x_value,
  float min_y_value,
  float max_y_value
) :
  x_pin(x_pin),
  y_pin(y_pin),
  button_pin(button_pin),
  min_x_value(min_x_value),
  max_x_value(max_x_value),
  min_y_value(min_y_value),
  max_y_value(max_y_value)
{
}

AnalogJoystick::AnalogJoystick(
  unsigned int x_pin,
  unsigned int y_pin,
  unsigned int button_pin
) :
  x_pin(x_pin),
  y_pin(y_pin),
  button_pin(button_pin),
  min_x_value(-1.0f),
  max_x_value( 1.0f),
  min_y_value(-1.0f),
  max_y_value( 1.0f)
{
}

void AnalogJoystick::begin() const
{
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
  pinMode(button_pin, INPUT_PULLUP);
}

float AnalogJoystick::read_x_position() const
{
  float x_position = normalize_position(analogRead(x_pin));
  float interval_length = get_interval_length(min_x_value, max_x_value);

  x_position *= interval_length;
  x_position += min_x_value;

  return x_position;
}

float AnalogJoystick::read_y_position() const
{
  float y_position = normalize_position(analogRead(y_pin));
  float interval_length = get_interval_length(min_y_value, max_y_value);

  y_position *= interval_length;
  y_position += min_y_value;

  return y_position;
}

bool AnalogJoystick::is_button_pressed() const
{
  return !digitalRead(button_pin);
}

float AnalogJoystick::get_interval_length(float min_value, float max_value) const
{
  return max_value - min_value;
}

float AnalogJoystick::normalize_position(float position) const
{
  return position / MAX_POSITION_VALUE;
}
