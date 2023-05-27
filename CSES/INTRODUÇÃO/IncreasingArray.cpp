#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<i64> vl;
typedef vector<ii> vii;

#define fi first
#define se second
#define MOD 1000000007

const char nl = '\n';

i64 cont(vl &vet)
{
    i64 count{};
    for (auto i = 1; i < (int)vet.size(); i++)
    {
        if (vet[i] < vet[i - 1])
        {
            count += vet[i - 1] - vet[i];
            vet[i] = vet[i - 1];
        }
    }
    return count;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vl num;
    for (auto i{0}; i < n; ++i)
    {
        i64 a;
        cin >> a;
        num.push_back(a);
    }

    cout << cont(num) << nl;
}
