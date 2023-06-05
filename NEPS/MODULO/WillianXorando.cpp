#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n, m, k;
vi nums;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while (cin >> n >> m >> k && n != 0) {
        nums.assign(n, 0);

        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << nums[((--k - m) % n + n) % n] << endl;
    }

    return 0;
}
