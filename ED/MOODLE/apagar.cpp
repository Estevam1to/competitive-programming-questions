#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

//função para leitura dos vetores
void read(vi &vet, int tam){
    for (int i = 0; i < tam; ++i){
        int a; cin >> a;
        vet.push_back(a);
    }
}

//procurar e retornar a posição de cada elemento no vetor
//se o elemento está no vet retorna a posição, se não retorna -1
int search_position(vi &fila, int element){
    vi::iterator it = find(fila.begin(), fila.end(), element);
  
    if (it != fila.end()){
        return distance(fila.begin(), it);
    }
    
    return -1;
}

//resolve o principal da questão, procura um elemento e depois apaga ele do vetor principal
void solver(vi &fila, vi fila_saida){
    for (int i = 0; i < fila_saida.size(); ++i){
        int pos = search_position(fila, fila_saida[i]);
        if (pos != -1){
            fila.erase(fila.begin() + pos);
        }
    }
}

void print(vi vet){
    for (int i = 0; i < vet.size(); ++i){
        cout << vet[i] << " ";
    }
    cout << endl;
}

int main(){
    int n; cin >> n;
    vi fila;

    read(fila, n);

    int m; cin >> m;
    vi fila_saida;

    read(fila_saida, m);

    solver(fila, fila_saida);

    print(fila);
}