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
#include <sys/stat.h>
#include "error_message.h"
#include "string.h"
#include "constant.h"

extern char **environ;

void free_matrix(char **mat);
void free_all(int ptr_num, ...);
int check_mode(int ac);
void display_user_prompt(char **argv, int *exit_code);
void process_non_interactive_file(char **argv, int *exit_code);
void process_non_interactive_pipe(char *program_name, int *exit_code);
void execute_command(char *input, char *program_name,
					char ***argv, int *exit_code);
char ***extract_tokens(char *user_input_ptr);
void execute_eof(void);
void execute_signal_interupt(int signal);
char *validate_command(char *command);
int execute_exit(char *input, char ***argv, char **command,
				char *program_name, int line_number, int previous_error_code);
void execute_env(int *exit_code);
void free_tokens(char ***tokens);
void free_argv(char ***argv, int row_index);
#endif
