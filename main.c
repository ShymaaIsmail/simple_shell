#include "main.h"

/**
* main - main
* @ac: d
* @argv: f
* Return: int
*/
int main(int ac, char **argv)
{
int is_interactive = check_mode();
if (is_interactive)
{
 display_user_prompt(ac, argv);
}
else
{
process_script(ac, argv);
}
char *prompt = "(Eshell) $ ";
char *lineptr, *lineptr_copy = NULL, *token;
const char *delim = " \n";
size_t n = 0, num_tokens = 0, i = 0;
ssize_t nchars_read;
SHELL_ERORR not_found_command = {NOT_FOUND_COMMAND, NULL};

(void)ac;

while (1)
{
printf("%s", prompt);
nchars_read = getline(&lineptr, &n, stdin);
if (nchars_read == -1)
{
printf("Exiting shell....\n");
return (-1);
}
printf("you typed %s\n", lineptr);
lineptr_copy = malloc(sizeof(char) * nchars_read);
if (lineptr_copy == NULL)
{
perror("tsh: memory allocation error");
return (-1);
}
strcpy(lineptr_copy, lineptr);
/* tokenizatin part*/
/* split the string (lineptr) into an array of words */
token = strtok(lineptr, delim);
/* determine how many tokens are there*/
while (token != NULL)
{
num_tokens++;
token = strtok(NULL, delim);
}
num_tokens++;
argv = malloc(sizeof(char *) * num_tokens);
  /* Store each token in the argv array */
token = strtok(lineptr_copy, delim);

for (i = 0; token != NULL; i++){
argv[i] = malloc(sizeof(char) * strlen(token));
strcpy(argv[i], token);

token = strtok(NULL, delim);
}
argv[i] = NULL;

print_shell_error(not_found_command, 2, "loy", "biin");
}
free_all(3, lineptr, lineptr_copy, argv);

return (0);
}
