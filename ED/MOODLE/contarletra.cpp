#include <stdio.h>
#include <string.h>

/**
n é o tamanho do texto contido em frase.
**/
int contar_letra(char frase[], int n, char letra, int cont){
    if(n == 0){
        return cont;
    }
    if(frase[n -1] == letra){
        return contar_letra(frase, n - 1, letra, cont + 1);
    }

    return contar_letra(frase, n - 1, letra, cont);
}


int main(){
    char frase[100];
    scanf("%[^\n]", frase);
    char letra;
    scanf(" %c", &letra);
    
    printf("%d", contar_letra(frase, strlen(frase), letra, 0));
}