#ifndef _constant_
#define _constant_

/* shell program special character*/
#define Prompt_Title  "$"
#define Space_Delim  " "
#define New_Line_Delim  "\n"

/* shell program exit codes */
#define EXIT_SUCCESS 0
#define EXIT_ERROR 1
#define EXIT_PERMISSION_NOTFOUND 126
#define EXIT_COMMAND_NOTFUND 127

/* strings */
#define EXIT "exit"
#define ENV "env"

/* SHELL MODES*/
#define INTERACTIVE_INPUT 0
#define PIPE_INPUT 1
#define FILE_INPUT 2


/* NON-INTERACTIVE MODE ASSUMPTIONS*/
#define BUFFER_SIZE 1024
#endif
