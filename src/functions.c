#include "../includes/ft_pipex.h"

void error_check(int error_code){
  switch (error_code)
  {
  case 1:
    fprintf(stderr, "Error: invalid number of arguments.\n");
    fprintf(stderr, "Usage: ./pipex file1 cmd1 cmd2 file2\n");
    break;

  default:
    fprintf(stderr, "Unkown error.\n");
    break;
  }
  exit(EXIT_FAILURE);
}

void check_args_count(int argc){
  if(argc != 5){
    error_check(1);
  }
}

