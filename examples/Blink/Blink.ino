/*
 * Blink
 * A demo sketch to discover MHK_Led library capabilities.
 *
 * Make a Led blink with a non blocking routine!
 */

// MHK_Led library
#include <MHK_Led.h>

// Led object
Led led(13, LOW); // pin number (default: LED_BUILTIN), defaultState: HIGH / LOW (default: LOW)

void setup() {
  // initialize Led object
  led.begin();

  // configure Led object
  led.setBlinkTime(500); // duration in milliseconds: 0 to 65535 (default: 1000)
}

void loop() {
  led.blink(); // update led state
  delay(10); // a little delay for stability ...
}
