#include "Controller.h"
#define numb_butt 4

MIDI_CREATE_DEFAULT_INSTANCE();

void	button_initializer(t_button *button, int pin, int note, int channel)
{
	button->state = 0;
	button->note = note;
	button->pin = pin;
	button->channel = channel;
	pinMode(pin, INPUT);
}

void	button_handler(t_button *button)
{
	int	i;

	i = digitalRead(button->pin);
	if (i == HIGH && button->state == 0)
	{
		MIDI.sendNoteOn(button->note, 127, button->channel);
		button->state = 1;
	}
	else if (i == LOW && button->state == 1)
	{
		MIDI.sendNoteOff(button->note, 0, button->channel);
		button->state = 0;
	}
}

t_button	b_arr[numb_butt];

void setup()
{
	button_initializer(&b_arr[0], 2, 110, 1);
	button_initializer(&b_arr[1], 3, 111, 1);
	button_initializer(&b_arr[2], 4, 112, 1);
	button_initializer(&b_arr[3], 5, 113, 1);
	MIDI.begin(MIDI_CHANNEL_OFF);
}

void loop()
{
	int	i;

	i = 0;
	while (i < numb_butt)
		button_handler(&b_arr[i++]);
}
