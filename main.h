#ifndef _simple_shell_
#define _simple_shell_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include "error_message.h"
#include "string.h"

void free_all(int ptr_num, ...);
int check_mode();

#endif
