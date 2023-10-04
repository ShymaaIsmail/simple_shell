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
if (is_interactive)
{
 display_user_prompt(ac, argv);
}
else
{
process_script(ac, argv);
}
return (0);
}
