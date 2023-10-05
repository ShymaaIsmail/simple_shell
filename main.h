#ifndef _simple_shell_
#define _simple_shell_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include "error_message.h"
#include "string.h"
#include "constant.h"
#include <signal.h>

void free_all(int ptr_num, ...);
int check_mode(void);
void display_user_prompt(char **argv);
void process_non_interactive_script(int ac, char **argv);
void execute_command(void);
char **extract_tokens(int chars_count, char *user_input_ptr);
void execute_eof(void);
void execute_signal_interupt(void);
#endif
