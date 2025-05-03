#include "../includes/ft_pipex.h"

int main(int argc, char *argv[])
{
  check_args_count(argc);
  int i = 0;
  while (*argv)
  {
    printf(ANSI_COLOR_RESET ANSI_COLOR_RED "%d - %s\n" ANSI_COLOR_RESET, i, *argv);
    i++;
    argv++;
  }
  printf("argc - %d\n", argc);
  return 0;
}
