#include <MIDI.h>
#define button 3

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  MIDI.begin(MIDI_CHANNEL_OFF);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  int state;

  state = 0;
  i = digitalRead(button);
  if (i == HIGH && state == 0)
  {
  	MIDI.sendNoteOn(102, 127, 1);
    state = 1;
  }
  else if (i == LOW && state == 1)
  {
  	MIDI.sendNoteOff(102, 0, 1);
    state = 0;
  }
}
