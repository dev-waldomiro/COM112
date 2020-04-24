/*Dupla:
        Álison Mesquita Maciel 2018 011 367
        Waldomiro Barbosa Romão 2018005655

*/

#include <stdio.h>
#include <string.h>
#include <locale.h>
#define TAM 10
// tamanho definido globalmente

typedef struct{
  int salario;
  char nome [15];
} funcionario; // typedef struct para chamar struct de 'funcionario'

void selectionSort_salario (funcionario f[])
{
  int i, j, min;
  funcionario aux; // variaveis do tipo struct

  for(i = 0; i < (TAM-1); i++)
  {
    min = i;                  // variavel utilizada nas comparações
    for(j = i + 1; j < TAM; j++) // j sempre na frente
    {
      if(f[j].salario > f[min].salario ){  // buscando o maior valor
        min = j; // pegando indice do maior p/ utilizar no swap
      }
    }

    if (i != min)// comparando se 'i' já é o indice com maior valor, caso sejam diferentes, o swap é realizado
    {  // swap
      aux = f[i]; 
      f[i] = f[min];         // trocando o maior valor => 'min = j;'
      f[min] = aux;         // trocando o outro de posição
    }
  }
}

void selectionSort_ordemAlf (funcionario f[])
{
  int i, j, temp;
  funcionario aux2; // variavel tipo struct 'funcionario'
  for(i = 0; i < (TAM-1); i++)
    {
        temp = i; // temp recebendo posiçao inicial

        for(j = i + 1; j < TAM; j++) // j sempre na frente
        {
          if(strcmp(f[j].nome, f[temp].nome) < 0)
          { 
            temp = j; // passando posição(indice) da 'menor' pra temp
          } 
        }
        
        if(i != temp) // se os "menores" forem !=
        { //swap
          aux2 = f[i];
          f[i] = f[temp];
          f[temp] = aux2;
        }
    }
}
/* A seleção pra ordem alfabética funciona assim: o primeiro IF compara se a 'string1' é MENOR que a 'string2', caso seja, devemos passar essa string MENOR para trás pra no fim poder realizar a ordenação alfabética.
O segundo IF apenas confere a diferença entre 'i' e 'temp' para assim realizar o SWAP. */

// item (a)
void printarStruct_salario (funcionario f[])
{
  int i;
  printf("\nSalario em ordem decrescente =>\n\n");
    for(i = 0; i < TAM; i++)
    {
      printf("\n  R$ %d\n  Nome: %s\n", f[i].salario, f[i].nome);
    }
}

// item (b)
void printarStruct_ordemAlf (funcionario f[])
{
  int i;
  printf("\nNomes em ordem alfabética =>\n\n");  
  for(i = 0; i < TAM; i++)
  {
    printf("  %s\n  Salário : %d\n\n", f[i].nome, f[i].salario);
  }
}

                            // MAIN //

int main(void) {
  setlocale(LC_ALL,"portuguese");

  int j=0, i, indice, temp, min;

  funcionario f[TAM], aux2, aux; // variaveis tipo 'funcionario'

//preencher os dados para funcionarios
  for(i=0; i<TAM; i++)
  {
    printf("\nDigite o salario: ");
    scanf("%d", &f[i].salario);

    printf("Digite o primeiro nome do funcionario: ");
    scanf("%s", f[i].nome);
  }

  selectionSort_salario(f); // f => variavel tipo struct
  printarStruct_salario(f); // item (a)

  selectionSort_ordemAlf(f);
  printarStruct_ordemAlf(f); // item (b)
  
  return 0;
}
