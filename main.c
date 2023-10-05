#include "main.h"

/**
* main - main
* @ac: d
* @argv: f
* Return: int
*/
int main(int ac, char **argv)
{
	int is_interactive = check_mode();

	if (is_interactive && ac > 0)
	{
		display_user_prompt(argv);
	}
	else
	{
		process_non_interactive_script(ac, argv);
	}
	return (0);
}
