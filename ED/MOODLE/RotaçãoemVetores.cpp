#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

//função de leitura dos valores do vector
void read(vi &vet, int tam) {
  for (int i{}; i < tam; ++i) {
    int a;
    cin >> a;
    vet.push_back(a);
  }
}

//rotaciona o vetor
void rotate(vi &vet, int qtd) {
   
}

//função de imprimir os valores 
void print(vi vet) {
  cout << "[ ";
  for (int i{}; i < vet.size(); ++i) {
    cout << vet[i] << " ";
  }
  cout << "]" << endl;
}

int main() {
  int n, elemts;
  cin >> n >> elemts;
  vi nums;

  read(nums, n);

  print(nums);
}