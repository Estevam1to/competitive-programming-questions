#include <bits/stdc++.h>


using namespace std;

int main()  {
    long long int x; 
    
    cin >> x;
    while (x != 1){
        cout << x << " ";
        if(x % 2 == 0){
            x /= 2 ;
        }else{
            x = (x * 3) + 1;
        }
    }
    cout << x << endl;
    return 0;
}