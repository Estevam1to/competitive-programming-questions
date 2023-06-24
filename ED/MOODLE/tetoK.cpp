#include <stdio.h>

int teto(int vet[], int ini, int fim, int k) {
    if (ini > fim ) return -1;
    
    if (vet[ini] >= k) return vet[ini];

    int meio = (ini + fim)/2;

    if (vet[meio] == k) return vet[meio];

    else if (vet[meio] < k) return teto(vet, meio + 1, fim, k); 

    return teto(vet, ini, meio, k);
}

int main() {
    int n;
    scanf("%d", &n);
    int vet[n];

    for (int i = 0; i < n; ++i) {
        scanf("%d", &vet[i]);
    }

    int k;
    scanf("%d", &k);

    int t = teto(vet, 0, n - 1, k);
    if (t != -1) {
        printf("TETO ENCONTRADO: %d\n", t);
    } else {
        printf("NAO HA TETO PARA %d\n", k);
    }
    return 0;
    
}
