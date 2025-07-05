#include "../includes/ft_pipex.h"

#define MIN_REQUIRED_ARGS 5
#define INVALID_ARGS 1
#define FORK_FAILED 2
#define EXEC_FAILED 3
#define DUP_FAILED 4

void error_check(int error_code)
{
  switch (error_code)
  {
  case INVALID_ARGS:
    fprintf(stderr, "Usage: ./pipex file1 cmd1 cmd2 file2\n");
    break;

  case FORK_FAILED:
    fprintf(stderr, "Error: Fork failed %s.\n", strerror(errno));
    break;

  case EXEC_FAILED:
    fprintf(stderr, "Error: Program execution failed %s.\n", strerror(errno));
    break;

  case DUP_FAILED:
    fprintf(stderr, "Error: Dup failed %s.\n", strerror(errno));
    break;

  default:
    fprintf(stderr, "Unknown error.\n");
    break;
  }
  exit(EXIT_FAILURE);
}

void check_args_count(int argc)
{
  if (argc < MIN_REQUIRED_ARGS)
  {
    fprintf(stderr, "Received %d arguments, but at least %d are required.\n", argc, MIN_REQUIRED_ARGS);
    error_check(INVALID_ARGS);
  }
}

void check_process_creation(pid_t pid)
{
  if (pid < 0)
  {
    error_check(FORK_FAILED);
  }
}

void check_exec(int exec)
{
  if (exec == -1)
  {
    error_check(EXEC_FAILED);
  }
}

void check_dup(int dup)
{
  if (dup == -1)
  {
    error_check(DUP_FAILED);
  }
}

/* === STRING FUNCTIONS ===*/

// char **split_string(char *str, int num_substrings){

//   return;
// }

int count_substrings(char *str)
{
  int str_size = strlen(str);
  int count = 1;
  int i = 0;
  while (i < str_size)
  {
    if (str[i] == ' ')
    {
      count++;
    }
    i++;
  }
  return count;
}

/* === EXECUTE FUNCTIONS ===*/

void increment_counter(ProcessCounter *c)
{
  c->count++;
}

int get_counter(ProcessCounter *c)
{
  return c->count;
}

void fork_and_execute(int fd, ProcessCounter *p_count, char** argv, char* program)
{
  pid_t process1 = fork();
  check_process_creation(process1);
  if (process1 == SUCCESS)
  {
    printf(RST RED "Process(%d) PID: %d\n" RST, get_counter(p_count), getpid());
    int dup = dup2(fd, STDOUT_FILENO);
    check_dup(dup);
    close(fd);
    int command = execvp(program, &argv[1]);
    check_exec(command);
  }
  else
  {
    wait(NULL);
    increment_counter(p_count);
    printf(RST GREEN "Child process executed \n" RST);
  }
}