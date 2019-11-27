#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "err.h"

#define NR_PROC 5

int main ()
{
  pid_t pid;
  int i; 
  
  pid_t parent_pid;

  /* tworzenie procesów potomnych */
  for (i = 1; i <= NR_PROC; i++) {
    parent_pid = getpid();
    switch (pid = fork()) {
      case -1: 
        syserr("Error in fork\n");

      case 0: /* proces potomny */
 
        printf("I am a child and my pid is %d\n", getpid());
        printf("My parent's id is %d\n", parent_pid);
        break;
    
      default: /* proces macierzysty */

        if (wait(0) == -1) 
          syserr("Error in wait\n");
        return 0;
    }
  } 
  
  return 0;
  
}
