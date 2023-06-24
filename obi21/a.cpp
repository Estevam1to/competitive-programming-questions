#include <bits/stdc++.h>
using namespace std;

vector<int> ans(4);

int main() {
  string cards;
  cin >> cards;
  vector<vector<bool>> baralho(4, vector<bool>(13, 0));

  for (int i = 0; i < (cards.size() / 3); i += 3) {
    int num = (cards[i] - '0') * 10 + cards[i + 1] - '0';
    int naipe = cards[i + 2];

    if (naipe == 'N') {
      if (baralho[0][num - 1]) {
        ans[0] = -1;
      } else {
        ans[0] = 1;
      }
    } else if (naipe == 'C') {
      if (baralho[1][num - 1]) {
        ans[1] = -1;
      } else {
        ++ans[1];
      }
    } else if (naipe == 'E') {
      if (baralho[2][num - 1]) {
        ans[2] = -1;
      } else {
        ++ans[2];
      }
    } else if (naipe == 'U') {
      if (baralho[3][num - 1]) {
        ans[3] = -1;
      } else {
        ++ans[3];
      }
    } else if (naipe == 'P') {
      if (baralho[4][num - 1]) {
        ans[4] = -1;
      } else {
        ++ans[4];
      }
    }
  }
  for (int i = 0; i < 4; ++i) {
    if (ans[i] == -1)
      cout << "error\n";
    else
      cout << ans[i] << "\n";
  }
}