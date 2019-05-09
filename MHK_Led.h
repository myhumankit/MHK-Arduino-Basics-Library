// MHK_Arduino_Basics - Led
// Usefull tools to start prototyping with Arduino.
// Copyright MyHumanKit 2019
// MIT License

// ensure this library description is only included once
#ifndef MHK_Led
#define MHK_Led

// uncomment to activate debugging mode
//#define DEBUG 1

// library interface description
class Led {
  public:

    // constructor:
    Led(uint8_t pin = LED_BUILTIN, bool defaultState = LOW):
      _pin(pin),
      _state(defaultState),
      _defaultState(defaultState),
      _blink(false),
      _brightness(15),
      _blinkTime(1000),
      _lastBlinkTime(0)
    {};

    // accessors and mutators:
    bool get() {
      return _state;
    };

    void set(bool state) {
      _state = state;
      if (_state != _defaultState) {
        switch (_brightness) {
          case 0:
            digitalWrite(_pin, _defaultState);
            break;
          case 1:
            if (_defaultState) {
              analogWrite(_pin, 256 - 1);
            } else {
              analogWrite(_pin, 1);
            };
            break;
          case 2:
            if (_defaultState) {
              analogWrite(_pin, 256 - 1);
            } else {
              analogWrite(_pin, 1);
            };
            break;
          case 3:
            if (_defaultState) {
              analogWrite(_pin, 256 - 2);
            } else {
              analogWrite(_pin, 2);
            };
            break;
          case 4:
            if (_defaultState) {
              analogWrite(_pin, 256 - 3);
            } else {
              analogWrite(_pin, 3);
            };
            break;
          case 5:
            if (_defaultState) {
              analogWrite(_pin, 256 - 5);
            } else {
              analogWrite(_pin, 5);
            };
            break;
          case 6:
            if (_defaultState) {
              analogWrite(_pin, 256 - 8);
            } else {
              analogWrite(_pin, 8);
            };
            break;
          case 7:
            if (_defaultState) {
              analogWrite(_pin, 256 - 12);
            } else {
              analogWrite(_pin, 12);
            };
            break;
          case 8:
            if (_defaultState) {
              analogWrite(_pin, 256 - 18);
            } else {
              analogWrite(_pin, 18);
            };
            break;
          case 9:
            if (_defaultState) {
              analogWrite(_pin, 256 - 27);
            } else {
              analogWrite(_pin, 27);
            };
            break;
          case 10:
            if (_defaultState) {
              analogWrite(_pin, 256 - 39);
            } else {
              analogWrite(_pin, 39);
            };
            break;
          case 11:
            if (_defaultState) {
              analogWrite(_pin, 256 - 57);
            } else {
              analogWrite(_pin, 57);
            };
            break;
          case 12:
            if (_defaultState) {
              analogWrite(_pin, 256 - 83);
            } else {
              analogWrite(_pin, 83);
            };
            break;
          case 13:
            if (_defaultState) {
              analogWrite(_pin, 256 - 121);
            } else {
              analogWrite(_pin, 121);
            };
            break;
          case 14:
            if (_defaultState) {
              analogWrite(_pin, 256 - 176);
            } else {
              analogWrite(_pin, 176);
            };
            break;
          default:
            digitalWrite(_pin, !_defaultState);
            break;
        }
      }
      else {
        digitalWrite(_pin, _defaultState);
      }
    };


    void setBlinkTime(uint16_t blinkTime = 1000) {
      _blinkTime = blinkTime;
    };

    void setBrightness(uint8_t value = 15) {
      _brightness = min(value, 15);
    };

    // other functions:
    void begin() {
      pinMode(_pin, OUTPUT);
      off();
    };

    void on() {
      set(!_defaultState);
      noBlink();
    };

    void off() {
      set(_defaultState);
      noBlink();
    };

    void blink() {
      _blink = true;
    };

    void noBlink() {
      _blink = false;
    };

    void update() {
      if (_blink) {
        uint32_t now = millis();
        if (now > _lastBlinkTime + _blinkTime) {
          //set(!_state);
          _state = !_state;
          _lastBlinkTime = now;
        }
      }
      set(_state);
    };


  private:

    bool _state;
    bool _defaultState;
    bool _blink;

    uint8_t _pin;
    uint8_t _brightness;
    uint16_t _blinkTime;
    uint32_t _lastBlinkTime;
};

#endif
