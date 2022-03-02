#ifndef CONTROLLER_H
# define CONTROLLER_H

#include <MIDI.h>

typedef struct	s_button
{
	int	state;
	int	note;
	int pin;
	int	channel;
}				t_button;

void	Button_initializer(t_button *button, int pin, int note, int channel);
void	Button_handler(t_button *button);
#endif
