#include "../includes/ft_pipex.h"

extern char **environ;

int main(int argc, char *argv[])
{
  check_args_count(argc);

  ProcessCounter p_count = {1};

  int process_count = get_counter(&p_count);

  int fd = creat("tempfile", 0600); // 0600 -> owner
  
  pid_t process1 = fork();
  check_process_creation(process1);
  if (process1 == SUCCESS)
  {
    printf(RST RED "Process(%d) PID: %d\n" RST, process_count ,getpid());
    dup2(fd, STDOUT_FILENO);
    close(fd);
    int command = execvp("./print_strings", &argv[1]);
    check_exec(command); 
  }
  else
  {
    wait(NULL);
    printf(RST GREEN "Child process executed \n" RST);
    process_count++;
    // printf(RST GREEN "Process count: %d\n" RST, process_count);
  }
  
  pid_t process2 = fork();
  check_process_creation(process2);
  if (process2 == SUCCESS)
  {
    printf(RST RED "Process(%d) PID: %d\n" RST, process_count ,getpid());
    dup2(fd, STDOUT_FILENO);
    close(fd);
    int command = execvp("./print_strings", &argv[1]);
    check_exec(command); 
  }
  else
  {
    wait(NULL);
    printf(RST GREEN "Child process executed \n" RST);
    // printf(RST GREEN "Process count: %d\n" RST, process_count);
  }



  return 0;
}
