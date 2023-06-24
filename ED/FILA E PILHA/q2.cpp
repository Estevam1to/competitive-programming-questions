#include "queue.cpp"
#include "stack.cpp"
#include <iostream>

using namespace std;

void print(int vet[], int n){
  for (int i{}; i < n; ++ i){
    cout << vet[i] << " ";
  }
  cout << endl;
}

void positivos_negativos(int vet[], int n) {
  Queue<int> negativos;
  Stack<int> positivos;

  for (int i = 0; i < n; ++i) {
    if (vet[i] < 0) {
      negativos.push(vet[i]);
    } else {
      positivos.push(vet[i]);
    }
  }

  int i = 0;
  while (!negativos.empty()) {
    vet[i++] = negativos.pop();
  }

  while (!positivos.empty()) {
    vet[i++] = positivos.top();
    positivos.pop();
  }
}

int main() {
  int n;
  cin >> n;
  int vet[n];
  for (int i{}; i < n; ++i) {
    cin >> vet[i];
  }
  positivos_negativos(vet, n);

  print(vet, n);
}