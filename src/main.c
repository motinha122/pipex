#include "../includes/ft_pipex.h"

extern char **environ;

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

  char *str[] = {"teste", "batata", "xampson", "lep", "cenoura", NULL};

  pid_t pid = fork();

  check_process_creation(pid);

  if (pid == 0)
  {
    printf(RST RED "Child PID: %d\n" RST, getpid());
    // printf("argv[1]: %s", argv[1]);
    // execvp(argv[1], &argv[1]);
    // int command = execvp("print_strings", &argv[1]);
    int command = execvp("./print_strings", str);
    check_exec(command); 
  }
  else
  {
    wait(NULL);
    printf(RST BLUE "\nParent PID: %d\n" RST, getpid());
    printf(RST GREEN "Child process executed \n" RST);
  }

  return 0;
}
