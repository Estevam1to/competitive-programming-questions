#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi nums;
vi erros;
int n;
int main(){
  cin >> n;
  nums.assign(0, n);
  erros.assign(0, n);

  for (int i{}; i < n; ++ i){
    int a;
    cin >> a;
    nums.push_back(a);
  }

  for (int i{}; i < n; ++i) {
    int a;
    cin >> a;
    erros.push_back(a);
  }
  
}
