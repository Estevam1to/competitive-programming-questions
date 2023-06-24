#include <stdio.h>
#include <stdbool.h>

bool existe_soma(int vet[], int ini, int fim, int x) {
    if (ini >= fim) {
        return false;
    }
    int rest = x - vet[ini];
    printf("%d\n", rest);
    int meio = (ini + fim) / 2;
    if (vet[meio] == rest) {
        return true;
    }
    if (vet[meio] < rest) {
        return existe_soma(vet, meio + 1, fim, x);
    }
    return existe_soma(vet, ini, meio - 1, x);
}

int main() {
    int n, x;
    scanf("%d", &n);
    int vetor[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
    scanf("%d", &x);
    if (existe_soma(vetor, 0, n - 1, x)) {
        printf("SIM");
    } else {
        printf("NAO");
    }
    return 0;
}
