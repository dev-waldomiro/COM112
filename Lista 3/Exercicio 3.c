/*Dupla:
        Álison Mesquita Maciel 2018 011 367
        Waldomiro Barbosa Romão 2018005655

*/

#include <stdio.h>
#include <string.h>
#include <locale.h>
#define TAM 10

typedef struct {
  int cod; // auto increment
  int price;
  char description [30];
} produto; // 'produto' chamará a struct agora (typedef)

void insertionSort_ordemAlf (produto p[])
{
  int i, j;
  produto aux;
  for(i = 1; i <= (TAM-1); i++)
  { 
      j = i;

      while(j > 0 && strcmp(p[j-1].description, p[j].description) > 0)
      { // swap
        aux = p[j];
        p[j] = p[j - 1];
        p[j - 1] = aux;
        j--;
      }
        
  }
}

void printarStruct_ordemAlf (produto p[])
{
  int i;
  printf("\nOrdem alfabética:\n\n");

  for(i = 0; i < TAM; i++)
  {
    printf("Produto %d\n  Código:     0%d\n  Preço:      R$ %d\n  Descrição:  %s\n\n", i + 1, p[i].cod + 1, p[i].price, p[i].description);
  }
}

int main(void) {
  setlocale(LC_ALL,"portuguese");

  int i, j, count, cod=0;
  int temp;
  char aux2[30];

  produto p[TAM], aux; // variavel p do tipo struct, TAM = 10;

  for(i=0; i<TAM; i++)
  {
    printf("\nDigite o preço do produto: ");
    scanf("%d", &p[i].price); // armazenando o preco na estrutura

    printf("Digite a descrição(nome) do produto: ");
    scanf(" %[^\n]s", p[i].description);

    p[i].cod = i; // código do produto (auto increment)
  }
  
  insertionSort_ordemAlf(p);

  printarStruct_ordemAlf(p);

  return 0;
}