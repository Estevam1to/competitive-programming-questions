#include "stack.cpp"
#include <iostream>

using namespace std;

int main() {
  string frase;
  getline(cin, frase);

  Stack<char> inverte;
  string ans = "";
  for (int i{}; i < (int)frase.size(); ++i) {
    if (frase[i] != ' ') {
      inverte.push(frase[i]);
    } else {
      while (!inverte.empty()) {
        ans += inverte.top();
        inverte.pop();
      }
      ans += " ";
    }
  }

  while (!inverte.empty()) {
    ans += inverte.top();
    inverte.pop();
  }

  cout << ans << endl;
}