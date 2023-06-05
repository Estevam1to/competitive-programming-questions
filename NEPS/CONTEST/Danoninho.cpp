#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, x;
    cin >> n >> x;

    vector<int> cups(n);
    for (int i = 0; i < n; ++i){
        cin >> cups[i];
    }

    int p1{}, p2{}, sum{cups[0]}, ans{1};

    while (p1 < n && p2 < n){
        if (sum <= x) {
            if (++p2 < n) {
                sum += cups[p2];
            }
        } else {
            sum -= cups[p1++];
        }
        ans = max(ans, p2 - p1);
    }
    cout << ans << "\n";
}
    