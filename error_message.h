#ifndef _error_message_
#define _error_message_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>

/**
 * enum ERROR_CODE - enum that contains the error code that appears for user
 * @NOT_FOUND: object (type of error) "NOT FOUND command"
 * @ILLEGAL_PARAMETER: object when passing to the command not accepted arg
 * @MAX_CODE: MAX_CODE
 *
 * Description: error codes that will be appear to the user in the shell
*/
typedef enum ERROR_CODE
{
	ILLEGAL_PARAMETER = 0,
	NOT_FOUND = 1,
	MAX_CODE
} ERROR_CODE;

/**
* struct SHELL_ERORR - struct that contains all SHELL ERORR TYPES
* @code: index of the error code starts from 0
* @message: the content of error message
* Description: SHELL ERORR TYPES
*/
typedef struct SHELL_ERORR
{
	enum ERROR_CODE code;
	char *message;

} SHELL_ERORR;

void print_shell_error(enum ERROR_CODE error_code, int ptr_num, ...);

#endif
