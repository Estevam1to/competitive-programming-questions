#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    unordered_set<int> numbers;
    for (int i = 0; i < n-1; ++i){
        int a; cin >> a;
        numbers.insert(a);
    }
    
    unordered_set<int> copy;
    for (int i = 1; i <= n; ++i) {
        copy.insert(i);
    }   


    for(auto i : copy){
       if(numbers.find(i) == numbers.end()){
            cout << i << "\n";
            return 0;
       }
    }

}