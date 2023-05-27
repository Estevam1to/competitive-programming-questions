#include <bits/stdc++.h>

using namespace std;


int n;

int main(){
    int count = 0, qtd = 0, ans = 0;
    cin >> n;


    for(int i = 0; i < 3 * n; ++i){
        int a; cin >> a;

        if(count == 3){
            count = 0;
            qtd = 0;
        }

        if(count < 3){
            qtd += (a == 1);
            qtd > 1 && a == 1 && qtd != 3 ? ++ans : 0;
            ++count;
        }

    }

    cout << ans << "\n";

}