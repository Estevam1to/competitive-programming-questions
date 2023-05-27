#include <bits/stdc++.h>

using namespace std;

int main(){
    set<int> ferr;
    for(int i = 0; i < 4; ++i){
        int a; cin >> a;
        ferr.insert(a);
    }

    cout << 4 - ferr.size() << "\n";
}