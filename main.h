#ifndef MAIN_H
#define MAIN_H
#define DELIMETER " \n\t\r"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#define BUFF_SIZE 1024

extern char **environ;

/*Declaration of functions*/
void display_prompt(void);
int bettyStyle(int m, int n);
void print_env(void);
int main(int argc, char **argv);
int exec(char *argv, char **av);
void tokens(char **args);
char **tokenize(char *str);
char *path(const char *cmd);
bool is_integer(const char *str);

#endif
