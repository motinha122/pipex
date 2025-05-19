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

  default:
    fprintf(stderr, "Unkown error.\n");
    break;
  }
  exit(EXIT_FAILURE);
}

void check_args_count(int argc)
{
  if (argc != 5)
  {
    error_check(1);
  }
}

void check_create_process(pid_t pid)
{
  if (pid < 0)
  {
    error_check(2);
  }
}