// MHK_Arduino_Basics - Serial MP3 Player v1.0
// Usefull tools to start prototyping with Arduino.
// Copyright MyHumanKit 2019
// MIT License

// ensure this library description is only included once
#ifndef MHK_Serial_MP3_Player
#define MHK_Serial_MP3_Player

// uncomment to activate debugging mode
//#define DEBUG 1

// include description files for other libraries used
// ...

// constants
#define DEFAULT_WAIT 200

#define EQUALIZER_NORMAL  0x00
#define EQUALIZER_POP     0x01
#define EQUALIZER_ROCK    0x02
#define EQUALIZER_JAZZ    0x03
#define EQUALIZER_CLASSIC 0x04
#define EQUALIZER_BASS    0x05

// library interface description
class MP3Player {
    public:

        // constructor:
        MP3Player() {};

        // accessors and mutators:
        void setVolume(byte volume, unsigned long wait = DEFAULT_WAIT) {
            sendCommand(0x06, 0x00, min(volume, 30), wait);
        };

        void setEqualizer(byte mode, unsigned long wait = DEFAULT_WAIT) {
            sendCommand(0x07, 0x00, mode, wait);
        };

        // other functions:
        void begin(unsigned long wait = DEFAULT_WAIT) {
            Serial.begin(9600);
            delay(1000); // delay for MP3 Player to start
            reset(wait);
            selectSDCard(wait);
            setEqualizer(EQUALIZER_NORMAL, wait);
            setVolume(15, wait);
        };

        void volumeUp(unsigned long wait = DEFAULT_WAIT) {
            sendCommand(0x04, 0x00, 0x00, wait);
        };

        void volumeDown(unsigned long wait = DEFAULT_WAIT) {
            sendCommand(0x05, 0x00, 0x00, wait);
        };

        void playTrack(byte folder, byte track, unsigned long wait = DEFAULT_WAIT) {
            sendCommand(0x0f, folder, track, wait);
        };

        void play(unsigned long wait = DEFAULT_WAIT) { // play or resume
            sendCommand(0x0D, 0x00, 0x00, wait);
        };

        void pause(unsigned long wait = DEFAULT_WAIT) {
            sendCommand(0x0E, 0x00, 0x00, wait);
        };

        void stop(unsigned long wait = DEFAULT_WAIT) {
            sendCommand(0x16, 0x00, 0x00, wait);
        };

    private:

        void sendCommand(byte command, byte data0, byte data1, unsigned long wait = DEFAULT_WAIT) {
            Serial.write(0x7e);    // starting byte
            Serial.write(0xff);    // version
            Serial.write(0x06);    // number of bytes of the command
            Serial.write(command); // command
            Serial.write(0x00);    // 0x00 no feedback, 0x01 feedback
            Serial.write(data0);
            Serial.write(data1);
            Serial.write(0xef);    // ending byte
            delay(wait);
        };

        void reset(unsigned long wait = DEFAULT_WAIT) {
            sendCommand(0x0c, 0x00, 0x00, wait);
        };

        void selectSDCard(unsigned long wait = DEFAULT_WAIT) {
            sendCommand(0x09, 0x00, 0x02, wait);
        };
};

#endif
