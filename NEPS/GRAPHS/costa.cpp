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

vcc mapa;
int m, n, ans; 



int main() {
    IOS;
    cin >> m >> n;

    vcc mapa(m+2, vc(n+2, '.'));
    

    for(int i {1}; i <= m; i++){
        for(int j {1}; j <= n; ++j){
            cin >> mapa[i][j];
        }
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (mapa[i][j] == '#' && (mapa[i-1][j] == '.' || mapa[i+1][j] == '.' || mapa[i][j-1] == '.' || mapa[i][j+1] == '.')) {
                ans++;
            }
        }
    }

    cout << ans <<"\n";    
}