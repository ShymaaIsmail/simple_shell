#ifndef _error_message_
#define _error_message_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>

/**
 * enum ERROR_CODE - ERROR_CODE
 * @NOT_FOUND: NOT_FOUND
 * @ILLEGAL_PARAMETER: ILLEGAL_PARAMETER
 * @MAX_CODE: MAX_CODE
 *
 * Description: error codes
*/
typedef enum ERROR_CODE
{
	ILLEGAL_PARAMETER = 0,
	NOT_FOUND = 1,
	MAX_CODE
} ERROR_CODE;

/**
* struct SHELL_ERORR - SHELL ERORR TYPES
* @code: error code number sart from 0
* @message: error message
* Description: SHELL ERORR TYPES
*/
typedef struct SHELL_ERORR
{
	enum ERROR_CODE code;
	char *message;

} SHELL_ERORR;

void print_shell_error(enum ERROR_CODE error_code, int ptr_num, ...);

#endif
