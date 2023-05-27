#include <iostream>

using namespace std;

void read(int vet[], int n);

void intercala( int vet[], int ini, int mid1, int mid2, int fim);

void merge_sort3(int vet[], int ini, int fim);

void print(int vet[], int n);

int main(){
    int n; cin >> n;
    int *v = new int[n];

    read(v, n);

    merge_sort3(v, 0, n -1);

    print(v, n);

    delete[] v;
    return 0;
}

void read(int vet[], int n){
    for(int i = 0; i < n; ++i){
        cin >> vet[i];
    }
}

void intercala( int vet[], int ini, int mid1, int mid2, int fim){
    int i = ini;
    int j = mid1 + 1;
    int z = mid2 + 1;
    int count = 0;
    int *aux = new int[fim - ini + 1];

    while (i <= mid1 && j <= mid2 && z <= fim) {
        if (vet[i] <= vet[j] && vet[i] <= vet[z]) aux[count++] = vet[i++];
        else if (vet[j] <= vet[i] && vet[j] <= vet[z]) aux[count++] = vet[j++];
        else aux[count++] = vet[z++];
    }

    while (i <= mid1 && j <= mid2){
       if(vet[i] <= vet[j]) aux[count++] = vet[i++];
       else aux[count++] = vet[j++];
    }

    while (i <= mid1 && z <= fim){
       if(vet[i] <= vet[z]) aux[count++] = vet[i++];
       else aux[count++] = vet[z++];
    }

    while (j <= mid2 && z <= fim){
       if(vet[j] <= vet[z]) aux[count++] = vet[j++];
       else aux[count++] = vet[z++];
    }
    
    while (i <= mid1) 
        aux [ count++ ] = vet [i++];
    while (j <= mid2) 
        aux [ count++ ] = vet [j++];
    while(z <= fim) 
        aux [ count++ ] = vet [z++];

    for(int i = ini; i <= fim; ++i)
        vet[i] = aux[i - ini];
    
    delete[] aux;    
}

void merge_sort3(int vet[], int ini, int fim){
    if(ini < fim){
        int mid1 = ini + ((fim - ini) / 3);
        int mid2 = ini + 2 * ((fim - ini) / 3) + 1;

        merge_sort3(vet, ini, mid1); 
        merge_sort3(vet, mid1 + 1, mid2);
        merge_sort3(vet, mid2 + 1, fim);

        intercala(vet, ini, mid1, mid2, fim);
    }
}

void print(int vet[], int n){
    for(int i = 0; i < n; ++i){
        cout << vet[i] << " \n"[i == n - 1];
    }
}
