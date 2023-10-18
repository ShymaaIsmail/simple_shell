# 0x16. C - Simple Shell

## This is an ALX Cohort 18 project ( Last project in the first semester)

This is a simple shell project written in C progrmming language to behave exactly as sh (/bin/sh) program.

#What is the shell?
a program takes commands and gives them to the operating system to perform them.

important Functionalities:

We implement may features like:
1. Simple shell 0.1
mandatory
Write a UNIX command line interpreter.

Usage: simple_shell
Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)

2. Handle command lines with arguments

3. Handle the PATH
    fork must not be called if the command doesn’t exist
4. Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit

5. Implement the env built-in, that prints the current environment

6. Write your own getline function
Use a buffer to read many chars at once and call the least possible the read system call
You will need to use static variables
You are not allowed to use getline

#Compilation of the project:

##the compilation code:
###gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

#the allowed functions and system calls of the project:

1. access
2. chdir
3. close (man 2 close)
4. closedir (man 3 closedir)
5. execve (man 2 execve)
6. exit (man 3 exit)
7. _exit (man 2 _exit)
8. fflush (man 3 fflush)
9. fork (man 2 fork)
10. free (man 3 free)
11. getcwd (man 3 getcwd)
12. getline (man 3 getline)
13. getpid (man 2 getpid)
14. isatty (man 3 isatty)
15. kill (man 2 kill)
16. malloc (man 3 malloc)
17. open (man 2 open)
18. opendir (man 3 opendir)
19. perror (man 3 perror)
20. read (man 2 read)
21. readdir (man 3 readdir)
22. signal (man 2 signal)
23. stat (__xstat) (man 2 stat)
24. lstat (__lxstat) (man 2 lstat)
25. fstat (__fxstat) (man 2 fstat)
26. strtok
27. wait
28. waitpid
29. wait3
30. wait4
31. write

#Testing

the shell should work like this in interactive mode:
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
also in non-interactive mode:
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

#Output
##program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
##he only difference is when you print an error, the name of the program must be equivalent to argv[0]

#Requirements

1- Allowed editors: vi, vim, emacs
2- All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
3- All files should end with a new line
4- A README.md file, at the root of the folder of the project is mandatory
5- code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
6- shell should not have any memory leaks
7- No more than 5 functions per file
8- All your header files should be include guarded
9- Use system calls only when you need to (why?)
10- Write a README with the description of your project
11- You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker


# AUTHORS

## Shymaa Ismail
## Zainab Fadil
