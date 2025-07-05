#ifndef FT_PIPEX_H
#define FT_PIPEX_H

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RST "\x1b[0m"
#define SUCCESS 0

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

typedef struct {
  int count;
} ProcessCounter;

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

/*
 *    @brief Checks if the dup2 executed failed.
 *    @param dup The dup status.
 */
void check_dup(int dup);

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

/* === EXECUTE FUNCTIONS === */

/*
 *    @brief Increments the counter by 1.
 *    @param c The counter.
 */
void increment_counter(ProcessCounter *c);

/*
 *    @brief Returns the counter value.
 *    @param c The counter.
 *    @return the counter.
 */
int get_counter(ProcessCounter *c);

/*
 *    @brief Creates a fork and execute the program with the argv
 *    @param fd The file descriptor to send the output.
 *    @param p_count The process counter.
 *    @param **argv The arguments of the main program.
 *    @param *program The name of the program.
 */
void fork_and_execute(int fd, ProcessCounter *p_count, char **argv, char *program);


#endif