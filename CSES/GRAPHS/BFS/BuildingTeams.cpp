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

/*
AUTHOR: LUÍS ESTEVAM ROSA CHAVES
PROBLEM: https://cses.fi/problemset/task/1668/
*/ 

int n, m;

queue<int> q;
vb visited;
vii gr;
vi team;
bool impossible;

void bfs(int s, int t) {
    visited[s] = true; 
    team[s] = t; 
    q.push(s); 

    while(!q.empty()) {
        int u = q.front(); 
        q.pop(); 
        for(int to : gr[u]){ 
            if(!visited[to]){ 
                t = (team[u] == 1 ? 2 : 1); 
                team[to] = t; 
                visited[to] = true; 
                q.push(to); 
            }
            if(team[to] == team[u]){
                impossible = true; 
            }
        }
    }
}

int main() {
    IOS;

    cin >> n >> m;

    gr.assign(n + 1, vi());
    visited.assign(n + 1, false);
    team.assign(n + 1, 0);

    for (int i{1}; i <= m; ++i) {
        int a, b;
        cin >> a >> b;

        gr[a].psb(b);
        gr[b].psb(a);
    }

    for (int i{1}; i <= n; ++i) {
        if (!visited[i]) {
            bfs(i, 1);
        }
    }

    for (int i = 1; i < (int)team.size(); ++i) {
        if (impossible) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        cout << team[i] << " ";
    }

    cout << nl;
}