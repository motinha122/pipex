#ifndef FT_PIPEX_H
#define FT_PIPEX_H

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RST "\x1b[0m"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <sys/types.h>

/* === ERROR FUNCTIONS ===*/

/*
 *    @brief Checks for an error, prints a message and exit if caught an error.
 *    @param error_code The code of the error.
 */
void error_check(int error_code);

/*
 *    @brief Checks the number of arguments, if is different than 5 returns an error 1.
 *    @param argc The argc of the main program.
 */
void check_args_count(int argc);

/*
 *    @brief Checks if the process creation failed.
 *    @param pid The pid of the process.
 */
void check_process_creation(pid_t pid);

/*
 *    @brief Checks if the program executed failed.
 *    @param exec The exec command.
 */
void check_exec(int exec);

/* === STRING FUNCTIONS ===*/

/*
 *    @brief Splits a given string separating the substrings with space.
 *    @param *str The string to divide.
 *    @param num_substrings The number of substrings.
 *    @return The array that contains all the substrings.
 */
char **split_string(char *str, int num_substrings);

/*
 *    @brief Counts the number of substrings separated by space.
 *    @param *str The string to count.
 *    @return The number of substrings.
 */
int count_substrings(char *str);

#endif