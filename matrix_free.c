#include "main.h"

/**
 * free_matrix - frees the 2d array pointers
 * @mat: the matrix of pointers that will be freed
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
		idx++;
	}
	free(mat);
}

/**
 * free_tokens - frees the tokens that executed by program
 * @tokens: the pointers that will be freed
 * Return: void
*/
void free_tokens(char ***tokens)
{
	char ***temp = NULL;
	char **inner = NULL;
	char **temp_inner = NULL;

	if (tokens == NULL)
		return;

	temp = tokens;
	while (*temp != NULL)
	{
		inner = *temp;
		if (inner != NULL)
		{
			temp_inner = inner;
			while (*temp_inner != NULL)
			{
				free(*temp_inner);
				temp_inner++;
			}
			free(inner);
		}
		temp++;
	}
	free(tokens);
}

/**
 * free_argv - pointer to 2d pointers array
 * @argv: the matrix that will be freed
 * @row_index: index of the row
 * Return: Void
*/
void free_argv(char ***argv, int row_index)
{
	int i = 0;

	for (i = 0; i < row_index; i++)
	{
		free(argv[i]);
	}
	free(argv);
	argv = NULL;
}
