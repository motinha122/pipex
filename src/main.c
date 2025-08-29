#include "../includes/ft_pipex.h"

int main(int argc, char *argv[])
{
  check_args_count(argc);
  ProcessCounter p_count = {1};

  int fd = creat("tempfile", 0600); // 0600 -> owner

  int pipe_index = find_string_index(argv, argc, PIPE);

  int prog1_init = 1;
  int prog1_end = pipe_index - 1;
  int prog2_init = pipe_index + 1;
  int prog2_end = argc - 1;

  char **program_1_args = copy_strings_src(argv, prog1_init, prog1_end);
  char **program_2_args = copy_strings_src(argv, prog2_init, prog2_end);
  printf("Program args: %s \n", program_1_args[0]);
  printf("Program args: %s \n", program_1_args[1]);
  printf("Program args: %s \n", program_1_args[2]);
  printf("Program args: %s \n", program_1_args[3]);
  printf(" ");
  printf("Program args: %s \n", program_2_args[0]);
  printf("Program args: %s \n", program_2_args[1]);
  printf("Program args: %s \n", argv[0]);

  fork_and_execute(fd, &p_count, &argv[2], argv[1], OUTPUT);
  fork_and_execute(fd, &p_count, &argv[5], argv[4], INPUT);
  
  //
  // TODO: Solve invalid free 
  free_strings(program_1_args);
  free_strings(program_2_args);
  
  close(fd);
  unlink("tempfile");

  return 0;
}
