//  Waldomiro Barbosa Romão 2018005655

#include <stdio.h>

void troca(int *x, int *y) 
{ 
    int aux = *x; 
    *x = *y; 
    *y = aux; 
} 

void bubbleSort(int vetor[], int tam) 
{ 
   int aux; 
   for (int i = 0; i < tam-1; i++)       
       for (int j = 0; j < tam-i-1; j++)  
           if (vetor[j] > vetor[j+1]) troca(&vetor[j], &vetor[j+1]);
} 

void selectionSort(int vetor[], int tam) 
{ 
    int menor, aux; 
    for (int i = 0; i < tam-1; i++) 
    { 
        menor = i; 
        for (int j = i+1; j < tam; j++) 
          if (vetor[j] < vetor[menor]) menor = j; 
				if(menor != i) troca(&vetor[menor], &vetor[i]);
    } 
} 

void insertionSort(int vetor[], int tam) 
{ 
    int chave; 
    for (int i = 1; i < tam; i++) 
		{ 
        chave = vetor[i]; 
        int j = i - 1; 
        while (j >= 0 && vetor[j] > chave) 
				{ 
            arr[j + 1] = vetor[j]; 
            j = j - 1; 
        } 
        vetor[j + 1] = chave; 
    } 
} 