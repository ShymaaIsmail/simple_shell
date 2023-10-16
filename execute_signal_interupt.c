#include "main.h"

/**
* execute_signal_interupt - execute if any interuption happened
* @signal: argument "the signal"
* Return: void
*/
void execute_signal_interupt(int signal)
{
	exit(signal * 0);
}
