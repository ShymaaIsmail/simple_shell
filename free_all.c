#include "main.h"
/**
* free_all - free all passed pointers of any void* type
* @ptr_num: number of passed pointers
* Return: void
*/
void free_all(int ptr_num, ...)
{
	if (ptr_num > 0)
	{
		int ptr_index = 0;

		va_list ptr;
		void **ptr_to_release;

		va_start(ptr, ptr_num);
		while (ptr_index < ptr_num)
		{
		ptr_to_release = va_arg(ptr, void **);

		if (*ptr_to_release != NULL)
		{
		free(*ptr_to_release);
		*ptr_to_release = NULL;
		}
		ptr_index++;
		}
		va_end(ptr);
	}
}
