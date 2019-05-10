/*
   LCDKeypadShield
   A demo sketch to discover the VMA203 LCD Keypad Shield.
*/

// MHK_VMA203 library
#include <MHK_VMA203.h>

// VMA203 object
VMA203 shield;

// variable to change backlight brightness
int brightness = 15;

void setup() {
  // initialize VMA203 object
  shield.begin();

  // display a simple message
  shield.lcd.print("Press a button!");
}

void loop() {
  shield.keypad.read(); // update keypad state

  if (shield.keypad.select.pressed()) {
    shield.lcd.clear();
    shield.lcd.print("SELECT");
  }

  if (shield.keypad.left.pressed()) {
    shield.lcd.clear();
    shield.lcd.print("RIGHT");
  }

  if (shield.keypad.right.pressed()) {
    shield.lcd.clear();
    shield.lcd.print("LEFT");
  }

  if (shield.keypad.up.pressed()) {
    shield.lcd.clear();
    shield.lcd.print("UP");
    
    brightness = min(brightness + 1, 15);
    shield.backlight.setBrightness(brightness);
    shield.backlight.on();
  }

  if (shield.keypad.down.pressed()) {
    shield.lcd.clear();
    shield.lcd.print("DOWN");
    
    brightness = max(brightness - 1, 0);
    shield.backlight.setBrightness(brightness);
    shield.backlight.on();
  }
}
