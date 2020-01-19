/* Avaliação 04.1 - Questão 1 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

  pid_t pid;
  int n;

  printf("Digite o valor de n: ");
  scanf("%d", &n);
  printf("%d\n", n);

  pid = fork();

  if (pid < 0) {

    fprintf(stderr, "Fork Failed");
    return 1;

  } else if (pid == 0) {

    do {
      
      if (n % 2 == 0) {

        n = n / 2;
        
      } else {

        n = (3 * n) + 1;

      } 


      printf("%d\n", n);        

        
    } while (n != 1);

  } else {

    wait(NULL);
    printf("Child Complete.\n\n");

  }


  return 0;
}