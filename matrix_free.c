#include "main.h"

/**
 * free_matrix - frees the 2d array
 * @mat: the matrix that will be freed
 * Return: (Void) no value
 */
void free_matrix(char **mat)
{
	int idx = 0;

	if (!mat || mat == NULL)
		return;
	while (mat[idx])
	{
		free(mat[idx]);
	}
	free(mat);
}
