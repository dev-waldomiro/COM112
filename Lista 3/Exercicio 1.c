/*Dupla:
        Álison Mesquita Maciel 2018 011 367
        Waldomiro Barbosa Romão 2018005655

*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void bubbleSort ( int vetor[])
{
  int i, j, aux;
  for(i = 1; i < TAM; i++) // base do vetor de comparações 'TAM - i'
  {
    for(j = 0; j < TAM - i; j++)
    {
      if ( vetor[j] < vetor[j + 1] ) // if==true -> troca de posição
      {
         aux = vetor[j];            // aux recebe o menor
         vetor[j] = vetor[j + 1];   // j recebe o maior 
         vetor[j + 1] = aux;       // j+1 recebe o menor em auxiliar
      }
    }
    /* // tire o comentário para acompanhar o "vetor de comparações"
        for(int a = 0; a <= TAM - i; a++)
          {
            printf("Elemento %d = %d\n", a, vetor[a]);
          } printf("\n");       */   
  } 
}
/* TAM - i => no final do loop, o menor valor será empurrado para a última posição e o maior valor de cada par é empurrando em direção ao topo (nesse caso, índice 0), 'TAM - i' garante que o número de comparações no loop interno diminua a partir do momento que os menores números já estão sendo empurrados em ordem para o fim do vetor, assim, é necessário um número MENOR de comparações para ordenar os restantes, tendo em vista que o vetor de comparações está diminuindo */
void printVetor (int vetor[])
{
  int i;
  printf("\nElementos ordenados (Decrescente):\n");
  
  for(i = 0; i < TAM; i++)
  {
    printf("Elemento %d = %d\n", i, vetor[i]);
  }
}


int main(void)
{
  int vetor[TAM], i = 0, j = 0, aux = 0;      
  
  for(i = 0; i < TAM; i++) 
  {
    printf("Preencher o vetor em [%d]: ",i);
    scanf("%d", &vetor[i]);
  }
  
  bubbleSort(vetor);
  printVetor(vetor);

  /* apenas o vetor passado como parametro pois TAM foi definido globalmente */

  return 0;
}