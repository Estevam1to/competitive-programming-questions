#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void trocar(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

bool estaOrdenado(int array[], int quantidade) {
  for (int i = 1; i < quantidade; i++) {
    if (array[i - 1] > array[i]) {
      return false;
    }
  }
  return true;
}

void bogoSort(int array[], int quantidade) {
  while (!estaOrdenado(array, quantidade)) {
    for (int i = 0; i < quantidade; i++) {
      int j = i + rand() % (quantidade - i);
      trocar(&array[i], &array[j]);
    }
  }
}

int buscaBinaria(int array[], int quantidade, int valor) {
  int mid = 0, ini = 0, fim = quantidade - 1;
  
  while(ini <= fim){
    mid = (ini + fim)/2;
    
    if(array[mid] == valor) 
        return 1;
    if(array[mid] < valor ) 
        ini = mid + 1;
    if(array[mid] > valor) 
        fim = mid - 1;
  }
  
  return 0;
}

int main() {
  // Lê os nossos dados de entrada:
  int quantidade;
  scanf("%d", &quantidade);
  int conteudos[quantidade];
  for (int i = 0; i < quantidade; i++) {
    scanf("%d", &conteudos[i]);
  }

  // Ordena os conteúdos usando Bogo Sort!?
  bogoSort(conteudos, quantidade);

  bool encontrou = buscaBinaria(conteudos, quantidade, 777);

  //TODO: Criar as condições necessárias para imprimir "S" ou "N".
  
  if(encontrou == 1) printf("S\n");
  else printf("N\n");

  return 0;
}
