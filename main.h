#ifndef _simple_shell_
#define _simple_shell_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "error_message.h"
#include "string.h"
#include "constant.h"

void free_matrix(char **mat);
void free_all(int ptr_num, ...);
int check_mode(int ac);
void display_user_prompt(char **argv);
void process_non_interactive_file(char **argv);
void process_non_interactive_pipe(char *program_name);
void execute_command(char *program_name, char ***argv);
char ***extract_tokens(int chars_count, char *user_input_ptr);
void execute_eof(void);
void execute_signal_interupt(void);
char *validate_command(char *command);
void execute_exit(void);
void execute_env(void);
#endif
