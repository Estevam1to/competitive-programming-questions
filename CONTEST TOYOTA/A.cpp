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

unordered_map<char, int> cont;
int n;
string s;

int main() {
    IOS;
    cin >> n >> s;

    for(int i { }; i < (int) s.size(); ++i){
        cont[s[i]]++;
    }

   if(cont['o'] > 0 && cont['x'] == 0){
        cout << "Yes\n";
   }else{
        cout<< "No\n";
   }
}