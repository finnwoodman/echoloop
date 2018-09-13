#include <Bounce.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=121,138
AudioMixer4              mixer1;         //xy=352,156
AudioEffectDelayExternal delayExt1;      //xy=354,317
AudioOutputI2S           i2s1;           //xy=538,313
AudioConnection          patchCord1(i2s2, 0, mixer1, 0);
AudioConnection          patchCord2(mixer1, delayExt1);
AudioConnection          patchCord3(delayExt1, 0, mixer1, 3);
AudioConnection          patchCord4(delayExt1, 0, i2s1, 0);
AudioConnection          patchCord5(delayExt1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=123,326
// GUItool: end automatically generated code


Bounce button0 = Bounce(0, 5);

void setup() {

  pinMode(0, INPUT_PULLUP);
  AudioMemory(5);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.95);
  sgtl5000_1.inputSelect(AUDIO_INPUT_LINEIN);
  sgtl5000_1.micGain(46);
  mixer1.gain(0, 0.95);
  mixer1.gain(3, 0.95);
  delayExt1.delay(AUDIO_MEMORY_23LC1024, 2500);
  delay(1000);
}

void loop() {
  // uncomment for A3 knob to control the feedback level
  /*
  int knob = analogRead(A3);
  float feedback = (float)knob / 1050.0;
  mixer1.gain(3, feedback);
  */

  // uncomment for pin 0 button to double the feedback (allowing unstable)
  /*
  button0.update();
  if (button0.read() == LOW) {
    mixer1.gain(3, feedback * 2.0);
  }
  */
}
