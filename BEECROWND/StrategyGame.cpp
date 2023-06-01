#include <bits/stdc++.h>
 
using namespace std;

typedef vector<int> vi;
typedef unordered_map<int, int> ump;

int n, m; 
vi vet;
ump sum;
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    vet.assign(0, n * m);

    for (int i { }, a { }; i < n * m; ++i) {
        cin >> a;
        vet.push_back(a);
    }

    for (int i { }; i < (int) vet.size(); ++i) {
        sum[i % n] += vet[i];
    }

    int max = sum[0], ans { };
    for (int i {1}; i < (int) sum.size(); ++i) {
        if(max <= sum[i]){
            max = sum[i];
            ans = i;
        }
    }

    cout << ans + 1 << "\n";
}