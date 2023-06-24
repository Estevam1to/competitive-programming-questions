#include <iostream>

using namespace std;

int main(){
    int x = 10;

    // deloquei um bit a esquerda
    // y = 10  * 2
    int y = (x << 1);

    // deloquei um bit a direita
    // y = 10/2
    int z = (x >> 1);

    int k = x & 3;

    cout << y << endl;
    cout << z << endl;
    cout << k << endl;
}