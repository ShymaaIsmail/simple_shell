#include "main.h"

/**
* check_mode - determine whether the shell
* usage mode interactive or not
*/
int check_mode()
{
  return (isatty(STDIN_FILENO));
}
