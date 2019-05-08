// MHK_Arduino_Basics - Button
// Usefull tools to start prototyping with Arduino.
// Copyright MyHumanKit 2019
// MIT License

// ensure this library description is only included once
#ifndef MHK_Button
#define MHK_Button

// uncomment to activate debugging mode
//#define DEBUG 1

// library interface description
class VirtualButton {
  public:

    // contructor:
    VirtualButton(bool defaultState = LOW);

    // accessors and mutators:
    bool get() { return _state; };
    void set(bool state);
    void setHoldTime(uint16_t holdTime) { _holdTime = holdTime; }; // Set the amount of milliseconds the user will have to hold a button until the HOLD state is triggered.
    void setIdleTime(uint16_t idleTime) { _idleTime = idleTime; }; // Set the amount of milliseconds the user will have to release a button until the IDLE state is triggered.
    void setMultiTime(uint8_t multiTime) { _multiTime = multiTime; }; // Set the max amount of milliseconds between two push to trigger the MULTI state.
    uint32_t getCurrentStateStart() { return _currentStateStart; };
    uint32_t getPreviousStateDuration() { return _previousStateDuration; };

    // other functions:
    bool on() { return (_state != _defaultState); };
    bool off() { return (_state == _defaultState); };
    bool changed() { return (_state != _previousState); };
    bool pressed() { return (changed() && on()); };
    bool released() { return (changed() && off()); };
    bool hold() { return (_holdFlag != _previousHoldFlag); };
    bool idle() { return (_idleFlag != _previousIdleFlag); };
    bool multi() { return _multiFlag; };

  private:

    bool _state;
    bool _previousState;
    bool _defaultState;

    bool _holdFlag;
    bool _previousHoldFlag;

    bool _idleFlag;
    bool _previousIdleFlag;

    bool _multiFlag;

    uint32_t _currentStateStart;
    uint32_t _previousStateDuration;

    uint16_t _holdTime;
    uint16_t _idleTime;
    uint8_t _multiTime;
};


class Button : public VirtualButton {
  public:

    // contructor:
    Button(uint8_t pin, bool defaultValue = LOW);

    // accessors and mutators:
    void setDebounceTime(uint16_t debounceTime) { _debounceTime = debounceTime; };

    // other functions:
    void begin(uint8_t mode = INPUT) { pinMode(_pin, mode); };
    bool read();

  private:

    uint8_t _pin;
    uint16_t _debounceTime;
    uint32_t _lastDebounceTime;
};

#endif
