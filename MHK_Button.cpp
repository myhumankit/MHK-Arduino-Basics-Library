// MHK_Arduino_Basics - Button
// Usefull tools to start prototyping with Arduino.
// Copyright MyHumanKit 2019
// MIT License

// include Arduino core library
#include "Arduino.h"

// include this library's description file
#include "MHK_Button.h"

// include description files for other libraries used
// ...

// Constructor /////////////////////////////////////////////////////////////////
// Function that handles the creation and setup of instances

VirtualButton::VirtualButton(bool defaultState = LOW):
  _state(defaultState),
  _previousState(defaultState),
  _defaultState(defaultState),

  _holdFlag(false),
  _previousHoldFlag(false),

  _idleFlag(false),
  _previousIdleFlag(false),

  _multiFlag(false),

  _currentStateStart(0),
  _previousStateDuration(0),

  _holdTime(1000),
  _idleTime(1000),
  _multiTime(127)
{};


Button::Button(uint8_t pin, bool defaultValue = LOW)
       :VirtualButton(defaultValue),
  _pin(pin),
  _debounceTime(0),
  _lastDebounceTime(0)
{};


// Public Methods //////////////////////////////////////////////////////////////
// Functions available in MHK_Arduino_Basics sketches, this library, and other libraries

void VirtualButton::set(bool state) {
  uint32_t now = millis();
  _previousState = _state;
  _state = state;
  _multiFlag = false;

  if (changed()) {
    // reset timers
    _previousStateDuration = now - _currentStateStart;
    _currentStateStart = now;

    // reset flags
    _holdFlag = false;
    _previousHoldFlag = false;
    _idleFlag = false;
    _previousIdleFlag = false;

    // double click ?
    if (on() && (_previousStateDuration < _multiTime)) {
      _multiFlag = true;
    }
  }
  else if  (on()) {
    _previousHoldFlag = _holdFlag;
    _holdFlag = (now > _currentStateStart + _holdTime);
  }
  else {
    _previousIdleFlag = _idleFlag;
    _idleFlag = (now > _currentStateStart + _idleTime);
  }
};


bool Button::read() {
  if (_debounceTime != 0) {
    uint32_t now = millis();
    if (now < _lastDebounceTime + _debounceTime) {
      set(get());
    }
    else {
      set(digitalRead(_pin));
      if (changed()) {
        _lastDebounceTime = now;
      }
    }
  }
  else {
    set(digitalRead(_pin));
  }
  return get();
};


// Private Methods /////////////////////////////////////////////////////////////
// Functions only available to other functions in this library

// ...
