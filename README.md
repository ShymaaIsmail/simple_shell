# 0x16. C - Simple Shell

## This is an ALX Cohort 18 project ( Last project in the first semester)

This is a simple shell project written in C progrmming language to behave exactly as sh (/bin/sh) program.

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

#our code flow: 


# AUTHORS

## Shymaa Ismail
## Zainab Fadil
