/* Avaliação 04.1 - Questão 2 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_THREADS 5


/* criação das variáveis globais */
int num_total_pts_circ = 0;
int num_total_pts = 0;

/* Cabeçalho da função da contagem de pontos */
void *calculo_pi(void *param);

/* Programa Principal */
int main(int argc, char *argv[]) {

  int i;
  pthread_t tid[NUM_THREADS];
  pthread_attr_t attr;

  pthread_attr_init(&attr);

  for (i = 0; i < NUM_THREADS; i++) {
    
    pthread_create(&tid[i], &attr, calculo_pi, argv[1]); // cria a thread   

  }

  for (i = 0; i < NUM_THREADS; i++) {

    pthread_join(tid[i], NULL); // junta as threads

  }

  
  float calculo = 4 * (num_total_pts_circ / num_total_pts);
  
  printf("pi = %.4f\n", calculo);


  return 0;
}

float pitagoras( float x, float y) {

  return sqrt((x * x) + (y * y));

}

float pontoAleatorio() {
  return (2 * ((float) rand() / (float) RAND_MAX)) - 1;
}


/* implementação da função de contagem de pontos dentro do círculo */
void *calculo_pi(void *param) {

  int num_pts_circ_aux = atoi(param);
  int upper = atoi(param);

  float x = pontoAleatorio();
  float y = pontoAleatorio();

  

  for (int j = 0; j < num_pts_circ_aux; j++) {

    num_total_pts += 1;    

  }
  
  
  for (int i = 0; i < num_pts_circ_aux; i++) {

    if (pitagoras(x, y) <= 1) {

      num_total_pts_circ += 1;

    }

  }

  pthread_exit(0);

}