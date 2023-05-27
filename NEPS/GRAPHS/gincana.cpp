#include "bits/stdc++.h"
using namespace std;

typedef int64_t i64;
typedef pair<int, int> pii;
typedef vector<char> vc;
typedef vector<vc> vcc;
typedef vector<bool> vb;
typedef vector<vb> vbb;
typedef vector<int> vi;
typedef vector<i64> vl;
typedef vector<vi> vii;
typedef vector<pii> vpii;

#define fi first
#define se second
#define MOD 1000000007
#define IOS cin.tie(0)->sync_with_stdio(0)
#define psb(v) push_back(v)
#define ppb() pop_back()
#define nl '\n'

int n, m;

vb visited;
vii gr;

void dfs(int u)
{
    visited[u] = true;

    for (int to : gr[u])
    {
        if (!visited[to])
        {
            dfs(to);
        }
    }
}

int main()
{
    IOS;

    cin >> n >> m;

    gr.assign(n + 1, vi());
    visited.assign(n + 1, 0);

    for (int i{1}; i <= m; ++i)
    {
        int a, b;
        cin >> a >> b;

        gr[a].psb(b);
        gr[b].psb(a);
    }

    int ans = 0;
    for (int i{1}; i <= n; ++i)
    {
        if (!visited[i])
        {
            ++ans;
            dfs(i);
        }
    }

    cout << ans << nl;
}