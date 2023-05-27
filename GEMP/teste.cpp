#include <iostream>
#include <vector>
#include <algorithm>


//TODO - Aula da OBI explicando funções e métidos do Vector

using namespace std;

vector<int> joao;

void f(vector<int> *x){
    for(int i = 0; i < x->size(); ++ i) {
        cout << x->at(i) << endl;
    }
}

int main(){
    joao.assign(10, 0);

    for(int i = 0; i < (int)joao.size(); ++i){
      cin >> joao.at(i);
    }

    sort(joao.rbegin(), joao.rend());

    f(&joao);

    joao.erase(joao.begin() + 5);

    for(int i = 0; i < (int)joao.size(); ++i){
      cout << joao[i] << " ";
    }

}