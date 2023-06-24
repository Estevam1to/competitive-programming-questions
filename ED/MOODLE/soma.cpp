#include <stdio.h>
#include <string.h>


int soma_digito(int numero){
    return  numero <= 9 ? numero :  numero % 10 + soma_digito(numero / 10);
}


int main(){
    int numero;
    scanf("%d", &numero);
    printf("%d", soma_digito(numero));
}