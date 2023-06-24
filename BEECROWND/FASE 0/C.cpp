#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int64_t n, k;

  cin >> n >> k;

  int64_t mod = 2 * n + 1;

  for (int64_t i = 2 * n; i >= 1; --i) {
    int64_t r = i * i;

    if (!((abs(r - k)) % mod) or !((abs(k - r)) % mod)) {
      cout << r << endl;
      return 0;
    }
  }

  cout << 3 << endl;
}
