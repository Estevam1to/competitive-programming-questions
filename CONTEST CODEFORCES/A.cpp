#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vi vet1(n), vet2(n);
    for (int i = 0; i < n; ++i) {
      cin >> vet1[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> vet2[i];
    }

    int maxVet1 = *max_element(vet1.begin(), vet1.end());
    int maxVet2 = *max_element(vet2.begin(), vet2.end());

    if (maxVet1 != n - 1 && maxVet2 != n - 1) {
      cout << "No\n";
      continue;
    }

    bool yes = (vet1 == vet2 ? true : false);

    if (yes) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
