#include <bits/stdc++.h>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

vii gr;
vb visited;
vi team;
int n, m, ans1, ans2;

void dfs(int u, int t ){

    visited[u] = true;
    team[u] = t;

    for(int to : gr[u]){
        if(!visited[to]){
            dfs(to, t == 0 ? 1 : 0 );
        }
    }
}



int main(){
    cin >> n >> m;
    gr.assign(n + 1, vi());
    visited.assign(n + 1, false);
    team.assign(n + 1, 0);

    for(int i {1}; i <= m; ++i){
        int a, b; cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    for(int i {1}; i <= n; ++i){
        if(!visited[i]){
            dfs(i, 0);
        }
    }

    for(int i : team){
        ans1 += (i == 0);
        ans2 += (i == 1);
    }

    if(ans1 == ans2) cout << "0\n";

}