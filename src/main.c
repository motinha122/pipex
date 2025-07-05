#include "../includes/ft_pipex.h"

int main(int argc, char *argv[])
{
  check_args_count(argc);

  ProcessCounter p_count = {1};

  int fd = creat("tempfile", 0600); // 0600 -> owner

  fork_and_execute(fd, &p_count, argv, "./print_strings");

  return 0;
}
