#include "../includes/ft_pipex.h"

int main(int argc, char *argv[])
{
  check_args_count(argc);

  char *args[] = {"teste", "batata", "capivara", NULL};
  pid_t pid = fork();
  
  check_create_process(pid);
  
  if(pid == 0){
    printf(RST RED "Child PID: %d\n" RST, getpid());
    execv("./print_argv", args);
  } else {
    wait(NULL);
    printf(RST BLUE "\nParent PID: %d\n" RST, getpid());
    printf(RST GREEN "Child process executed \n" RST);
  }

  // int i = 0;
  // while (*argv)
  // {
  //   printf(RST RED "%d - %s\n" RST, i, *argv);
  //   i++;
  //   argv++;
  // }
  // printf("argc: %d\n", argc);
  return 0;
}
