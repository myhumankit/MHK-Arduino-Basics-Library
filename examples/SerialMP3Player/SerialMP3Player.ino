/*
 * SerialMP3Player
 * A demo sketch to discover Serial MP3 Player library capabilities.
 *
 * Connect RX pin of the Serial MP3 Player to the TX pin of the Arduino (digital 1).
 * Connect GND pin to GND pin.
 * Connect VCC pin to +5V pin.
 */

// MHK_Serial_MP3_Player library
#include <MHK_Serial_MP3_Player.h>

// Serial_MP3_Player object
MP3Player player;

void setup() {
  // intialize Serial_MP3_Player object
  player.begin();

  // optionnal configuration
  player.setEqualizer(EQUALIZER_NORMAL); // EQUALIZER_NORMAL, EQUALIZER_POP, EQUALIZER_ROCK, EQUALIZER_JAZZ, EQUALIZER_CLASSIC, EQUALIZER_BASS
  player.setVolume(15);                  // volume: 0 to 30
}

void loop() {
  // play a specific track:
  player.playTrack(2, 6); // folder number (/02/), track number (/02/006_bidule.mp3)
  delay(5000); // wait for 5 seconds ...

  // pause
  player.pause();
  delay(5000); // wait for 5 seconds ...

  // play (or resume)
  player.play();
  delay(5000); // wait for 5 seconds ...

  // volume up
  player.volumeUp();
  delay(5000); // wait for 5 seconds ...

  // volume up
  player.volumeDown();
  delay(5000); // wait for 5 seconds ...

  // stop
  player.stop();
  delay(5000); // wait for 5 seconds ...
}
