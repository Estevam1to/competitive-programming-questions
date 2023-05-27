#include "bits/stdc++.h"
using namespace std;

typedef int64_t i64;
typedef pair<int, int> pii;
typedef vector<char> vc;
typedef vector<vc> vcc;
typedef vector<bool> vb;
typedef vector<vb> vbb;
typedef vector<int> vi;
typedef vector<i64> vl;
typedef vector<vi> vii;
typedef vector<pii> vpii;

#define fi first
#define se second
#define MOD 1000000007
#define IOS cin.tie(0)->sync_with_stdio(0)
#define psb(v) push_back(v)
#define ppb() pop_back()
#define nl '\n'

int n;
vii a, b;


void rotate(vii &x){
    for(int i { }; i < n/2; ++i){
        for(int j{ }; j < n-i-1; ++j){
            int tmp = x[i][j];
            x[i][j] = x[n-1-j][i];
            x[n-1-j][i] = x[n-1-i][n-1-j];
            x[n-1-i][n-1-j] = x[j][n-1-i];
            x[j][n-1-i] = tmp;
        }
    }
}

bool compare(vii x, vii y){
    for(int i { }; i < n; ++i){
        for(int j{ }; j < n; ++j){
            if(x[i][j] != y[i][j]){
                return false;
            }
        }
    }   
    return true;
}


int main() {
    IOS;

    cin >> n;
    a.assign(n, vi(n, 0)); 
    b.assign(n, vi(n, 0)); 

    for(int i { }; i < n; ++i){
        for(int j { }; j < n; ++j){
            cin >> a[i][j];
        }
    }

    for(int i { }; i < n; ++i){
        for(int j { }; j < n; ++j){
            cin >> b[i][j];
        }
    }

    for(int i { }; i < n ; ++i){
        for(int j { }; j < n ; ++j){
            if(a[i][j] == 1 && b[i][j] == 0){
                break;
            }else if((a[i][j] == 1 && b[i][j] == 1)){
                rotate(a);
                rotate(a);
                rotate(a);
            }
        }
    }

    if(compare(a, b)){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }

   
}