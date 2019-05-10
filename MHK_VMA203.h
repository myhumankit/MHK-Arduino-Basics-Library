// MHK_Arduino_Basics - VMA203
// Usefull tools to start prototyping with Arduino.
// Copyright MyHumanKit 2019
// MIT License

// ensure this library description is only included once
#ifndef MHK_VMA203
#define MHK_VMA203

// uncomment to activate debugging mode
//#define DEBUG 1

// include description files for other libraries used
#include "MHK_Button.h"
#include "MHK_Led.h"
#include <LiquidCrystal.h>

// constants
#define LCD_RS 8
#define LCD_EN 9
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7
#define LCD_Backlight 10

// library interface description
class VMA203_Keypad {
  public:

    // constructor:
    VMA203_Keypad(uint8_t pin = A0, uint16_t defaultValue = 1023):
      _pin(pin),
      _value(defaultValue)
    {};

    // other functions:
    void read() {
      _value = analogRead(_pin);

      if (_value < 50) {
        right.set(true);
        up.set(false);
        down.set(false);
        left.set(false);
        select.set(false);
      }
      else if (_value < 178) {
        right.set(false);
        up.set(true);
        down.set(false);
        left.set(false);
        select.set(false);
      }
      else if (_value < 333) {
        right.set(false);
        up.set(false);
        down.set(true);
        left.set(false);
        select.set(false);
      }
      else if (_value < 525) {
        right.set(false);
        up.set(false);
        down.set(false);
        left.set(true);
        select.set(false);
      }
      else if (_value < 832) {
        right.set(false);
        up.set(false);
        down.set(false);
        left.set(false);
        select.set(true);
      }
      else {
        right.set(false);
        up.set(false);
        down.set(false);
        left.set(false);
        select.set(false);
      }
    };

    VirtualButton right;  //   0
    VirtualButton up;     //  99
    VirtualButton down;   // 256
    VirtualButton left;   // 410
    VirtualButton select; // 641

  private:

    uint8_t _pin;
    uint16_t _value;
};


class VMA203 {
  public:

    // constructor:
    VMA203():
        lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7),
        backlight(LCD_Backlight, LOW)
    {};

    // other functions:
    void begin() {
        lcd.begin(16, 2);
        backlight.begin();
        //backlight.setBrightness(15);
        backlight.on();
    };

    LiquidCrystal lcd;
    VMA203_Keypad keypad;
    Led backlight;
};


#endif
