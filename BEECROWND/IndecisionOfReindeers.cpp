#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    vector<string> reindeers = {"Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen", "Rudolph"};
    int sum { };
    for (int i { }, a { }; i < 9; ++i){
        cin >> a;
        sum += a;
    }
    cout << reindeers[(sum + 8) % 9] << "\n";
    return 0;
}