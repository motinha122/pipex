#ifndef FT_PIPEX_H
#define FT_PIPEX_H

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

// Error Functions

/*
 *    @brief Checks for an error, prints a message and exit if caught an error.
 *    @param error_code The code of the error.
 */
void error_check(int error_code);


/*
 *    @brief Check the number of arguments, if is different than 5 returns an error 1.
 *    @param argc The argc of the main program.
 */
void check_args_count(int argc);



#endif