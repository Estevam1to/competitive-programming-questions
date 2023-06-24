#include <stdio.h>

int is_sorted(int vet[], int ini, int fim) {
    if (ini >= fim) {
        return 1;
    } else if (vet[ini] > vet[ini + 1]) {
        return 0;
    }
    return is_sorted(vet, ini + 1, fim);
}

int main() {
    int n;
    scanf("%d", &n);
    int vet[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vet[i]);
    }

    if (is_sorted(vet, 0, n - 1)) {
        printf("ORDENADO\n");
        return 0;
    }
    printf("NAO ORDENADO\n");
    return 0;
}