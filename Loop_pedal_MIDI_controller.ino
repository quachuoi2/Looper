#include "Controller.h"
#define numb_butts 4 //modify this to the number of buttons (pedals) you have

MIDI_CREATE_DEFAULT_INSTANCE();

t_button	b_arr[numb_butts];

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

void	setup()
{
	int	button_index = 0;
	int	pin;
	int	note;

	MIDI.begin(MIDI_CHANNEL_OFF);
	while (button_index < numb_butts)
	{
		pin = 2 + button_index;         //assign buttons to pins, starting from pin D2
		note = 102 + button_index;      //assign notes starting from 102. Check MIDI CC list for more info.
		button_initializer(b_arr + button_index, pin, note, 1);
		button_index++;
	}
}

void	loop()
{
	int	button_index;

	button_index = 0;
	while (button_index < numb_butts)
		button_handler(b_arr + button_index++);
}
