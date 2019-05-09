/*
 * Blink
 * A demo sketch to discover MHK_Led library capabilities.
 *
 * Make a Led blink with a non blocking routine!
 */

// MHK_Led library
#include <MHK_Led.h>

// Led object
Led led(6, LOW); // pin number (default: LED_BUILTIN), defaultState: HIGH / LOW (default: LOW)

void setup() {
  // initialize Led object
  led.begin();

  // configure Led object
  led.setBlinkTime(500); // duration in milliseconds: 0 to 65535 (default: 1000)
  led.setBrightness(7); // brightness: 0 to 15 (default: 15) (only for PWM pins!)
  led.blink(); // set blink on
}

void loop() {
  led.update(); // update led state
  delay(10); // a little delay for stability ...
}
