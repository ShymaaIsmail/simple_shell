#include "main.h"

/**
* display_user_prompt - display_user_prompt
* @ac: nummber of args
* @argv: array of pointers with args
* Return: void
*/
void display_user_prompt(int ac, char **argv)
{
      char *lineptr, *lineptr_copy = NULL, *token;
      size_t n = 0, num_tokens = 0, i = 0;
      ssize_t chars_count;
      SHELL_ERORR not_found_command = {NOT_FOUND_COMMAND, NULL};

      (void) ac;
      while (1)
      {
        write(STDOUT_FILENO, Prompt_Title, 2);
        nchars_read = getline(&lineptr, &n, stdin);

        if (nchars_read == EOF)
        {
        printf("Exiting shell....\n");
        }
        lineptr_copy = malloc(sizeof(char) * nchars_read);
        if (lineptr_copy == NULL)
        {
        perror("tsh: memory allocation error");
        }
        strcpy(lineptr_copy, lineptr);
        /* tokenizatin part*/
        /* split the string (lineptr) into an array of words */
        token = strtok(lineptr, Command_DeLim);
        /* determine how many tokens are there*/
        while (token != NULL)
        {
        num_tokens++;
        token = strtok(NULL, Command_DeLim);
        }
        num_tokens++;
        argv = malloc(sizeof(char *) * num_tokens);
          /* Store each token in the argv array */
        token = strtok(lineptr_copy, Command_DeLim);

        for (i = 0; token != NULL; i++)
        {
        argv[i] = malloc(sizeof(char) * strlen(token));
        strcpy(argv[i], token);

        token = strtok(NULL, Command_DeLim);
        }
        argv[i] = NULL;

        /* test print error*/
        print_shell_error(not_found_command, 2, "loy", "biin");
        print_shell_error(not_found_command,0);
      }
      free_all(3, &lineptr, &lineptr_copy, &argv);
}
