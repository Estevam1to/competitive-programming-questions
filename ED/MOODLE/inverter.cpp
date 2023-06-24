#include <iostream>
#include <algorithm>

using namespace std;

int inverter(int vet[ ], int ini, int fim) {
    if(ini >= fim){
        return 0;
    }

    swap(vet[ini], vet[fim]);
    
    return inverter(vet, ini + 1, fim - 1);   
}

int main(){
   int n; cin >> n;
   int vet[n];

   for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    inverter(vet, 0, n-1);

    for (int i = 0; i < n; i++) 
        cout << vet[i] << " \n"[i == n -1];

    return 0;
}