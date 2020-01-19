/* Exercício 3.18 - Cap 3 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>


int main() {

  pid_t pid;

  pid = fork();

  if (pid < 0) {

    fprintf(stderr, "Fork Failed");
    return 1;

  } else if (pid == 0) {

    execlp ("/bin/ls", "ls", NULL);

  } else {

    wait(NULL);
    printf("Child Complete.\n\n");

  }

  return 0;
}