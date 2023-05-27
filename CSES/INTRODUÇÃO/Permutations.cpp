#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<i64> vl;
typedef vector<ii> vii;

#define fi first
#define se second
#define MOD 1000000007

const char nl = '\n';


int main() {
    int n; cin >> n;

    if(n == 2 || n == 3){
        cout << "NO SOLUTION\n";
        return 0;
    }
    
    vi numbers;
    for(int i {1}; i <= n; ++i){
        numbers.push_back(i);
    }
    
    vi par, impar;
    for (auto i : numbers){
        if(i % 2 == 0 ){
            par.push_back(i);
        }else{
            impar.push_back(i);
        }
    }

    vi ans;
    for(auto i : par){
        ans.push_back(i);
    }

    for(auto i : impar){
        ans.push_back(i);
    }

    
    for(auto i : ans){
        cout << i << " ";
    }

    cout << nl;
    
}