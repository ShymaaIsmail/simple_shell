#ifndef _error_message_
#define _error_message_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>
/**
* struct SHELL_ERORR - SHELL ERORR TYPES
* @code - error code number sart from 0
* @message: error message
* Description: SHELL ERORR TYPES
*/
typedef struct SHELL_ERORR
{
	enum
	{
		NOT_FOUND_COMMAND,
		ILLEGAL_PARAMETER,
		MAX_CODE
	} code;
	char *message;

} SHELL_ERORR;

void print_shell_error(SHELL_ERORR shell_error, int ptr_num, ...);

#endif
