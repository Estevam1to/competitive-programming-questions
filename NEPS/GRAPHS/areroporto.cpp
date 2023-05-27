#include "bits/stdc++.h"
using namespace std;

typedef int64_t i64;
typedef pair<int, int> pii;
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

int a, v, idx; 

int main() {
    IOS;
    idx = 1;
    while (cin >> a >> v){
        
        if( a == 0 || v == 0){
            return 0;
        }

        map<int, int> qtd;
        int maior = 0;
        for(int i { }; i < v; ++i){
            int x, y; cin >> x >> y;

            qtd[x]++;
            qtd[y]++;     

            if(maior < qtd[x]){
                maior = qtd[x];
            }
            if(maior < qtd[y]){
                maior = qtd[y];
            }      
        }

        cout << "Teste " << idx << "\n"; 
        int cont = 0;
        for(auto it = qtd.begin(); it != qtd.end(); ++it){
            if(it->se == maior){
                cout << (cont > 0 ? " ": "") << it->first;
                cont++;
            }
        }  
        cout << "\n" << "\n";
        idx++;
    }
    
}