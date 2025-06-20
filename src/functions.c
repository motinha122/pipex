#include "../includes/ft_pipex.h"

void error_check(int error_code)
{
  switch (error_code)
  {
  case 1:
    fprintf(stderr, "Error: invalid number of arguments.\n");
    fprintf(stderr, "Usage: ./pipex file1 cmd1 cmd2 file2\n");
    break;

  case 2:
    fprintf(stderr, "Error: Fork failed.\n");
    break;

  case 3:
    fprintf(stderr, "Error: Program execution failed.\n");
    break;

  default:
    fprintf(stderr, "Unkown error.\n");
    break;
  }
  exit(EXIT_FAILURE);
}

void check_args_count(int argc)
{
  if (argc < 5)
  {
    error_check(1);
  }
}

void check_process_creation(pid_t pid)
{
  if (pid < 0)
  {
    error_check(2);
  }
}

void check_exec(int exec)
{
  if (exec == -1)
  {
    error_check(3);
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

void increment_counter(ProcessCounter *c){
  c->count++;
}

int get_counter(ProcessCounter *c){
  return c->count;
}
