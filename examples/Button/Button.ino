/*
 * Button
 * A demo sketch to discover MHK_Button library capabilities.
 *
 * Connect a push button between pin 7 and GND and watch what appends in the Serial Monitor!
 */

// MHK_Button library
#include <MHK_Button.h>

// Button object
Button bouton(7, HIGH); // pin number, defaultState: HIGH / LOW (default: LOW)

void setup() {
  // initialize serial communications
  Serial.begin(115200);

  // initialize Button object
  bouton.begin(INPUT_PULLUP); // mode: INPUT / INPUT_PULLUP (default: INPUT)

  // configure Button object
  bouton.setDebounceTime(50); // duration in milliseconds: 0 to 255 (default: 0)
  bouton.setHoldTime(2000);   // duration in milliseconds: 0 to 65535 (default: 1000)
  bouton.setIdleTime(3000);   // duration in milliseconds: 0 to  65535 (default: 1000)
  bouton.setMultiTime(255);   // duration in milliseconds: 0 to 255 (default: 127)
}

void loop() {
  bouton.read(); // update button state

  // if (bouton.on()) { Serial.println(F("ON")); }
  // if (bouton.off()) { Serial.println(F("OFF")); }
  if (bouton.changed()) { Serial.println(F("CHANGED")); }
  if (bouton.pressed()) { Serial.println(F("PRESSED")); }
  if (bouton.released()) { Serial.println(F("RELEASED")); }
  if (bouton.hold()) { Serial.println(F("HOLD")); }
  if (bouton.idle()) { Serial.println(F("IDLE")); }
  if (bouton.multi()) { Serial.println(F("MULTI")); }
}
