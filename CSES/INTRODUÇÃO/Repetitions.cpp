#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int max = 1, resp{};
    char aux = str[0];

    for (int i = 1; i <= (int)str.size(); ++i)
    {
        if (str[i] == aux)
        {
            ++max;
        }
        else if (resp < max)
        {
            resp = max;
            max = 1;
            aux = str[i];
        }
        else
        {
            max = 1;
            aux = str[i];
        }
    }

    cout << resp << endl;
}