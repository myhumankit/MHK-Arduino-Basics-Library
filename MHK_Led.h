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
      _blinkTime(1000),
      _lastBlinkTime(0)
    {};

    // accessors and mutators:
    bool get() {
      return _state;
    };

    void set(bool state) {
      _state = state;
      digitalWrite(_pin, _state);
    };

    void setBlinkTime(uint16_t blinkTime = 1000) {
      _blinkTime = blinkTime;
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
          set(!_state);
          _lastBlinkTime = now;
        }
      }
    };


  private:

    bool _state;
    bool _defaultState;
    bool _blink;

    uint8_t _pin;
    uint16_t _blinkTime;
    uint32_t _lastBlinkTime;
};

#endif
