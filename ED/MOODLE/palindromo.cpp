#include <iostream>
#include <algorithm>

using namespace std;

int palindromo(string x, string y, int size) {
    if(size == 0 ) 
        return x[size];
    
    if(x[size] != y[size])
        return 0;
    
    return palindromo(x, y, size-1);
}

int main(){
    string str1, str2;
    cin >> str1;

    str2 = str1;

    reverse(str2.begin(), str2.end());

    bool ans = palindromo(str1, str2, str1.size()- 1);

    if(ans)     
        cout << "sim\n ";
    else  
        cout << "nao\n";

    return 0;

}