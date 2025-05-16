#include "../includes/ft_pipex.h"

int main(int argc, char *argv[])
{
  check_args_count(argc);
  // int i = 0;
  // while (*argv)
  // {
  //   printf(RST RED "%d - %s\n" RST, i, *argv);
  //   i++;
  //   argv++;
  // }
  // printf("argc: %d\n", argc);

  char *args[] = {"safada", "cachorra", "biscate", NULL};
  execv("./print_argv", args);
  printf(RST BLUE "PID: %d\n" RST, getpid());
  return 0;
}
