#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

  printf("MAIN PROCESS ID: %d\nPARENT OF MAIN PROCESS ID: %d", getpid(),
         getppid());

  pid_t child = fork();

  if (child < 0)
    printf("\nUNFORTUNATELY Child was not created !");
  else if (child == 0) {
    printf("\n\nCHILD PROCESS ID: %d\nPARENT ID OF CHILD: %d", getpid(),
           getppid());
   
  } else {
    printf("\n\nPARENT PROCESS ID: %d\nPARENT ID OF PARENT: %d", getpid(),
           getppid());
    sleep(50);
  }

  return 0;
}